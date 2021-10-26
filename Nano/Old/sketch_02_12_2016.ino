#include <SoftwareSerial.h>
#include <EEPROM.h>

SoftwareSerial mySerial(8, 9); //На этих пинах подключен модем RX, TX
#define RLed 10 // Красный светодиод
#define BLed 11 // Синий светодиод
#define GLed 12 // Зеленый светодиод
#define AlarmPin 4 // Выход "тревожного" пина, при срабатывании датчика на этом пине устанавливается сигнал высокого уровня на время указанное в переменной AlarmInterval, по умолчанию 60 секунд.
#define InverseAlarmPin 5 // Инверсный выход "тревожного" пина, при срабатывании датчика на этом пине устанавливается сигнал низкого уровня на время указанное в переменной AlarmInterval, по умолчанию 60 секунд.
#define DoorPin 6 // Номер входа, подключенный к датчику
int8_t DoorState = 0; // Переменная для хранения состояния датчика
int8_t DoorFlag = 1;

int8_t RLedState = LOW;
int8_t GLedState = LOW;
int8_t BLedState = LOW;


unsigned long previousAlarmMillis = 0;
uint16_t AlarmInterval = 60; // Секунд до отключения "тревожного" пина.

unsigned long previousMillis = 0;
uint16_t interval = 100;

uint8_t PauseTime = 15; // Время, указывается в минутах, на которое сигнализация должна засыпать при получении смс команды Pause.

uint8_t ch = 0;
int8_t sendsms = 1; //Отправка смс: 1 - включена, 0 - выключена. Глобальный параметр отправки сообщений. Управляется через смс командами SmsOn и SmsOff.
int8_t AlarmRing = 1; //Звонок: 1 - включен, 0 - выключен. Звонить на первый номер массива AlarmPhone при срабатывании датчика. Управляется через смс командами RingOn и RingOff.
int8_t guard = 1; //Охрана: 1 - включена, 0 - выключена. Если включена, будут отправляться смс при срабатывании датчиков
int8_t sendsmscaller; //Переменная для отправки смс о снятии или установки на охрану пользователям которые отсутствуют в массиве AlarmPhone
int8_t LedTestOn = 0;
int8_t LedOn = 1;

String BalanceNumber = "#100#"; //Команда запроса баланса. #100# - ответ латинскими буквами, *100# - ответ русскими буквами. Работает только с латинскими буквами. В данном случае команда запроса баланса Beeline(Россия).
uint8_t BalanceStringLen = 22; //Число символов от начала строки которые нужно переслать в смс сообщении при получении USSD ответа о балансе. Убираем спам от оператора при запросе баланса, особо критично для модема M590, обрезаем всё лишнее.

String val = "";
String RingPhone = "";
String LastEvent = "System -> guard ";

int8_t ModemID = 0;

const char* AllowPhone[] = {"70001234501", "70001234502", "70001234503", "70001234504", "70001234505"}; //Номера которым разрешено управлять охраной. На первый номер будут отправляться смс монитора порта (для отладки)
int8_t CountPhone = sizeof(AllowPhone) / sizeof(AllowPhone[0]);

const char* AlarmPhone[] = {"70001234501", "70001234502"}; //Номера для отправки смс при срабатывании датчиков и о снятии или установки на охрану. На первый номер будет осуществляться вызов если AlarmRing = 1;
int8_t CountAlarmPhone = sizeof(AlarmPhone) / sizeof(AlarmPhone[0]);


/*
  EEPROM Data:
  № ячейки - значение;
  0 - если записана не 1, то необходимо затереть часть памяти eeprom'a и восстановить стандартную конфигурацию.
  10 - sendsms = 1; //Отправка смс: 1 - включена, 0 - выключена. Глобальный параметр отправки сообщений. Управляется через смс командами SmsOn и SmsOff.
  11 - AlarmRing = 1; //Звонок: 1 - включен, 0 - выключен. Звонить на первый номер массива AlarmPhone при срабатывании датчика. Управляется через смс командами RingOn и RingOff.
  12 - LedTestOn = 0;
  13 - LedOn = 1;
  14 - guard =1; //Охрана: 1 - включена, 0 - выключена. Если включена, будут отправляться смс при срабатывании датчиков
*/
void setup() {

  Serial.begin(9600);

  //EEPROM.update(0, 255); //reset config;
  eepromconfig();

  pinMode(RLed, OUTPUT);
  pinMode(GLed, OUTPUT);
  pinMode(BLed, OUTPUT);
  digitalWrite(RLed, HIGH);
  digitalWrite(GLed, HIGH);
  digitalWrite(BLed, HIGH);

  digitalWrite(RLed, LOW);
  delay(500);
  digitalWrite(RLed, HIGH);
  digitalWrite(GLed, LOW);
  delay(500);
  digitalWrite(GLed, HIGH);
  digitalWrite(BLed, LOW);
  delay(500);
  digitalWrite(BLed, HIGH);

  pinMode(DoorPin, INPUT);

  pinMode(AlarmPin, OUTPUT);
  digitalWrite(AlarmPin, LOW);
  pinMode(InverseAlarmPin, OUTPUT);
  digitalWrite(InverseAlarmPin, HIGH);

  InitModem();
}

void loop() {
  if (LedTestOn == 0) digitalWrite(BLed, HIGH);
  if (LedTestOn == 1) LedTest();
  Led();
  AlarmPinOff();
  Detect();
  if (mySerial.available()) {
    while (mySerial.available()) { 
      ch = mySerial.read();
      val += char(ch);
      delay(20);
    }
    if (val.indexOf("+PBREADY") > -1) InitModem();
    if (val.indexOf("RING") > -1) { 
      if (CheckPhone() == 1) {
        mySerial.println("ATH0");
        sendsmscaller = 1;

        MasterRing();
      } else {

        mySerial.println("ATH0"); 
      }
    } else if (val.indexOf("+CMT:") > -1) {  
      if (CheckPhone() == 1) {
        sendsmscaller = 1;
        MasterSms();
      }
    } else if (val.indexOf("+CUSD:") > -1) { 

      Serial.println(RingPhone);
      Serial.println(val);
      if (val.indexOf("\"") > -1) {
        sms(String(val.substring(String(val.indexOf("\"")).toInt() + 1, String(val.indexOf("\"")).toInt() + BalanceStringLen)), String("+" + RingPhone));
        delay(1000);
      }
      mySerial.println("AT+CUSD=0");
      delay(200);
    } else
      Serial.println(val); 
    val = "";
  }
  if (Serial.available()) { 
    while (Serial.available()) { 
      ch = Serial.read();
      val += char(ch);
      delay(20);
    }
    mySerial.println(val);
    ConsolePrint();
    val = "";  
  }
}

void eepromconfig() {
  pinMode(13, OUTPUT);
  if (EEPROM.read(0) != 1) {
    for (int i = 0 ; i < 20 ; i++) {
      EEPROM.update(i, 255);
      delay(10);
    }
    EEPROM.update(10, 1);  // sendsms = 1; //Отправка смс: 1 - включена, 0 - выключена. Глобальный параметр отправки сообщений. Управляется через смс командами SmsOn и SmsOff.
    EEPROM.update(11, 1);  // AlarmRing = 1; //Звонок: 1 - включен, 0 - выключен. Звонить на первый номер массива AlarmPhone при срабатывании датчика. Управляется через смс командами RingOn и RingOff.
    EEPROM.update(12, 0);  // LedTestOn = 0;
    EEPROM.update(13, 1);  // LedOn = 1;
    EEPROM.update(14, 1); //Охрана: 1 - включена, 0 - выключена. Если включена, будут отправляться смс при срабатывании датчиков
    EEPROM.update(0, 1);
    digitalWrite(13, HIGH);
  }
  if (EEPROM.read(0) == 1) {
    sendsms = EEPROM.read(10);  // sendsms = 1; //Отправка смс: 1 - включена, 0 - выключена. Глобальный параметр отправки сообщений. Управляется через смс командами SmsOn и SmsOff.
    AlarmRing = EEPROM.read(11);  // AlarmRing = 1; //Звонок: 1 - включен, 0 - выключен. Звонить на первый номер массива AlarmPhone при срабатывании датчика. Управляется через смс командами RingOn и RingOff.
    LedTestOn = EEPROM.read(12);  // LedTestOn = 0;
    LedOn = EEPROM.read(13);  // LedOn = 1;
    guard = EEPROM.read(14); //Охрана: 1 - включена, 0 - выключена. Если включена, будут отправляться смс при срабатывании датчиков
    if (guard == 1) LastEvent = LastEvent + "on";
    if (guard == 0) LastEvent = LastEvent + "off";
  }
}

void InitModem() {
  delay(2000);
  Serial.begin(9600); 
  mySerial.begin(9600);
  mySerial.println("AT");
  delay(100);
  mySerial.println("ATI");
  delay(100);
  if (mySerial.find("M590")) ModemID = 1;
  mySerial.println("ATI");
  delay(100);
  if (mySerial.find("SIM800")) ModemID = 2;
  delay(100);
  mySerial.println("AT+CLIP=1");
  delay(100);
  mySerial.println("AT+CMGF=1"); 
  delay(100);
  mySerial.println("AT+CSCS=\"GSM\"");
  delay(100);
  mySerial.println("AT+CNMI=2,2");
  delay(100);
}

int CheckPhone() {
  for (int i = 0; i < CountPhone; i++) {
    if (val.indexOf(AllowPhone[i]) > -1) {
      RingPhone = AllowPhone[i];
      Serial.println("Event: +" + RingPhone);
      return 1;
    }
  }
  return 0;
}

void Detect() {
  DoorState = digitalRead(DoorPin);
  if (DoorState == LOW && DoorFlag == 0) {
    DoorFlag = 1;
    delay(100);
    if (LedOn == 1) digitalWrite(GLed, LOW);
    Alarm();
  }
  if (DoorState == HIGH && DoorFlag == 1) {
    DoorFlag = 0;
    delay(100);
  }
}

void Led() {
  if (guard == 1) {
    digitalWrite(GLed, HIGH);
    digitalWrite(RLed, LOW);
  }
  if (guard == 0) {
    digitalWrite(RLed, HIGH);
    if (LedOn == 1) digitalWrite(GLed, LOW);
  }
}

void LedTest() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
    if (RLedState == LOW)
      RLedState = HIGH;
    else
      RLedState = LOW;
    digitalWrite(BLed, RLedState);
  }
}

void AlarmPinOff() {
  unsigned long currentAlarmMillis = millis();
  if (currentAlarmMillis - previousAlarmMillis > AlarmInterval * 1000) {
    digitalWrite(AlarmPin, LOW);
    digitalWrite(InverseAlarmPin, HIGH);
  }
}

void Alarm() {
  if (guard == 1) {
    digitalWrite(AlarmPin, HIGH);
    digitalWrite(InverseAlarmPin, LOW);
    previousAlarmMillis = millis();
    for (int i = 0; i < CountAlarmPhone; i++) {
      sms(String("Srabotal datchik dveri!"), String("+" + String(AlarmPhone[i])));
      delay(1000);
    }
    if (AlarmRing == 1) {
      mySerial.println("ATD+" + String(AlarmPhone[0]) + ";");
      delay(1000);
    }
  }
}

void MasterRing() {
  if (guard == 1) GuardOff();
  else if (guard == 0) GuardOn();
}

void GuardOff() {
  guard = 0;
  EEPROM.update(14, guard);
  LastEvent = "Guard Off. Phone +" + RingPhone;
  Serial.println(LastEvent);
  delay(1000);
  for (int i = 0; i < CountAlarmPhone; i++) {
    if (RingPhone == String(AlarmPhone[i])) sendsmscaller = 0;
    delay(1000);
    sms(String(LastEvent), String("+" + String(AlarmPhone[i])));
    delay(1000);
  }
  if (sendsmscaller == 1) {
    delay(1000);
    sms(String("Guard Off"), String("+" + RingPhone));
    delay(1000);
  }
}

void GuardOn() {
  guard = 1;
  EEPROM.update(14, guard);
  DoorFlag = 1;
  LastEvent = "Guard On. Phone +" + RingPhone;
  Serial.println(LastEvent);
  delay(1000);
  for (int i = 0; i < CountAlarmPhone; i++) {
    if (RingPhone == String(AlarmPhone[i])) sendsmscaller = 0;
    delay(1000);
    sms(String(LastEvent), String("+" + String(AlarmPhone[i])));
    delay(1000);
  }
  if (sendsmscaller == 1) {
    delay(1000);
    sms(String("Guard On"), String("+" + RingPhone));
    delay(1000);
  }
}

void MasterSms() {
  val.toLowerCase();
  if ((val.indexOf("resetconfig") > -1)) {
    EEPROM.update(0, 255);
    eepromconfig();
  }
  if ((val.indexOf("money") > -1)) {
    delay(1000);
    balance();
    delay(1000);
  }
  if ((val.indexOf("pause") > -1)) {
    delay(1000);
    sms(String("Pause " + String(PauseTime) + " min"), String("+" + RingPhone));
    digitalWrite(BLed, LOW);
    delay(PauseTime * 60000);
    digitalWrite(BLed, HIGH);
  }
  if ((val.indexOf("ringon") > -1)) {
    delay(1000);
    AlarmRing = 1;
    EEPROM.update(11, AlarmRing);
    sms(String("RingOn: Alarm Ring is ON"), String("+" + RingPhone));
    delay(1000);
  }
  if ((val.indexOf("ringoff") > -1)) {
    delay(1000);
    AlarmRing = 0;
    EEPROM.update(11, AlarmRing);
    sms(String("RingOff: Alarm Ring is OFF"), String("+" + RingPhone));
    delay(1000);
  }
  if ((val.indexOf("smson") > -1)) {
    delay(1000);
    sendsms = 1;
    EEPROM.update(10, sendsms);
    sms(String("Sms On"), String("+" + RingPhone));
    delay(1000);
  }
  if ((val.indexOf("smsoff") > -1)) {
    delay(1000);
    sms(String("Sms Off"), String("+" + RingPhone));
    sendsms = 0;
    EEPROM.update(10, sendsms);
    delay(1000);
  }
  if ((val.indexOf("guardon") > -1)) {
    delay(1000);
    GuardOn();
  }
  if ((val.indexOf("guardoff") > -1)) {
    delay(1000);
    GuardOff();
  }
  if ((val.indexOf("info") > -1)) {
    delay(1000);
    sms(String("Info: " + LastEvent), String("+" + RingPhone));
    delay(1000);
  }
  if ((val.indexOf("clearsms") > -1)) {
    clearsms();
    delay(2000);
    sms(String("Clear: All messages removed"), String("+" + RingPhone));
    delay(1000);
  }
  if ((val.indexOf("teston") > -1)) {
    delay(1000);
    LedTestOn = 1;
    EEPROM.update(12, LedTestOn);
    delay(1000);
  }
  if ((val.indexOf("testoff") > -1)) {
    delay(1000);
    LedTestOn = 0;
    EEPROM.update(12, LedTestOn);
    digitalWrite(BLed, HIGH);
    delay(1000);
  }
  if ((val.indexOf("ledoff") > -1)) {
    delay(1000);
    LedOn = 0;
    EEPROM.update(13, LedOn);
    digitalWrite(GLed, HIGH);
    delay(1000);
  }
  if ((val.indexOf("ledon") > -1)) {
    delay(1000);
    LedOn = 1;
    EEPROM.update(13, LedOn);
    digitalWrite(GLed, LOW);
    delay(1000);
  }
  clearsms();
}

void ConsolePrint() {
  val.toLowerCase();
  if ((val.indexOf("clearsms") > -1)) {
    clearsms();
    delay(2000);
  }
  if ((val.indexOf("resetconfig") > -1)) {
    EEPROM.update(0, 255);
    eepromconfig();
  }
}

void balance() {
  mySerial.println("AT+CUSD=1");
  delay(200);
  mySerial.println("ATD" + BalanceNumber);
  delay(200);
}

void clearsms() {
  if (ModemID == 1) mySerial.println("AT+CMGD=0,4");
  if (ModemID == 2) mySerial.println("AT+CMGD=4");
}

void sms(String text, String phone) {
  if (sendsms == 1 ) {
    mySerial.println("AT+CMGS=\"" + phone + "\"");
    delay(500);
    mySerial.print(text);
    delay(500);
    mySerial.print((char)26);
    delay(500);
    Serial.println("SMS sended! Phone: " + phone + "; Message: " + text);
    delay(5000);
  } else {
    delay(1000);
    Serial.println("Silent mode, SMS not sended! Phone: " + phone + "; Message: " + text);
  }
}