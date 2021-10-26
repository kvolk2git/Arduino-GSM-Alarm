//Исправлен баг с тревожным пином. Теперь команды Info и Money всегда будут присылать ответное смс. Команда GuardButtonOn заменена командами GuardButtonOn1 и GuardButtonOn2.
//--------
//Теперь параметр sendsms не влияет на отправку смс сообщений мониторинга электросети.
//Добавлена смс команда DelayBeforeGuard отвечающая за задержку при постановке на охрану, значение не может превышать 255 секунд.
//Добавлена смс команда DelayBeforeAlarm отвечающая за задержку отправки уведомлений и включении "тревожного пина" при срабатывании датчиков, значение не может превышать 255 секунд.
//Удалены команды ClearSMS, теперь сообщения удаляются автоматически после получения.
//--------
//Теперь передача консольных команд в GSM модуль производится только если включен тестовый режим.
//Теперь нет разделения на смс команды и консольные команды, все существующие команды можно передавать через смс так и через консоль.
//--------
//Исправлен баг при котором команда ListConfig меняла значение последнего события.
//Теперь при вводе команд через косоль не отправляются ненужные смс сообщения.
//--------
//Исправлен баг с функцией DelayBeforeAlarm.
//-------- 17.05.23
//Незначительно изменён вывод информации в консоль.
//Добавлена поддержка модулей расширения портов на PCF8574A c адресами от 0x38 до 0x3f включительно.
//Исправлен баг c AlarmPinTime. https://mysku.ru/blog/ebay/44545.html#comment2064554
//Теперь устройство перезагружается автоматически после команд FullReset, ResetConfig, ResetPhone и в случае успешного выполнения команды MemTest.
//Добавлена команда WatchPowerTime. Теперь возможно установить время, по истечении которого будет отправлено смс сообщение об отключении внешнего источника питания. https://mysku.ru/blog/ebay/43282.html#comment2064788
//-------- GSM_2017_05_26-20-22.hex+
//Исправлена инициализация памяти датчиков платы расширения.
//Изменён синтаксис команды AddPhone.
//Добавлена команда EditMainPhone.
//Изменен принцип работы системы уведомлений, при срабатывании датчика сначала будут отправлены sms сообщения, после чего будут совершены голосовые вызовы.
//Тревожные sms сообщения будут отправлены на телефонные номера с признаком "S" (SMS).
//Голосовоые вызовы будут совершены на номера с признаком "R" (Ring).
//Сообщения об отключении/включении внешнего источника питания будут отправлены на телефонные номера с признаком "P" (Power).
//Добавлена команда RingTime. Теперь возможно установить длительность тревожного голосового вызова, параметр может иметь значение от 10 до 255 секунд.
//Теперь команда RingOn/RingOff глобально включает/отключает оповещение голосовыми вызовами.
//Добавлена команда ResetSensor.
//------- GSM_2017_06_02-17-43.hex
//Теперь после добавления основного номера устройство автоматически перезагружается.
//Теперь можно вносить в память устройства одинаковые номера. При добавлении второго и последующих дублирующихся номеров с них автоматически будут сняты атрибуты "M", "S" и "P". Эти номера будут использованы для повторного прозвона при срабатывании датчиков.
//Исправлен баг кривого вывода в консоль после выполнения команды AddPhone, теперь информация не выводится автоматически после добавления номера.
//Командам AddPhone и EditMainPhone добавлен параметр "I" (Info), отвечающий за sms уведомление о постановке или снятии устройства с охраны.
//Добавлена команда Reboot.
//------- GSM_2017_06_11-00-07.hex
//Теперь вновь при замыкании контактов основного герконового датчика (закрытии двери) устройство мигает синим светодиодом в течение 2 секунд, сигнализируя о нормальной работе датчика, при этом не учитывается поставлено или снято устройство с охраны.
//Команды RingOn/RingOff удалены.
//Теперь устройство можно снять с охраны во время тревожного вызова, теперь они осуществляются совершаются в фоновом режиме.
//------- GSM_2017_07_04-21-52
//https://mysku.ru/blog/ebay/43282.html#comment2102221
//https://mysku.ru/blog/ebay/43282.html#comment2103896
//Теперь команда Pause не присылает ответное смс. Удалены команды TestOn и TestOff. У всех номеров удалён признак Management.
//------- GSM_2017_07_24-12-02
//Добавлены команды ReedSwitchOn/ReedSwitchOff для мониторинга основного герконовго датчика, теперь его можно включать/отключать так же как и датчик движения.
//Исправлен баг команды Info.
//Команды TestOn и TestOff снова присутствуют в прошивке.
//------- GSM_2017_07_26-10-03.hex
//Добавлена команда ModemID. Автоматическое определение модема осуществляется только если знаечении этого параметра равно 0. После установки значения этого параметра равным 0 производится автоматическая перезагрузка устройства.
//------- GSM_2017_08_03-22-03.hex
//https://mysku.ru/blog/ebay/43282.html#comment2168630
//Теперь сигнализация может управлять внешними устройствами. Для управления используется аналоговый выход A3(D17 - используется как цифровой).
//Логический уровень выхода (+5В или GND) может быть изменен, после изменения уровня через команду настройки устройство автоматически будет перезагружено.
//Длительность сигнала управления внешним устройством может быть изменена.
//Добавлены команды ExtDeviceLevelLow, ExtDeviceLevelHigh, ExtDeviceTime, Open.
//Существенно изменена логика работы команд управления. Оптимизация памяти.
//------- GSM_2017_08_10-12-17.hex
//https://mysku.ru/blog/ebay/43282.html#comment2134666
//https://mysku.ru/blog/ebay/43282.html#comment2158624
//https://mysku.ru/blog/ebay/43282.html#comment2161017
//Удалены команды SmsOn/SmsOff, ReedSwitchOn/ReedSwitchOff, PIROn/PIROff и всё что с ними связано. Команда DelayBeforeAlarm заменена расширенными командами. Изменён вывод команды Info. Оптимизирован вывод команды ListConfig в консоль.
//Теперь к датчикам D6 и A0 могут быть подключены любые цифровые датчики с высоким или низким уровнем срабатывания, в том числе герконы.
//Пины D6 и A0 должны быть притянуты к земле через сопротивление 10 (20) кОм. Если датчик настроен на низкий уровень срабатывания (включен в режиме геркона), то проверяется целостность цепи.
//Логический уровень срабатывания по входам D6 и A0 (+5В или GND) может быть изменен, после изменения логического уровня устройство автоматически будет перезагружено.
//Для каждого из датчиков (main, second, PCF-платы расширения) при срабатывании может быть установлено своё время по истечение которого будет осуществлено уведомление (смс и/или голосовой вызов).
//"PIR Sensor" переименован в "Second sensor". Исправлена работа платы расширения при котором устройство всегда уведомляло о срабатывании датчиков, вне зависимости от того поставлено устройство на охрану или нет.
//Теперь можно выбрать режим работы при котором устройство может мониторить датчики платы расширения как во включеном режиме охраны (GuardOn), так и при выключеном режиме (GuardOff),
//Добавлены команды PCFForceOn/PCFForceOff, MainSensorLevelHigh/MainSensorLevelLow, SecondSensorLevelHigh/SecondSensorLevelLow, MainDelayBeforeAlarm, SecondDelayBeforeAlarm, PCFDelayBeforeAlarm.
//-------Актуальная


#include <SoftwareSerial.h>
#include <EEPROM.h>
#include <Wire.h>

typedef struct  {
  char PhoneNum[17];
  //  uint8_t Management;
  uint8_t SAlarm;
  uint8_t RAlarm;
  uint8_t PAlarm;
  uint8_t IAlarm;
  unsigned short addr;
} Phone;

char PhoneCharArray[17]; //При изменении заменить и тут RingPhoneNumber.toCharArray(PhoneCharArray, 17);
char PhoneNum[17];
//uint8_t ManagementOffset = 18;
uint8_t SAlarmOffset = 19;
uint8_t RAlarmOffset = 20;
uint8_t PAlarmOffset = 21;
uint8_t IAlarmOffset = 22;

Phone data[10] = {
  {"", 0, 0, 0, 0, 100}, //Только с первого номера можно изменять другие номера.
  {"", 0, 0, 0, 0, 130},
  {"", 0, 0, 0, 0, 160},
  {"", 0, 0, 0, 0, 190},
  {"", 0, 0, 0, 0, 220},
  {"", 0, 0, 0, 0, 250},
  {"", 0, 0, 0, 0, 280},
  {"", 0, 0, 0, 0, 310},
  {"", 0, 0, 0, 0, 340},
  {"", 0, 0, 0, 0, 370}
};

typedef struct  {
  char SensorName[18];
  uint8_t LoworHigh;
  unsigned short SensorAddr;
} Sensor;

char SensorNameCharArray[38]; //При изменении заменить и тут EditSensorName.toCharArray(SensorNameCharArray, 38);
char SensorName[38];
uint8_t LoworHighOffset = 39;
uint8_t LorHConfig[8];
uint8_t LorHCurrentFlag[8];
uint8_t PCFDeices = 0;
int PCFAddress; //Должно быть инт иначе варнинги.

Sensor SensorData[8] = {
  {"Sensor 1", 0, 500},
  {"Sensor 2", 0, 540},
  {"Sensor 3", 0, 580},
  {"Sensor 4", 0, 620},
  {"Sensor 5", 0, 660},
  {"Sensor 6", 0, 700},
  {"Sensor 7", 0, 740},
  {"Sensor 8", 0, 780}
};


SoftwareSerial mySerial(8, 9); //На этих пинах подключен модем RX, TX
#define RLed 10 //Красный светодиод
#define BLed 11 //Синий светодиод
#define GLed 12 //Зеленый светодиод
#define AlarmPin 4 //Выход "тревожного" пина, при срабатывании датчика на этом пине устанавливается сигнал высокого уровня на время указанное в переменной AlarmInterval, по умолчанию 60 секунд.
#define InverseAlarmPin 5 //Инверсный выход "тревожного" пина, при срабатывании датчика на этом пине устанавливается сигнал низкого уровня на время указанное в переменной AlarmInterval, по умолчанию 60 секунд.

#define GuardButton5VPin 15 // Pin A1; Использеутся как цифровой. Номер входа, подключенный к GuardButton5V
#define GuardButtonGNDPin 16 // Pin A2; Использеутся как цифровой. Номер входа, подключенный к GuardButtonGND
int8_t GuardButton5VState = 0;
int8_t GuardButtonGNDState = 1;
int8_t GuardButton5VFlag = 2;
int8_t GuardButtonGNDFlag = 2;

#define DoorPin 6 //Номер входа подключенного к герконовому датчику
int8_t DoorSensorLevel = 0;
int8_t DoorState = 0; //Переменная для хранения состояния датчика
int8_t DoorFlag = 1;

#define ExtPowerPin 7 //Номер входа подключенного к делителю напряжения внешнего источника питания для проверки наличия внешнего питания. +5В-R1(2,2К)-.-R2(3,3K)-GND.
int8_t ExtPowerState = 0;
int8_t ExtPowerFlag = 2;

#define PIRPin 14 // Pin A0; Использеутся как цифровой. Номер входа, подключенный к PIR - датчику
int8_t PIRSensorLevel = 1;
int8_t PIRState = 0;
int8_t PIRFlag = 1;

int8_t RLedState = LOW;
int8_t GLedState = LOW;
int8_t BLedState = LOW;

unsigned long previousAlarmMillis = 0;
unsigned short int AlarmInterval = 60; //Секунд до отключения "тревожного" пина.

unsigned long previousMillis = 0;
int8_t interval = 100;

uint16_t PauseTime = 15; //Время, указывается в минутах, на которое сигнализация должна засыпать при получении смс команды Pause.
uint16_t RingTime = 40; //Длительность тревожных вызовов
uint8_t CallFlag = 0;
uint8_t EndCallFlag = 0;
uint8_t CallNum = 0;
uint8_t Call = 0;
unsigned long previousCallTimeMillis = 0;

unsigned long previousWatchPowerTimeMillis = 0;
uint8_t ActivateWatchPowerTime = 0;
uint8_t WatchPowerTimeSmsSended = 0;
uint8_t WatchPowerTime = 0; //Задержка времени перед отправкой смс при отключении сети питания

unsigned long previousDelayBeforeGuardMillis = 0;
uint8_t ActivateDelayBeforeGuard = 0;
uint8_t DelayBeforeGuard = 0; //Задержка времени перед постановкой на охрану

unsigned long previousDelayBeforeAlarmMillis = 0;
uint8_t ActivateDelayBeforeAlarm = 0;
uint8_t DelayBeforeAlarm = 0; //Задержка времени перед отправкой смс и включения тревожных пинов
uint8_t MainDelayBeforeAlarm = 0; //Задержка времени перед отправкой смс и включения тревожных пинов
uint8_t SecondDelayBeforeAlarm = 0; //Задержка времени перед отправкой смс и включения тревожных пинов
//String PrepareAlarmText;
//uint8_t PrepareAlarmRing;
//uint8_t PrepareAlarmSMSForce;
uint8_t PrepareAlarmFromEvent;

uint8_t SuperUser = 0;
uint8_t SMSCommand = 0;
uint8_t ConsoleCommand = 0;

uint8_t ch = 0;
//int8_t sendsms = 1; //Отправка смс: 1 - включена, 0 - выключена. Глобальный параметр отправки сообщений. Управляется через смс командами SmsOn и SmsOff.
//int8_t ReedSwitchGuard = 1; // 1 - включен, 0 - выключен. Герконовый датчик
int8_t guard = 1; //Охрана: 1 - включена, 0 - выключена. Если включена, будут отправляться смс при срабатывании датчиков
//int8_t PIRGuard = 0;
int8_t WatchPower = 1; //Мониторинг внешнего питания:  0 - выключен, 1 - включен когда поставлено на охрану, 2 - включен всегда.
//int8_t sendsmscaller; //Переменная для отправки смс о снятии или установки на охрану пользователям которые отсутствуют в массиве AlarmPhone
int8_t LedTestOn = 0;
int8_t LedOn = 1;
int8_t GuardButtonEnable = 0;
int8_t GuardButtonEvent = 0;
int8_t ConsoleEvent = 0;
int8_t PCFForce = 0;

#define ExternalDevicePin 17 // Pin A3; Использеутся как цифровой. Номер выхода для управления внешними устройствами
int8_t ExternalDeviceLevel = 1;
int8_t ExternalDeviceTime = 1;

String BalanceNumber = "#100#"; //Команда запроса баланса. #100# - ответ латинскими буквами, *100# - ответ русскими буквами. Работает только с латинскими буквами. В данном случае команда запроса баланса Beeline(Россия).
uint8_t BalanceStringLen = 22; //Число символов от начала строки которые нужно переслать в смс сообщении при получении USSD ответа о балансе. Убираем спам от оператора при запросе баланса, особо критично для модема M590, обрезаем всё лишнее.
uint8_t BalanceLenOffset = 18;
uint8_t BalanceSettingsOffset = 19;
char BalanceNum[17];

String val = "";
String NotCheckRingPhone = "";
String RingPhone = "";
String LastEvent = "Guard O";

int8_t ModemID = 0;

const String Marker = " -> ";
const String Warn = "Alarm! ";
String SendSmsText = "";


/*
  EEPROM Data:
  № ячейки - значение;
  0 - если записана не 1, то необходимо затереть часть памяти eeprom'a отвечающую за настройки и восстановить стандартную конфигурацию.
  6 - Уровень сигнала срабатывания основного датчика D6: 0 - низкий, 1 - высокий +5В.
  7 - MainDelayBeforeAlarm = 0; //Задержка времени перед отправкой смс и включения тревожных пинов
  8 - Уровень сигнала срабатывания дополнительного датчика A0: 0 - низкий, 1 - высокий +5В.
  9 - SecondDelayBeforeAlarm = 0; //Задержка времени перед отправкой смс и включения тревожных пинов
  10 - sendsms = 1; //Отправка смс: 1 - включена, 0 - выключена. Глобальный параметр отправки сообщений. Управляется через смс командами SmsOn и SmsOff.
  11 - AlarmRing = 1; //Звонок: 1 - включен, 0 - выключен. Звонить на первый номер массива AlarmPhone при срабатывании датчика. Управляется через смс командами RingOn и RingOff.
  12 - LedTestOn = 0;
  13 - LedOn = 1;
  14 - guard = 1; //Охрана: 1 - включена, 0 - выключена. Если включена, будут отправляться смс при срабатывании датчиков
  15 - PauseTime; //в минутах, не менее 1 и не более 60.
  16,17 - AlarmInterval; //Секунд до отключения "тревожного" пина.
  18 - PIRGuard = 0; //Датчик движения: 1 - включен, 0 - выключен. Если включен, будут отправляться смс при срабатывании PIR - датчика
  19 - WatchExtPower = 1; //ExtPowerWatch мониторинг сети питания: 1 - включен, 0 - выключен.
  20 - GuardButtonEnable = 0; //Снятие и постановка на охрану кнопкой.
  21 - DelayBeforeGuard = 0; //Задержка времени перед постановкой на охрану
  22 - DelayBeforeAlarm = 0; //Задержка времени перед отправкой смс и включения тревожных пинов
  23 - WatchPowerTime = 0; //Задержка времени перед отправкой смс при отключении сети питания
  24 - RingTime = 40; //Длительность тревожных вызовов
  25 - ModemID = 0; //0 - Автоопределение модема, 1 - M590, 2 - SIM800l, 3 - A6_Mini.
  26 - Уровень сигнала для управления внешними устройствами 0 - низкий, 1 - высокий +5В.
  27 - Количество секунд до отключения сигнала управления внешним устройством.
  28 - Форсированная обработка событий PCF модуля.

  49 (30-49) - если записана не 1, то необходимо затереть часть памяти eeprom'a отвечающую за номер запросабаланса и восстановить стандартную конфигурацию.
  98 - если записана не 1, то необходимо затереть часть памяти eeprom'a отвечающую за названия PCF датчиков и восстановить стандартную конфигурацию из структуры.
  99 - если записана не 1, то необходимо затереть часть памяти eeprom'a отвечающую за номера телефонов и восстановить стандартную конфигурацию из структуры.
*/

void setup() {

  Serial.begin(9600);
  Wire.begin();
  //  Serial.println( F ("GSM Alarm 17.06.02 Current"));
  Serial.println( F ("GSM Alarm 17.08.10 fix-01"));
  lineprint();
  //Serial.println( F ("Init params..."));
  /*    for (uint8_t dot = 0 ; dot < 12 ; dot++) {
       Serial.print( F ("."));
       delay(250);
      }
      //lineprint();*/
  //lineprint();

  delay(2500);
  randomSeed(analogRead(0));
  //pinMode(13, OUTPUT);


  //EEPROM.update(0, 255); //Uncomment to reset system config;
  eepromconfig();
  //EEPROM.update(49, 255); //Uncomment to reset balance query config;
  eeprombalancenum();
  //EEPROM.update(99, 255); //Uncomment to reset phones config;
  eepromphonememory();
  //EEPROM.update(98, 255); //Uncomment to reset PCF sensor config;
  eepromsensormemory();
  i2cscan();

  pinMode(RLed, OUTPUT);
  pinMode(GLed, OUTPUT);
  pinMode(BLed, OUTPUT);
  digitalWrite(RLed, HIGH);
  digitalWrite(GLed, HIGH);
  digitalWrite(BLed, HIGH);

  //Мигание светодиодами при загрузке
  digitalWrite(RLed, LOW);
  delay(500);
  digitalWrite(RLed, HIGH);
  digitalWrite(GLed, LOW);
  delay(500);
  digitalWrite(GLed, HIGH);
  digitalWrite(BLed, LOW);
  delay(500);
  digitalWrite(BLed, HIGH);

  if (DoorSensorLevel == 0) {
    pinMode(DoorPin, INPUT);
  } else {
    pinMode(DoorPin, INPUT_PULLUP);
  };
  if (PIRSensorLevel == 0) {
    pinMode(PIRPin, INPUT);
  } else {
    pinMode(PIRPin, INPUT_PULLUP);
  };
  //  pinMode(PIRPin, INPUT);
  //  pinMode(ExtPowerPin, INPUT);

  pinMode(GuardButton5VPin, INPUT);
  pinMode(GuardButtonGNDPin, INPUT);

  pinMode(AlarmPin, OUTPUT);
  digitalWrite(AlarmPin, LOW);
  pinMode(InverseAlarmPin, OUTPUT);
  digitalWrite(InverseAlarmPin, HIGH);

  pinMode(ExternalDevicePin, OUTPUT);
  if (ExternalDeviceLevel == 1) {
    digitalWrite(ExternalDevicePin, LOW);
  }
  else {
    digitalWrite(ExternalDevicePin, HIGH);
  };

  InitModem();
  //Serial.println( F ("Go!"));
  if (guard == 1) LastEvent += "N";
  if (guard == 0) LastEvent += "FF";
  LastEvent += F(" at boot");
  Serial.println(LastEvent);
  /*  if (sendsms == 0) {
      Serial.println( F ("Silent mode!"));
      LongBlinkBLed();
    }*/
  lineprint();
}

void loop() {
  GuardButtonCheck();
  ExternalPowerMon();
  LorHCompare();
  //LedTest();
  Led();
  AlarmPinOff();
  Detect();
  PIRDetect();
  DelayGuardOn();
  DelayAlarm();
  AlarmCall();

  if (mySerial.available()) {  //Если GSM модуль что-то послал нам, то
    while (mySerial.available()) {  //сохраняем входную строку в переменную val
      ch = mySerial.read();
      val += char(ch);
      delay(10);
    }
    uint8_t l = 1;
    if (ModemID == 1 || ModemID == 3) l = 1;
    if (ModemID == 2) l = 2;
    //    if (val.indexOf( F ("+PBREADY")) > -1) InitModem(); //Если модем во время работы перезагрузился, выполняем настройку, только для М590
    if (val.indexOf( F ("RING")) > -1) {  //Если звонок обнаружен, то проверяем номер
      //Serial.println(val);//Orig
      //NotCheckRingPhone = "";//Orig
      String NotCheckRingPhone = val.substring(String(val.indexOf("\"")).toInt() + l, String(val.indexOf(F(","))).toInt() - 1);
      Serial.print( F ("Ring from: +"));
      Serial.println(NotCheckRingPhone);
      eepromfirstphone(NotCheckRingPhone);
      if (eepromcheckphone(NotCheckRingPhone) == 1) {
        //mySerial.println( F ("AT+CHUP")); //Разрываем связь
        endcall();
        //        sendsmscaller = 1;
        MasterRing();
      } else {
        //mySerial.println( F ("AT+CHUP")); //Разрываем связь
        endcall();
      }
    } else if (val.indexOf( F ("+CMT:")) > -1) {  //Если пришло смс, то проверяем номер
      Serial.println(val);
      //Serial.println(val);//Orig
      //      NotCheckRingPhone = val.substring(String(val.indexOf("\"")).toInt() + 2, String(val.indexOf(",")).toInt() - 1);
      if (ModemID == 1 || ModemID == 3) NotCheckRingPhone = val.substring(String(val.indexOf("+CMT: \"")).toInt() + 8, String(val.indexOf(F(",,"))).toInt() - 1);
      if (ModemID == 2) NotCheckRingPhone = val.substring(String(val.indexOf("+CMT: \"")).toInt() + 8, String(val.indexOf(F(",\""))).toInt() - 1);
      Serial.print( F ("SMS from: +"));
      Serial.println(NotCheckRingPhone);
      if (eepromcheckphone(NotCheckRingPhone) == 1) {
        if (eepromchecksuphone(NotCheckRingPhone) == 1) SuperUser = 1;
        //        sendsmscaller = 1;
        SMSCommand = 1;
        MasterCommands();
      }
    } else if (val.indexOf( F ("+CUSD:")) > -1) {  //Если пришел USSD ответ
      //Serial.print( F ("USSD query for : +"));//Orig
      Serial.print( F ("USSD query: "));
      //Serial.println(RingPhone);
      Serial.println(val);
      if (val.indexOf("\"") > -1) {
        //sms(String(val.substring(String(val.indexOf("\"")).toInt() + 1, String(val.indexOf("\"")).toInt() + BalanceStringLen)), String("+" + RingPhone));//Orig
        SendSmsText = val.substring(String(val.indexOf("\"")).toInt() + 1, String(val.indexOf("\"")).toInt() + BalanceStringLen);
        if (ConsoleEvent == 0)sms("+" + RingPhone);
        ConsoleEvent = 0;
        delay(1000);
      }
      mySerial.println( F ("AT+CUSD=0"));//Orig
      //mySerial.print("AT+");
      //mySerial.println( F ("CUSD=0"));
      delay(200);
      //    } else
    }
    if (LedTestOn == 1) Serial.println(val);  //Печатаем в монитор порта пришедшую строку
    val = "";
  }
  if (Serial.available()) {  //Если в мониторе порта ввели что-то
    while (Serial.available()) {  //Сохраняем строку в переменную val
      ch = Serial.read();
      val += char(ch);
      delay(20);
    }
    if (LedTestOn == 1) mySerial.println(val);  //передача всех команд набранных в мониторе порта в GSM модуль если включен тестовый режим
    //ConsolePrint();//Orig!
    SuperUser = 1;
    ConsoleCommand = 1;
    MasterCommands();
    val = "";  //Очищаем
  }
}

// ----- Soft Reset
void(* Reset) (void) = 0;

// ----- Долгое мигание синим светодиодом
void LongBlinkBLed () {
  for (uint8_t i = 1 ; i < 10 ; i++) {
    LedOK();
  }
}

// ----- Проверка состояния кнопки охраны
void GuardButtonCheck() {
  if ((GuardButtonEnable == 1) || (GuardButtonEnable == 2 && guard == 0)) {
    GuardButton5VState = digitalRead(GuardButton5VPin);
    GuardButtonGNDState = digitalRead(GuardButtonGNDPin);
    if (GuardButton5VState == HIGH && GuardButton5VFlag == 0) {
      GuardButton5VFlag = 1;
      delay(200);
      GuardButtonPush();
    }
    if (GuardButtonGNDState == LOW && GuardButtonGNDFlag == 0) {
      GuardButtonGNDFlag = 1;
      delay(200);
      GuardButtonPush();
    }
    if (GuardButton5VState == LOW && GuardButton5VFlag != 0) {
      GuardButton5VFlag = 0;
      delay(200);
    }
    if (GuardButtonGNDState == HIGH && GuardButtonGNDFlag != 0) {
      GuardButtonGNDFlag = 0;
      delay(200);
    }
  }
}

// ----- Нажатие кнопки охраны
void GuardButtonPush() {
  LedOK();
  //  Serial.println( F ("Button is pressed"));
  GuardButtonEvent = 1;
  //  sendsmscaller = 0;
  MasterRing();
}

// ----- Проверка внешнего питания
void ExternalPowerMon() {
  //Serial.println(WatchExtPower);
  if ((WatchPower == 1 && guard == 1) || WatchPower == 2) {
    //Считываем значения с входа питания
    ExtPowerState = digitalRead(ExtPowerPin);
    if (ExtPowerState == LOW && ExtPowerFlag == 0) {
      ExtPowerFlag = 1;
      delay(100);
      SendSmsText = F ("Power supply disconnected ");
      PrepareWatchPowerTimeAlarm(2);
    }
    if (ExtPowerState == HIGH && ExtPowerFlag == 1) {
      ActivateWatchPowerTime = 0;
      ExtPowerFlag = 0;
      delay(100);
      if (WatchPowerTimeSmsSended == 1) {
        SendSmsText = F ("Power supply restored");
        SmsAlarm(2);
        WatchPowerTimeSmsSended = 0;
      }
    }
    if (ExtPowerState == HIGH && ExtPowerFlag == 2) {
      ExtPowerFlag = 0;
      delay(100);
    }
  }
}

// ----- Инициализация номера запроса баланса
void eeprombalancenum() {
  if (EEPROM.read(30 + BalanceSettingsOffset) != 1) {
    Serial.println( F ("Delete balance data."));
    for (uint8_t i = 30 ; i < (BalanceSettingsOffset + 1) ; i++) {
      EEPROM.update(i, 255);
      delay(10);
    }
    Serial.println( F ("Load default balance data."));
    lineprint();
    BalanceNumber = "#100#";
    BalanceStringLen = 22;
    BalanceNumber.toCharArray(BalanceNum, 17);
    EEPROM.put(30, BalanceNum);
    EEPROM.update(30 + BalanceLenOffset, BalanceStringLen);
    EEPROM.update(30 + BalanceSettingsOffset, 1);
  }
  if (EEPROM.read(30 + BalanceSettingsOffset) == 1) {
    //BalanceNumber = String (EEPROM.get(30, BalanceNum));//Orig
    BalanceNumber = EEPROM.get(30, BalanceNum);
    BalanceStringLen = EEPROM.read(30 + BalanceLenOffset);
    Serial.print( F ("Balance number: "));
    Serial.println(BalanceNumber);
    Serial.print( F ("Length to return: "));
    Serial.println(BalanceStringLen);
    lineprint();
  }
}

// ----- Изменение номера запроса баланса
void eepromupdatebalancenum(String BalanceNumber, uint8_t BalanceStringLen) {
  BalanceNumber.toCharArray(BalanceNum, 17);
  EEPROM.put(30, BalanceNum);
  EEPROM.update(30 + BalanceLenOffset, BalanceStringLen);
  EEPROM.update(30 + BalanceSettingsOffset, 1);
  //Serial.print( F ("Request number balance modified: "));//Orig
  //Serial.println(EEPROM.get(30, BalanceNum));//Orig
  //Serial.print( F ("Length of characters to return: "));//Orig
  //Serial.println(EEPROM.read(30 + BalanceLenOffset));//Orig
  eeprombalancenum();
  Serial.println();
  //lineprint();
  LedOK();
}

// ----- Изменение времени PauseTime
void eepromupdatepausetime(uint8_t SmsPauseTime) {
  EEPROM.update(15, SmsPauseTime);
  PauseTime = SmsPauseTime;
  Serial.print( F ("PauseTime is: "));
  //Serial.println(String(EEPROM.read(15)));//Orig
  Serial.println(EEPROM.read(15));
  lineprint();
  LedOK();
}

// ----- Изменение времени DelayBeforeGuard
void eepromupdatedelaybeforeguard(uint8_t SmsDelayBeforeGuard) {
  EEPROM.update(21, SmsDelayBeforeGuard);
  DelayBeforeGuard = SmsDelayBeforeGuard;
  Serial.print( F ("DelayBeforeGuard is: "));
  Serial.println(EEPROM.read(21));
  lineprint();
  LedOK();
}

// ----- Изменение времени DelayBeforeAlarm
void eepromupdatedelaybeforealarm(uint8_t SmsDelayBeforeAlarm, uint8_t ms) {
  if (ms == 1) {
    EEPROM.update(7, SmsDelayBeforeAlarm);
    MainDelayBeforeAlarm = SmsDelayBeforeAlarm;
    Serial.print( F ("MainDelayBeforeAlarm is: "));
    Serial.println(EEPROM.read(7));
  }
  if (ms == 2) {
    EEPROM.update(9, SmsDelayBeforeAlarm);
    SecondDelayBeforeAlarm = SmsDelayBeforeAlarm;
    Serial.print( F ("SecondDelayBeforeAlarm is: "));
    Serial.println(EEPROM.read(9));
  }
  if (ms == 3) {
    EEPROM.update(22, SmsDelayBeforeAlarm);
    DelayBeforeAlarm = SmsDelayBeforeAlarm;
    Serial.print( F ("PCFDelayBeforeAlarm is: "));
    Serial.println(EEPROM.read(22));
  }
  /*
    EEPROM.update(22, SmsDelayBeforeAlarm);
    DelayBeforeAlarm = SmsDelayBeforeAlarm;
    Serial.print( F ("DelayBeforeAlarm is: "));
    Serial.println(EEPROM.read(22));*/
  lineprint();
  LedOK();
}

// ----- Изменение времени WatchPowerTime
void eepromupdatewatchpowertime(uint8_t SmsWatchPowerTime) {
  EEPROM.update(23, SmsWatchPowerTime);
  WatchPowerTime = SmsWatchPowerTime;
  Serial.print( F ("WatchPowerTime is: "));
  Serial.println(EEPROM.read(23));
  lineprint();
  LedOK();
}

// ----- Изменение длительности тревожного звонка
void eepromupdateringtime(uint8_t SmsRingTime) {
  EEPROM.update(24, SmsRingTime);
  RingTime = SmsRingTime;
  Serial.print( F ("RingTime is: "));
  Serial.println(EEPROM.read(24));
  lineprint();
  LedOK();
}

// ----- Изменение времени AlarmPinTime
void eepromupdatealarmpintime( unsigned short int num) {
  byte raw[2];
  (unsigned short int&)raw = num;
  for (byte i = 0; i < 2; i++) EEPROM.write(16 + i, raw[i]);
  AlarmInterval = num;
  Serial.print( F ("AlarmInterval is: "));
  //Serial.println(String(AlarmInterval)); //Orig
  Serial.println(AlarmInterval);
  lineprint();
  LedOK();
}

// ----- Чтение времени AlarmPinTime
unsigned short int eepromreadalarmpintime() {
  byte raw[2];
  for (byte i = 0; i < 2; i++) raw[i] = EEPROM.read(16 + i);
  unsigned short int &num = (unsigned short int&)raw;
  //Serial.println("Read "+String(num));
  return num;
}

// ----- Инициализация основного номера
void eepromfirstphone(String RingPhoneNumber) {
  if (String(EEPROM.get(data[0].addr, PhoneNum)) == "") {
    RingPhoneNumber.toCharArray(PhoneCharArray, 17);
    EEPROM.put(data[0].addr, PhoneCharArray);
    //EEPROM.update(data[0].addr + ManagementOffset, 1);
    EEPROM.update(data[0].addr + SAlarmOffset, 1);
    EEPROM.update(data[0].addr + RAlarmOffset, 1);
    EEPROM.update(data[0].addr + PAlarmOffset, 1);
    EEPROM.update(data[0].addr + IAlarmOffset, 1);
    Serial.print( F ("Primary phone: +"));
    Serial.println(RingPhoneNumber);
    lineprint();
    LedOK();
    endcall();
    //    delay(1000);
    Reset();
  } /*else {
    Serial.println( F ("The primary phone number already added."));
    lineprint();
  }*/
}

// ----- Удаление номера
void eepromdeletephone(String DeletePhoneNumber) {
  uint8_t error = 1;
  for (uint8_t i = 1 ; i < 10 ; i++) {
    if (String(EEPROM.get(data[i].addr, PhoneNum)) == DeletePhoneNumber) {
      //Serial.println (i + 1);
      //DeletePhoneNumber = "";
      //DeletePhoneNumber.toCharArray(PhoneCharArray, 17);
      char PhoneCharArray[17] = "";
      EEPROM.put(data[i].addr, PhoneCharArray);
      //EEPROM.update(data[i].addr + ManagementOffset, 0);
      EEPROM.update(data[i].addr + SAlarmOffset, 0);
      EEPROM.update(data[i].addr + RAlarmOffset, 0);
      EEPROM.update(data[i].addr + PAlarmOffset, 0);
      EEPROM.update(data[i].addr + IAlarmOffset, 0);
      Serial.print( F ("Delete phone: +"));
      Serial.println(DeletePhoneNumber);
      lineprint();
      listphone();
      LedOK();
      error = 0;
    }
  }
  if (error == 1) {
    Serial.print( F ("Error deleting phone: +"));
    Serial.println(DeletePhoneNumber);
    lineprint();
    LedERROR();
  }
}

// ----- Добавление номера
//void eepromaddphone(String AddPhoneNumber, uint8_t Cell, uint8_t M, uint8_t S, uint8_t R, uint8_t P, uint8_t I ) {
void eepromaddphone(String AddPhoneNumber, uint8_t Cell, uint8_t S, uint8_t R, uint8_t P, uint8_t I ) {
  //Serial.println(String(Cell) + Marker + AddPhoneNumber + Marker + String(M) + Marker + String(S)+ Marker + String(R)+ Marker + String(P)); //Orig
  uint8_t createnumber = 1;
  Cell -= 1;

  if (String(EEPROM.get(data[0].addr, PhoneNum)) == "") {
    Serial.println( F ("Error, not set main phone."));
    lineprint();
    LedERROR();
    createnumber = 0;
  }
  if (Cell <= 0 || Cell > 10)  {
    Serial.println( F ("Error, wrong cell."));
    lineprint();
    LedERROR();
    createnumber = 0;
  }
  if (createnumber == 1) {
    //Защита задвоения номеров, если необходимо изменить права, нужно перезписать номер на произвольный, и заново ввеси новый с нужными правами.
    for (uint8_t i = 0 ; i < 10 ; i++) {
      if (String(EEPROM.get(data[i].addr, PhoneNum)) == AddPhoneNumber) {
        //Serial.print( F ("Error, this phone already exists in the cell: "));
        Serial.print( F ("Phone already exists in the cell: "));
        //Serial.println(String(i + 1));//Orig
        Serial.println(i + 1);
        //LedERROR();
        //createnumber = 0;
        lineprint();
        if (i != Cell) {
          //M = 0;
          S = 0;
          P = 0;
          I = 0;
        }
      }
    }
  }
  if (createnumber == 1) {
    AddPhoneNumber.toCharArray(PhoneCharArray, 17);
    EEPROM.put(data[Cell].addr, PhoneCharArray);
    //EEPROM.update(data[Cell].addr + ManagementOffset, M);
    EEPROM.update(data[Cell].addr + SAlarmOffset, S);
    EEPROM.update(data[Cell].addr + RAlarmOffset, R);
    EEPROM.update(data[Cell].addr + PAlarmOffset, P);
    EEPROM.update(data[Cell].addr + IAlarmOffset, I);
    Serial.println( F ("Phone added."));
    lineprint();
    LedOK();
  }
  //listphone();
}

// ----- Инициализация памяти номеров
void eepromphonememory() {
  if (EEPROM.read(99) != 1) {        //Сюда код начальной инициализации памяти телефонов.
    Serial.println( F ("Deleting phone data."));
    for (unsigned short int i = 100 ; i < 400 ; i++) {
      EEPROM.update(i, 255);
      delay(10);
    }
    Serial.println( F ("Load default phone data."));
    lineprint();
    for ( uint8_t i = 0; i < 10; i++ ) {
      EEPROM.put(data[i].addr, data[i].PhoneNum);
      //EEPROM.update(data[i].addr + ManagementOffset, data[i].Management);
      EEPROM.update(data[i].addr + SAlarmOffset, data[i].SAlarm);
      EEPROM.update(data[i].addr + RAlarmOffset, data[i].RAlarm);
      EEPROM.update(data[i].addr + PAlarmOffset, data[i].PAlarm);
      EEPROM.update(data[i].addr + IAlarmOffset, data[i].IAlarm);
    }
    EEPROM.update(99, 1);
  }

  //Ниже только для отладки, пока не вижу смысла читать данные в массив.
  if (EEPROM.read(99) == 1) {
    //Сюда код чтения из памяти телефонных номеров.
    listphone();
  }
}

// ----- Вывод в консоль номеров
void listphone() {
  Serial.println ( F ("Read array phone:"));
  Serial.print (F("№"));
  Serial.print (Marker + F("Phone"));
  //Serial.print (Marker + F("m"));
  Serial.print (Marker + F("s"));
  Serial.print (Marker + F("r"));
  Serial.print (Marker + F("p"));
  Serial.println (Marker + F("i"));

  for ( uint8_t i = 0; i < 10; i++ ) {
    //delay(500);
    EEPROM.get(data[i].addr, PhoneNum);
    //Serial.println(String(data[i].addr) + " -> " + data[i].PhoneNum + "-> " + PhoneNum + " -> " + EEPROM.read(data[i].addr + ManagementOffset) + " -> " + EEPROM.read(data[i].addr + AlarmOffset));
    //Serial.println(String(String(i + 1) + Marker + PhoneNum + Marker + EEPROM.read(data[i].addr + ManagementOffset) + Marker + EEPROM.read(data[i].addr + SAlarmOffset))); //Orig
    //    Serial.println((i + 1) + Marker + PhoneNum + Marker + EEPROM.read(data[i].addr + ManagementOffset) + Marker + EEPROM.read(data[i].addr + SAlarmOffset) + Marker + EEPROM.read(data[i].addr + RAlarmOffset) + Marker + EEPROM.read(data[i].addr + PAlarmOffset));
    //Serial.print((i + 1) + Marker + PhoneNum + Marker + EEPROM.read(data[i].addr + ManagementOffset) + Marker + EEPROM.read(data[i].addr + SAlarmOffset));
    Serial.print((i + 1) + Marker + PhoneNum + Marker + EEPROM.read(data[i].addr + SAlarmOffset));
    Serial.println(Marker + EEPROM.read(data[i].addr + RAlarmOffset) + Marker + EEPROM.read(data[i].addr + PAlarmOffset) + Marker + EEPROM.read(data[i].addr + IAlarmOffset));
  }
  lineprint();
}

// ----- Инициализация конфигурации устройства
void eepromconfig() {
  if (EEPROM.read(0) != 1) {
    Serial.println( F ("Deleting eepromconfig data."));
    for (uint8_t i = 0 ; i < 30 ; i++) {
      EEPROM.update(i, 255);
      delay(10);
    }
    Serial.println( F ("Load default eepromconfig data."));
    lineprint();
    EEPROM.update(6, 0); //Уровень сигнала срабатывания основного датчика: 0 - низкий, 1 - высокий +5В.
    EEPROM.update(7, 0); //MainDelayBeforeAlarm задержка времени перед отправкой смс и включения тревожных пинов
    EEPROM.update(8, 1); //Уровень сигнала срабатывания дополнительного датчика: 0 - низкий, 1 - высокий +5В.
    EEPROM.update(9, 0); //SecondDelayBeforeAlarm задержка времени перед отправкой смс и включения тревожных пинов
    EEPROM.update(10, 1);  //sendsms = 1; //Отправка смс: 1 - включена, 0 - выключена. Глобальный параметр отправки сообщений. Управляется через смс командами SmsOn и SmsOff.
    EEPROM.update(11, 1);  //ReedSwitchGuard = 1; //1 - включен, 0 - выключен. Основной геркон.
    EEPROM.update(12, 0);  //LedTestOn = 0;
    EEPROM.update(13, 1);  //LedOn = 1;
    EEPROM.update(14, 1); //Охрана: 1 - включена, 0 - выключена. Если включена, будут отправляться смс при срабатывании датчиков
    EEPROM.update(15, 15); //PauseTime - в минутах, не менее 1 и не более 60.
    eepromupdatealarmpintime(60);
    EEPROM.update(18, 0); //Датчик движения: 1 - включен, 0 - выключен. Если включен, будут отправляться смс при срабатывании PIR - датчика
    EEPROM.update(19, 1); //WatchExtPower мониторинг сети питания: 1 - включен, 0 - выключен.
    EEPROM.update(20, 0); //GuardButtonEnable функция снятия и постановки на охрану кнопками:  1 - включена(включение-выключение), 2 - включена (только включение), 0 - выключена.
    EEPROM.update(21, 0); //DelayBeforeGuard задержка времени перед постановкой на охрану
    EEPROM.update(22, 0); //DelayBeforeAlarm задержка времени перед отправкой смс и включения тревожных пинов
    EEPROM.update(23, 0); //WatchPowerTime Задержка времени перед отправкой смс при отключении сети питания
    EEPROM.update(24, 40); //RingTime Длительность тревожного голосового вызова.
    EEPROM.update(25, 0); //ModemID. 0 - Автоопределение модема, 1 - M590, 2 - SIM800l, 3 - A6_Mini.
    EEPROM.update(26, 1); //Уровень сигнала для управления внешними устройствами 0 - низкий, 1 - высокий +5В.
    EEPROM.update(27, 1); //Количество секунд до отключения сигнала управления внешним устройством.
    EEPROM.update(28, 0); //Форсированная обработка событий PCF модуля: 1 - включена, 0 - выключена.
    EEPROM.update(0, 1);
  }
  if (EEPROM.read(0) == 1) {
    Serial.println( F ("Read eepromconfig:"));
    lineprint();
    /*    sendsms = EEPROM.read(10);  //sendsms = 1; //Отправка смс: 1 - включена, 0 - выключена. Глобальный параметр отправки сообщений. Управляется через смс командами SmsOn и SmsOff.
        Serial.print( F ("SendSms: "));
        //Serial.println(String(sendsms)); //Orig
        Serial.println(sendsms);*/

    RingTime = EEPROM.read(24);
    Serial.print( F ("RingTime: "));
    Serial.println(RingTime);

    LedTestOn = EEPROM.read(12);  //LedTestOn = 0;
    Serial.print( F ("Test: "));//LedTestOn
    //Serial.println(String(LedTestOn));//Orig
    Serial.println(LedTestOn);

    LedOn = EEPROM.read(13);  //LedOn = 1;
    Serial.print( F ("Led: "));
    //Serial.println(String(LedOn));//Orig
    Serial.println(LedOn);

    guard = EEPROM.read(14); //Охрана: 1 - включена, 0 - выключена. Если включена, будут отправляться смс при срабатывании датчиков
    Serial.print( F ("Guard: "));
    //Serial.println(String(guard));//Orig
    Serial.println(guard);

    PauseTime = EEPROM.read(15); //PauseTime в минутах, не менее 1 и не более 60.
    Serial.print( F ("SleepTime: "));
    //Serial.println(String(PauseTime));//Orig
    Serial.println(PauseTime);

    AlarmInterval = eepromreadalarmpintime();
    Serial.print( F ("AlarmPinTime: "));
    //Serial.println(String(AlarmInterval));//Orig
    Serial.println(AlarmInterval);
    /*@@
        ReedSwitchGuard = EEPROM.read(11);  //ReedSwitchGuard = 1; //Звонок: 1 - включен, 0 - выключен. Основной геркон
        Serial.print( F("ReedSwitchGuard: "));
        //Serial.println(String(AlarmRing));//Orig
        Serial.println(ReedSwitchGuard);

        PIRGuard = EEPROM.read(18); //Датчик движения: 1 - включен, 0 - выключен. Если включен, будут отправляться смс при срабатывании PIR - датчика
        Serial.print( F ("PIRGuard: "));
        //Serial.println(String(PIRGuard));//Orig
        Serial.println(PIRGuard);
    */
    WatchPower = EEPROM.read(19);
    WatchPowerTime = EEPROM.read(23);
    Serial.println( F ("WatchPower"));
    Serial.print( F (" Mode: "));
    //Serial.println(String(WatchPower));//Orig
    Serial.println(WatchPower);
    Serial.print( F (" Time: "));
    Serial.println(WatchPowerTime);

    GuardButtonEnable = EEPROM.read(20);
    Serial.print( F ("GuardButton: "));
    Serial.println(GuardButtonEnable);

    DelayBeforeGuard = EEPROM.read(21);
    Serial.print( F ("DelayBeforeGuard: "));
    Serial.println(DelayBeforeGuard);

    ExternalDeviceLevel = EEPROM.read(26);
    ExternalDeviceTime = EEPROM.read(27);
    Serial.println( F ("ExtDevice"));
    Serial.print( F (" Level: "));
    Serial.println(ExternalDeviceLevel);
    Serial.print( F (" Time: "));
    Serial.println(ExternalDeviceTime);

    DoorSensorLevel = EEPROM.read(6);
    PIRSensorLevel = EEPROM.read(8);
    Serial.println( F ("SensorLevel"));
    Serial.print( F (" Main: "));
    Serial.println(DoorSensorLevel);
    Serial.print( F (" Second: "));
    Serial.println(PIRSensorLevel);

    MainDelayBeforeAlarm = EEPROM.read(7);
    SecondDelayBeforeAlarm = EEPROM.read(9);
    DelayBeforeAlarm = EEPROM.read(22);
    Serial.println( F ("DelayBeforeAlarm"));
    Serial.print( F (" Main: "));
    Serial.println(MainDelayBeforeAlarm);
    Serial.print( F (" Second: "));
    Serial.println(SecondDelayBeforeAlarm);
    Serial.print( F (" PCF: "));
    Serial.println(DelayBeforeAlarm);

    PCFForce = EEPROM.read(28);
    Serial.print( F ("PCFForce: "));
    Serial.println(PCFForce);

    ModemID = EEPROM.read(25);
    Serial.print( F ("ModemID: "));
    if (ModemID == 0) Serial.println(F("Autodetect"));
    else
      Serial.println(ModemID);

    lineprint();
  }
}

// ----- Инициализация модема
void InitModem() {
  delay(2000);  //Время на инициализацию модуля
  Serial.begin(9600);  //Скорость порта
  mySerial.begin(9600);
  for ( uint8_t i = 0; i < 10; i++ ) {
    mySerial.println( F ("AT"));
    delay(200);
  }

  mySerial.println( F ("ATI"));
  delay(10);
  if (mySerial.available()) {  //Если GSM модуль что-то послал нам, то
    while (mySerial.available()) {  //сохраняем входную строку в переменную val
      ch = mySerial.read();
      val += char(ch);
      delay(20);
    }
    if (ModemID == 0) {
      if (val.indexOf( F ("M590")) > -1) ModemID = 1;
      if (val.indexOf( F ("SIM800")) > -1) ModemID = 2;
      if (val.indexOf( F ("A6")) > -1) ModemID = 3;
      Serial.print(F("Detected ModemID: "));
      Serial.println(ModemID);
    }
    val = "";
  }

  mySerial.println( F ("AT+CLIP=1")); //Включаем АОН
  delay(100);
  mySerial.println( F ("AT+CMGF=1")); //Режим кодировки СМС - обычный (для англ.)
  delay(100);
  mySerial.println( F ("AT+CSCS=\"GSM\"")); //Режим кодировки текста
  delay(100);
  mySerial.println( F ("AT+CNMI=2,2")); //Отображение смс в терминале сразу после приема (без этого сообщения молча падают в память)
  delay(100);
  if (LedTestOn == 1) {
    mySerial.println( F ("ATE1"));
  }
  else mySerial.println( F ("ATE0"));
  mySerial.println( F ("ATE0"));
}

/* Функционал пока не задействован
  int eepromcheckphone(String CheckPhoneNumber) {
  for (int i = 0; i < 10; i++) {
    if (String(EEPROM.get(data[i].addr, PhoneNum)) == CheckPhoneNumber) {
      //RingPhone = String(EEPROM.get(data[i].addr, PhoneNum));
      //Serial.println("Event: +" + RingPhone);
      return 1;
    }
  }
  return 0;
  }

  int eepromcheckaphone(String CheckPhoneANumber) {
  for (int i = 0; i < 10; i++) {
    if (String(EEPROM.get(data[i].addr, PhoneNum)) == CheckPhoneANumber) {
      if (EEPROM.read(data[i].addr + AlarmOffset) == 1) {
        RingPhone = String(EEPROM.get(data[i].addr, PhoneNum));
        Serial.println("Event: +" + RingPhone);
        return 1;
      }
    }
  }
  return 0;
  }
*/

// ----- Проверка номера SuperUser
uint8_t eepromchecksuphone(String CheckPhoneSUNumber) {
  if (String(EEPROM.get(data[0].addr, PhoneNum)) == CheckPhoneSUNumber) return 1;
  return 0;
}

// ----- Проверка номера
uint8_t eepromcheckphone(String CheckPhoneMNumber) {
  for (uint8_t i = 0; i < 10; i++) {
    //Serial.println("CheckPhoneMNumber = " + CheckPhoneMNumber);
    if (String(EEPROM.get(data[i].addr, PhoneNum)) == CheckPhoneMNumber) {
      //Serial.println(data[i].addr + ManagementOffset);
      //Serial.println(EEPROM.read(data[i].addr + ManagementOffset));
      //RingPhone = String(EEPROM.get(data[i].addr, PhoneNum)); //Orig !!
      RingPhone = CheckPhoneMNumber;
      //      if (EEPROM.read(data[i].addr + ManagementOffset) == 1) {
      //Serial.println("return 1");
      return 1;
      break;
      //      }
    }
  }
  return 0;
  //Serial.println("return 1");
}

// ----- Проверка состояния герконового датчика
void Detect() {
  DoorState = digitalRead(DoorPin);
  //DelayBeforeAlarm = MainDelayBeforeAlarm;
  if (DoorFlag == 0) {
    if (DoorSensorLevel == 0 && DoorState == LOW) {
      DoorFlag = 1;
      delay(100);
      if (guard == 1) {
        if (LedOn == 1) digitalWrite(GLed, LOW);
        SendSmsText = Warn + (F ("Main sensor!"));
        DelayBeforeAlarm = MainDelayBeforeAlarm;
        PrepareAlarm(1);
      }
    }  else if (DoorSensorLevel == 1 && DoorState == HIGH) {
      DoorFlag = 1;
      delay(100);
      if (guard == 1) {
        if (LedOn == 1) digitalWrite(GLed, LOW);
        SendSmsText = Warn + (F ("Main sensor!"));
        DelayBeforeAlarm = MainDelayBeforeAlarm;
        PrepareAlarm(1);
      }
    }
  }
  if (DoorFlag == 1) {
    if (DoorSensorLevel == 0 && DoorState == HIGH) {
      DoorFlag = 0;
      delay(100);
      LongBlinkBLed();
    }  else if (DoorSensorLevel == 1 && DoorState == LOW) {
      DoorFlag = 0;
      delay(100);
      LongBlinkBLed();
    }
  }
}

// ----- Проверка состояния датчика движения
void PIRDetect() {
  PIRState = digitalRead(PIRPin);
  //DelayBeforeAlarm = SecondDelayBeforeAlarm;
  if (PIRFlag == 0) {
    if (PIRSensorLevel == 0 && PIRState == LOW) {
      PIRFlag = 1;
      delay(100);
      if (guard == 1) {
        if (LedOn == 1) digitalWrite(GLed, LOW);
        SendSmsText = Warn + (F ("Second sensor!"));
        DelayBeforeAlarm = SecondDelayBeforeAlarm;
        PrepareAlarm(1);
      }
    }  else if (PIRSensorLevel == 1 && PIRState == HIGH) {
      PIRFlag = 1;
      delay(100);
      if (guard == 1) {
        if (LedOn == 1) digitalWrite(GLed, LOW);
        SendSmsText = Warn + (F ("Second sensor!"));
        DelayBeforeAlarm = SecondDelayBeforeAlarm;
        PrepareAlarm(1);
      }
    }
  }
  if (PIRFlag == 1) {
    if (PIRSensorLevel == 0 && PIRState == HIGH) {
      PIRFlag = 0;
      delay(100);
      LongBlinkBLed();
    }  else if (PIRSensorLevel == 1 && PIRState == LOW) {
      PIRFlag = 0;
      delay(100);
      LongBlinkBLed();
    }
  }
}
/* @@ void PIRDetect() {
  if (PIRSensorLevel != 2) {
    PIRState = digitalRead(PIRPin);
    if (PIRState == HIGH && PIRFlag == 0 && guard == 1) {
      PIRFlag = 1;
      delay(100);
      if (LedOn == 1) digitalWrite(GLed, LOW);
      SendSmsText = Warn + ( F ("PIR sensor!"));
      PrepareAlarm(0, 1);
    }

    if (PIRState == LOW && PIRFlag == 1) {
      PIRFlag = 0;
      delay(100);
      LongBlinkBLed();
    }
  }
  }
*/
// ----- Световая индикация GuardOn/GuardOff
void Led() {
  //TEST
  DoorState = digitalRead(DoorPin);
  PIRState = digitalRead(PIRPin);
  if (guard == 1 && ((DoorSensorLevel == 0 && DoorState == LOW) || (PIRSensorLevel == 0 && PIRState == LOW))) {
    digitalWrite(GLed, HIGH);
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis > interval) {
      previousMillis = currentMillis;
      if (RLedState == LOW)
        RLedState = HIGH;
      else
        RLedState = LOW;
      digitalWrite(RLed, RLedState);
    }
  }
//    if (guard == 1 && DoorState == HIGH && PIRState == HIGH) {
  if (guard == 1 && (DoorSensorLevel != 0 || DoorState == HIGH) && (PIRSensorLevel != 0 || PIRState == HIGH)) {
    //TEST
    digitalWrite(GLed, HIGH);
    digitalWrite(RLed, LOW);
  }
  if (guard == 0) {
    digitalWrite(RLed, HIGH);
    if (LedOn == 1) digitalWrite(GLed, LOW);
  }
}


// ----- Световая индикация TestOn/TestOff ???

void LedTest() {
  if (LedTestOn == 0) digitalWrite(BLed, HIGH);
  if (LedTestOn == 1) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis > interval) {
      previousMillis = currentMillis;
      if (BLedState == LOW)
        BLedState = HIGH;
      else
        BLedState = LOW;
      digitalWrite(BLed, BLedState);
    }
  }
}

// ----- Световая индикация успешного завершения команды
void LedOK() {
  digitalWrite(BLed, HIGH);
  delay(100);
  digitalWrite(BLed, LOW);
  delay(100);
  digitalWrite(BLed, HIGH);
}

// ----- Световая индикация завершения команды с ошибкой
void LedERROR() {
  for (uint8_t i = 0 ; i < 2 ; i++) {
    LedOK();
  }
}

// ----- Отключение "тревожного пина"
void AlarmPinOff() {
  unsigned long currentAlarmMillis = millis();
  //if ((currentAlarmMillis - previousAlarmMillis > AlarmInterval * 1000) || guard == 0) {//Orig!
  if (((currentAlarmMillis - previousAlarmMillis) / 1000 > AlarmInterval) || guard == 0) {
    digitalWrite(AlarmPin, LOW);
    digitalWrite(InverseAlarmPin, HIGH);
  }
}

// ----- Включение "тревожного пина"
void AlarmPinOn() {
  digitalWrite(AlarmPin, HIGH);
  digitalWrite(InverseAlarmPin, LOW);
  previousAlarmMillis = millis();
}

// ----- Предварительная обработка GuardOn/GuardOff
void MasterRing() {
  if (guard == 1) PrepareGuardOff(0);
  else if (guard == 0) PrepareDelayGuardOn(0);
}

// ----- Предварительная обработка DelayGuardOff
void PrepareGuardOff(uint8_t from_console) {
  if (from_console == 1) ConsoleEvent = 1;
  ActivateDelayBeforeGuard = 0;
  ActivateDelayBeforeAlarm = 0;
  GuardOff();//Orig
}

// ----- Предварительная обработка DelayGuardOn
void PrepareDelayGuardOn(uint8_t from_console) {
  if (from_console == 1) ConsoleEvent = 1;
  previousDelayBeforeGuardMillis = millis();
  ActivateDelayBeforeGuard = 1;
  DelayGuardOn();//Orig
}

// ----- Обработка DelayGuardOn
void DelayGuardOn() {
  if (ActivateDelayBeforeGuard == 1) {
    unsigned long currentDelayBeforeGuardMillis = millis();
    if ((currentDelayBeforeGuardMillis - previousDelayBeforeGuardMillis) / 1000 > DelayBeforeGuard) {
      GuardOn();
      ActivateDelayBeforeGuard = 0;
    }
  }
}

// ----- Обработка GuardOff
void GuardOff() {
  guard = 0;
  EEPROM.update(14, guard); //!!! Guard Off. вынести
  LastEvent = F ("Guard OFF.");
  lasteventprepare();
  Serial.println(LastEvent);
  SendSmsText = LastEvent;
  delay(1000);
  for (uint8_t i = 0; i < 10; i++) {
    if (EEPROM.read(data[i].addr + IAlarmOffset) == 1) {
      //      if (RingPhone == String(EEPROM.get(data[i].addr, PhoneNum))) sendsmscaller = 0;
      delay(1000);
      sms("+" + String(EEPROM.get(data[i].addr, PhoneNum)));
      delay(1000);
    }
  }
  /*  if (sendsmscaller == 1) {
      delay(1000);
      sms( F ("Guard OFF"), "+" + RingPhone, 0);
      delay(1000);
    }*/
  if (GuardButtonEnable == 2) {
    GuardButton5VFlag = 0;
    GuardButtonGNDFlag = 0;
  }
  guardeventoff();
}

// ----- Обработка GuardOn
void GuardOn() {
  guard = 1;
  EEPROM.update(14, guard);
  DoorFlag = 1;
  LastEvent = F ("Guard ON.");
  lasteventprepare();
  Serial.println(LastEvent);
  SendSmsText = LastEvent;
  delay(1000);
  for (uint8_t i = 0; i < 10; i++) {
    if (EEPROM.read(data[i].addr + IAlarmOffset) == 1) {
      //      if (RingPhone == String(EEPROM.get(data[i].addr, PhoneNum))) sendsmscaller = 0;
      delay(1000);
      sms("+" + String(EEPROM.get(data[i].addr, PhoneNum)));
      delay(1000);
    }
  }
  /*  if (sendsmscaller == 1) {
      delay(1000);
      sms( F ("Guard ON"), "+" + RingPhone, 0);
      delay(1000);
    }*/
  guardeventoff();
}

void lasteventprepare() {
  if (GuardButtonEvent == 1) LastEvent += F (" Button");
  else if (ConsoleEvent == 1) LastEvent += F (" Console");
  else {
    LastEvent += F (" Phone +");
    LastEvent += RingPhone;
  }
}

void guardeventoff() {
  GuardButtonEvent = 0;
  ConsoleEvent = 0;
}

// ----- Обработка команд
void MasterCommands() {
  if (ConsoleCommand == 1) Serial.println(val);
  val.replace("\r", "");
  val.replace("\n", "");
  val.toLowerCase();
  if (SuperUser == 1) {
    if ((val.indexOf( F ("addphone")) > -1)) {
      addphone(val, 1);
    }
    if ((val.indexOf( F ("deletephone")) > -1)) {
      deletephone(val);
    }
    if ((val.indexOf( F ("balancenum")) > -1)) {
      String SmsText = val.substring(String(val.lastIndexOf(":")).toInt() + 1);
      String SmsBalanceNum = SmsText.substring(0, String(SmsText.indexOf("l")).toInt());
      String SmsBalanceLen = val.substring(String(val.lastIndexOf("l")).toInt() + 1);
      eepromupdatebalancenum(SmsBalanceNum, SmsBalanceLen.toInt());
    }
    if ((val.indexOf( F ("sleeptime")) > -1)) {
      String SmsText = val.substring(String(val.lastIndexOf(":")).toInt() + 1);
      String SmsPauseTime = SmsText;
      if (SmsPauseTime.toInt() < 1 || SmsPauseTime.toInt() > 60 ) SmsPauseTime = String(PauseTime);
      eepromupdatepausetime(SmsPauseTime.toInt());
    }
    if ((val.indexOf( F ("delaybeforeguard")) > -1)) {
      String SmsText = val.substring(String(val.lastIndexOf(":")).toInt() + 1);
      String SmsDelayBeforeGuard = SmsText;
      if (SmsDelayBeforeGuard.toInt() < 0 || SmsDelayBeforeGuard.toInt() > 255 ) SmsDelayBeforeGuard = String(DelayBeforeGuard);
      eepromupdatedelaybeforeguard(SmsDelayBeforeGuard.toInt());
    }
    if ((val.indexOf( F ("delaybeforealarm")) > -1)) {
      uint8_t ms = 0;
      if ((val.indexOf( F ("main")) > -1)) ms = 1;
      if ((val.indexOf( F ("second")) > -1))ms = 2;
      if ((val.indexOf( F ("pcf")) > -1))ms = 3;
      String SmsText = val.substring(String(val.lastIndexOf(":")).toInt() + 1);
      String SmsDelayBeforeAlarm = SmsText;
      if (SmsDelayBeforeAlarm.toInt() < 0 || SmsDelayBeforeAlarm.toInt() > 255 ) SmsDelayBeforeAlarm = String(DelayBeforeAlarm);
      eepromupdatedelaybeforealarm(SmsDelayBeforeAlarm.toInt(), ms);
    }
    if ((val.indexOf( F ("watchpowertime")) > -1)) {
      String SmsText = val.substring(String(val.lastIndexOf(":")).toInt() + 1);
      String SmsWatchPowerTime = SmsText;
      if (SmsWatchPowerTime.toInt() < 0 || SmsWatchPowerTime.toInt() > 255 ) SmsWatchPowerTime = String(WatchPowerTime);
      eepromupdatewatchpowertime(SmsWatchPowerTime.toInt());
    }
    if ((val.indexOf( F ("ringtime")) > -1)) {
      String SmsText = val.substring(String(val.lastIndexOf(":")).toInt() + 1);
      String SmsRingTime = SmsText;
      if (SmsRingTime.toInt() < 10 || SmsRingTime.toInt() > 255 ) SmsRingTime = String(RingTime);
      eepromupdateringtime(SmsRingTime.toInt());
    }
    if ((val.indexOf( F ("alarmpintime")) > -1)) {
      String SmsText = val.substring(String(val.lastIndexOf(":")).toInt() + 1);
      String SmsAlarmPinTime = SmsText;
      if (SmsAlarmPinTime.toInt() < 1 || SmsAlarmPinTime.toInt() > 43200 ) SmsAlarmPinTime = String(AlarmInterval);
      eepromupdatealarmpintime(SmsAlarmPinTime.toInt());
    }
    if ((val.indexOf( F ("fullreset")) > -1)) {
      EEPROM.update(0, 255);
      eepromconfig();
      EEPROM.update(99, 255);
      eepromphonememory();
      EEPROM.update(30 + BalanceSettingsOffset, 255);
      eeprombalancenum();
      LedOK();
      Reset();
    }
    if ((val.indexOf( F ("resetphone")) > -1)) {
      EEPROM.update(99, 255);
      eepromphonememory();
      LedOK();
      Reset();
    }
    if ((val.indexOf( F ("resetconfig")) > -1)) {
      EEPROM.update(0, 255);
      eepromconfig();
      LedOK();
      Reset();
    }
    if ((val.indexOf( F ("resetsensor")) > -1)) {
      EEPROM.update(98, 255);
      eepromsensormemory();
      LedOK();
      Reset();
    }

    /*
        if ((val.indexOf( F ("reedswitchon")) > -1)) {
          ReedSwitchGuard = 1;
          EEPROM.update(11, ReedSwitchGuard);
          SendSmsText = F ("Reed Switch ON");
          if (SMSCommand == 1) sms("+" + RingPhone, 0);
        }
        if ((val.indexOf( F ("reedswitchoff")) > -1)) {
          ReedSwitchGuard = 0;
          EEPROM.update(11, ReedSwitchGuard);
          SendSmsText = F ("Reed Switch OFF");
          if (SMSCommand == 1) sms("+" + RingPhone, 0);
        }
    */

    /*@@   if ((val.indexOf( F ("reedswitcho")) > -1)) {
          SendSmsText = F ("Reed Switch O");
          if ((val.indexOf("n") > -1)) {
            ReedSwitchGuard = 1;
            //EEPROM.update(11, ReedSwitchGuard);
            SendSmsText +=  "N";
            //if (SMSCommand == 1) sms("+" + RingPhone, 0);
          }
          else {
            ReedSwitchGuard = 0;
            //EEPROM.update(11, ReedSwitchGuard);
            SendSmsText +=  "FF";
            //if (SMSCommand == 1) sms("+" + RingPhone, 0);
          }
          EEPROM.update(11, ReedSwitchGuard);
          if (SMSCommand == 1) sms("+" + RingPhone, 0);
        }
    */

    /*
        if ((val.indexOf( F ("smson")) > -1)) {
          sendsms = 1;
          EEPROM.update(10, sendsms);
          SendSmsText = F ("Sms ON");
          if (SMSCommand == 1) sms("+" + RingPhone, 0);
        }
        if ((val.indexOf( F ("smsoff")) > -1)) {
          SendSmsText = F ("Sms OFF");
          if (SMSCommand == 1) sms("+" + RingPhone, 0);
          sendsms = 0;
          EEPROM.update(10, sendsms);
        }
    */
    /*
        if ((val.indexOf( F ("smso")) > -1)) {
          SendSmsText = F ("Sms O");
          if ((val.indexOf("n") > -1)) {
            sendsms = 1;
            //EEPROM.update(10, sendsms);
            SendSmsText +=  "N";
            if (SMSCommand == 1) sms("+" + RingPhone, 0);
          }
          else {
            SendSmsText +=  "FF";
            if (SMSCommand == 1) sms("+" + RingPhone, 0);
            sendsms = 0;
            //EEPROM.update(10, sendsms);
          }
          EEPROM.update(10, sendsms);
        }*/
    /*
        if ((val.indexOf( F ("piron")) > -1)) {
          PIRGuard = 1;
          EEPROM.update(18, PIRGuard);
          SendSmsText = F ("PIR ON");
          if (SMSCommand == 1) sms("+" + RingPhone, 0);
        }
        if ((val.indexOf( F ("piroff")) > -1)) {
          PIRGuard = 0;
          EEPROM.update(18, PIRGuard);
          SendSmsText = F ("PIR OFF");
          if (SMSCommand == 1) sms("+" + RingPhone, 0);
        }
    */
    /*@@    if ((val.indexOf( F ("piro")) > -1)) {
          SendSmsText = F ("PIR O");
          if ((val.indexOf( "n") > -1)) {
            PIRGuard = 1;
            //EEPROM.update(18, PIRGuard);
            SendSmsText +=  "N";
            //if (SMSCommand == 1) sms("+" + RingPhone, 0);
          }
          else {
            PIRGuard = 0;
            //EEPROM.update(18, PIRGuard);
            SendSmsText +=  "FF";
            //if (SMSCommand == 1) sms("+" + RingPhone, 0);
          }
          EEPROM.update(18, PIRGuard);
          if (SMSCommand == 1) sms("+" + RingPhone, 0);
        }
    */

    /*

        if ((val.indexOf( F ("watchpoweron1")) > -1)) {
          WatchPowerOn(SMSCommand, 1);
        }
        if ((val.indexOf( F ("watchpoweron2")) > -1)) {
          WatchPowerOn(SMSCommand, 2);
        }
        if ((val.indexOf( F ("watchpoweroff")) > -1)) {
          WatchPowerOff(SMSCommand);
        }
    */
    if ((val.indexOf( F ("watchpowero")) > -1)) {
      SendSmsText =  F ("Watch the power O");
      if ((val.indexOf( F ("n1")) > -1)) {

        //WatchPowerOn(SMSCommand, 1);
        WatchPower = 1;
        //EEPROM.update(19, WatchPower);
        Serial.print( F ("1"));
        SendSmsText +=   "N";
        //if (SMSCommand == 1) sms("+" + RingPhone, 0);
      }
      else if ((val.indexOf( F ("n2")) > -1)) {
        //WatchPowerOn(SMSCommand, 2);
        WatchPower = 2;
        //EEPROM.update(19, WatchPower);
        Serial.print( F ("2"));
        SendSmsText +=   "N";
        //if (SMSCommand == 1) sms("+" + RingPhone, 0);
      }
      else {
        //WatchPowerOff(SMSCommand);
        WatchPower = 0;
        //EEPROM.update(19, WatchPower);
        Serial.print( F ("3"));
        SendSmsText +=  "FF";
        //if (SMSCommand == 1) sms("+" + RingPhone, 0);
      }
      EEPROM.update(19, WatchPower);
      if (SMSCommand == 1) sms("+" + RingPhone);
    }

    /*
        if ((val.indexOf( F ("guardbuttonon1")) > -1)) {
          GuardButtonOnOff(SMSCommand);
        }
        if ((val.indexOf( F ("guardbuttonon2")) > -1)) {
          GuardButtonOnlyOn(SMSCommand);
        }
        if ((val.indexOf( F ("guardbuttonoff")) > -1)) {
          GuardButtonOff(SMSCommand);
        }
    */
    if ((val.indexOf( F ("guardbuttono")) > -1)) {
      SendSmsText =  F ("Guard button: ");
      if ((val.indexOf( F ("n1")) > -1)) {
        //GuardButtonOnOff(SMSCommand);
        GuardButtonEnable = 1;
        //EEPROM.update(20, GuardButtonEnable);
        SendSmsText +=  F ("ON/OFF mode");
        //if (SMSCommand == 1) sms("+" + RingPhone, 0);
      }
      else if ((val.indexOf( F ("n2")) > -1)) {
        //GuardButtonOnlyOn(SMSCommand);
        GuardButtonEnable = 2;
        //EEPROM.update(20, GuardButtonEnable);
        SendSmsText += F ("ON mode");
        //if (SMSCommand == 1) sms("+" + RingPhone, 0);
      }
      else {
        //GuardButtonOff(SMSCommand);
        GuardButtonEnable = 0;
        //EEPROM.update(20, GuardButtonEnable);
        SendSmsText += F ("Disabled");
        //if (SMSCommand == 1) sms("+" + RingPhone, 0);
      }
      EEPROM.update(20, GuardButtonEnable);
      if (SMSCommand == 1) sms("+" + RingPhone);
    }


    if ((val.indexOf( F ("editsensor")) > -1)) {
      editsensor(val);
    }
    if ((val.indexOf( F ("editmainphone")) > -1)) {
      addphone(val, 2);
    }
    if ((val.indexOf( F ("listconfig")) > -1)) {
      eepromconfig();
      eeprombalancenum();
    }
    if ((val.indexOf( F ("listsensor")) > -1)) {
      listsensor();
    }
    if ((val.indexOf( F ("memtest")) > -1)) {
      memtest();
    }
    if ((val.indexOf( F ("i2cscan")) > -1)) {
      i2cscan();
    }
    if ((val.indexOf( F ("listphone")) > -1)) {
      listphone();
    }
    if ((val.indexOf( F ("reboot")) > -1)) {
      delay(500);
      Reset();
    }
    if ((val.indexOf( F ("modemid")) > -1)) {
      String Text = val.substring(String(val.lastIndexOf(":")).toInt() + 1);
      if (Text.toInt() < 0 || Text.toInt() > 10 ) Text = ModemID;
      setupmodemid(Text.toInt());
    }
    if ((val.indexOf( F ("extdevicelevel")) > -1)) {
      if ((val.indexOf( F ("low")) > -1)) {
        EEPROM.update(26, 0);
      }
      //      if ((val.indexOf( F ("high")) > -1)) {
      else {
        EEPROM.update(26, 1);
      }
      delay(500);
      Reset();
    }
    if ((val.indexOf( F ("extdevicetime")) > -1)) {
      String SmsText = val.substring(String(val.lastIndexOf(":")).toInt() + 1);
      String SmsExternalDeviceTime = SmsText;
      if (SmsExternalDeviceTime.toInt() < 0 || SmsExternalDeviceTime.toInt() > 255 ) SmsExternalDeviceTime = String(ExternalDeviceTime);
      //eepromupdateringtime(SmsExternalDeviceTime.toInt());
      EEPROM.update(27, SmsExternalDeviceTime.toInt());
      ExternalDeviceTime = SmsExternalDeviceTime.toInt();
      Serial.print( F ("ExtDeviceTime is: "));
      Serial.println(EEPROM.read(27));
      lineprint();
      LedOK();
    }





    /*      SendSmsText = F ("Sms OFF");
          if (SMSCommand == 1) sms("+" + RingPhone, 0);
          sendsms = 0;
          EEPROM.update(10, sendsms);

              ExternalDeviceLevel = EEPROM.read(26);
        Serial.print( F ("ExtlDeviceLevel: "));
        Serial.println(ExternalDeviceLevel);

        ExternalDeviceTime

    */

    if ((val.indexOf( F ("mainsensorlevel")) > -1)) {
      if ((val.indexOf( F ("high")) > -1)) {
        EEPROM.update(6, 1);
      }
      else if ((val.indexOf( F ("low")) > -1)) {
        EEPROM.update(6, 0);
      }
      else EEPROM.update(6, 2);
      delay(500);
      Reset();
    }

    if ((val.indexOf( F ("secondsensorlevel")) > -1)) {
      if ((val.indexOf( F ("high")) > -1)) {
        EEPROM.update(8, 1);
      }
      else if ((val.indexOf( F ("low")) > -1)) {
        EEPROM.update(8, 0);
      } else EEPROM.update(8, 2);
      delay(500);
      Reset();
    }

    if ((val.indexOf( F ("pcfforceo")) > -1)) {
      if ((val.indexOf("n") > -1)) {
        PCFForce = 1;
      }
      else {
        PCFForce = 0;
      }
      EEPROM.update(28, PCFForce);
    }
    SuperUser = 0;
  }
  if ((val.indexOf( F ("info")) > -1)) {
    //    SendSmsText =  F("Info: PIR O");
    //SendSmsText =  F("Info: ");
    //    if (PIRSensorLevel == 0) SendSmsText += "FF";
    //    else SendSmsText += "N";
    //    SendSmsText +=  F(". ");
    //Serial.println(SendSmsText);
    //Serial.println(LastEvent);
    SendSmsText = LastEvent;
    //Serial.println(SendSmsText);
    delay(2000);
    //SendSmsText = smstext;
    if (SMSCommand == 1) sms("+" + RingPhone);
    if (ConsoleCommand == 1) Serial.println(SendSmsText);
  }
  if ((val.indexOf( F ("money")) > -1)) {
    balance(ConsoleCommand);
  }
  if ((val.indexOf( F ("pause")) > -1)) {
    //if (SMSCommand == 1) sms("Pause " + String(PauseTime) + " min", "+" + RingPhone, 1);
    digitalWrite(BLed, LOW);
    delay(PauseTime * 60000);
    digitalWrite(BLed, HIGH);
  }

  if ((val.indexOf( F ("guardon")) > -1)) {
    PrepareDelayGuardOn(ConsoleCommand);
  }
  if ((val.indexOf( F ("guardoff")) > -1)) {
    PrepareGuardOff(ConsoleCommand);
  }

  /*
    if ((val.indexOf( F ("teston")) > -1)) {
      LedTestOn = 1;
      EEPROM.update(12, LedTestOn);
      InitModem();
    }
    if ((val.indexOf( F ("testoff")) > -1)) {
      LedTestOn = 0;
      EEPROM.update(12, LedTestOn);
      digitalWrite(BLed, HIGH);
      InitModem();
    }
  */
  if ((val.indexOf( F ("testo")) > -1)) {
    if ((val.indexOf("n") > -1)) {
      LedTestOn = 1;
    }
    else {
      LedTestOn = 0;
      //EEPROM.update(12, LedTestOn);
      digitalWrite(BLed, HIGH);
      //InitModem();
    }
    EEPROM.update(12, LedTestOn);
    InitModem();
  }


  /*
    if ((val.indexOf( F ("ledon")) > -1)) {
      LedOn = 1;
      EEPROM.update(13, LedOn);
      digitalWrite(GLed, LOW);
    }
    if ((val.indexOf( F ("ledoff")) > -1)) {
      LedOn = 0;
      EEPROM.update(13, LedOn);
      digitalWrite(GLed, HIGH);
    }
  */
  if ((val.indexOf( F ("ledo")) > -1)) {
    if ((val.indexOf("n") > -1)) {
      LedOn = 1;
      //EEPROM.update(13, LedOn);
      digitalWrite(GLed, LOW);
    }
    else {
      LedOn = 0;
      //EEPROM.update(13, LedOn);
      digitalWrite(GLed, HIGH);
    }
    EEPROM.update(13, LedOn);
  }

  if ((val.indexOf( F ("clearsms")) > -1)) {
    clearsms();
  }

  if ((val.indexOf( F ("open")) > -1)) {
    if (ExternalDeviceLevel == 1) {
      digitalWrite(ExternalDevicePin, HIGH);
      delay(ExternalDeviceTime * 1000);
      digitalWrite(ExternalDevicePin, LOW);
    }
    else {
      digitalWrite(ExternalDevicePin, LOW);
      delay(ExternalDeviceTime * 1000);
      digitalWrite(ExternalDevicePin, HIGH);
    };
  }

  //if ((val.indexOf( F ("mytest")) > -1)) {
  //}
  SMSCommand = 0;
  ConsoleCommand = 0;
}
/*
  // ----- Обработка команд WatchPowerOn 1
  void WatchPowerOn(uint8_t sms_enable, uint8_t mode) {
  WatchPower = mode;
  EEPROM.update(19, WatchPower);
  SendSmsText =  F ("Watch the power ON");
  if (sms_enable == 1 && SMSCommand == 1) sms("+" + RingPhone, 0);
  }
  // ----- Обработка команд WatchPowerOff
  void WatchPowerOff(uint8_t sms_enable) {
  WatchPower = 0;
  EEPROM.update(19, WatchPower);
  SendSmsText = F ("Watch the power OFF");
  if (sms_enable == 1 && SMSCommand == 1) sms("+" + RingPhone, 0);
  }
*/
/*
  // ----- Обработка команд GuardButtonOn/Off
  void GuardButtonOnOff(uint8_t sms_enable) {
  GuardButtonEnable = 1;
  EEPROM.update(20, GuardButtonEnable);
  SendSmsText =  F ("Guard button: ON/OFF mode");
  if (sms_enable == 1 && SMSCommand == 1) sms("+" + RingPhone, 0);
  }
*/
/*
  // ----- Обработка команд GuardButtonOnlyOn
  void GuardButtonOnlyOn(uint8_t sms_enable) {
  GuardButtonEnable = 2;
  EEPROM.update(20, GuardButtonEnable);
  SendSmsText = F ("Guard button: ON mode");
  if (sms_enable == 1 && SMSCommand == 1) sms("+" + RingPhone, 0);
  }
*/
/*
  // ----- Обработка команд GuardButtonOff
  void GuardButtonOff(uint8_t sms_enable) {
  GuardButtonEnable = 0;
  EEPROM.update(20, GuardButtonEnable);
  SendSmsText = F ("Guard button OFF");
  if (sms_enable == 1 && SMSCommand == 1) sms("+" + RingPhone, 0);
  }
*/
// ----- Обработка команд добавления телефона
void addphone (String val, uint8_t from_event) {
  String Text = val.substring(String(val.lastIndexOf(":")).toInt() + 1);
  //uint8_t M = 0;
  uint8_t S = 0;
  uint8_t R = 0;
  uint8_t P = 0;
  uint8_t I = 0;
  //if (Text.indexOf("m") > -1) M = 1;
  if (Text.indexOf("s") > -1) S = 1;
  if (Text.indexOf("r") > -1) R = 1;
  if (Text.indexOf("p") > -1) P = 1;
  if (Text.indexOf("i") > -1) I = 1;
  //Text.replace("m", "");
  Text.replace("s", "");
  Text.replace("r", "");
  Text.replace("p", "");
  Text.replace("i", "");
  Text.replace("(sp)", "");
  String Cell = Text.substring(0, String(Text.indexOf("+")).toInt());
  String AddPhoneNumber = Text.substring(String(Text.lastIndexOf("+")).toInt() + 1);
  if (from_event == 1) eepromaddphone(AddPhoneNumber, Cell.toInt(), S, R, P, I);
  if (from_event == 2) editmainphone(S, R, P, I);
}

// ----- Обработка команд удаления телефона
void deletephone (String val) {
  String Text = val.substring(String(val.lastIndexOf(":")).toInt() + 1);
  Text.replace( "(sp)", "");
  String SmsDeletePhoneNumber = Text.substring(String(Text.lastIndexOf("+")).toInt() + 1);
  eepromdeletephone(SmsDeletePhoneNumber);
}

// ----- Изменение параметров основного номера
void editmainphone (uint8_t S, uint8_t R, uint8_t P, uint8_t I) {
  EEPROM.update(data[0].addr + SAlarmOffset, S);
  EEPROM.update(data[0].addr + RAlarmOffset, R);
  EEPROM.update(data[0].addr + PAlarmOffset, P);
  EEPROM.update(data[0].addr + IAlarmOffset, I);
  Serial.println( F ("Phone settings changed."));
  lineprint();
  LedOK();
  //listphone();
}

// ----- Тестирование памяти EEPROM
void memtest() {
  uint8_t x;
  x = random(2, 255);
  Serial.print( F ("EEPROM: "));
  Serial.print(EEPROM.length());
  Serial.println( F ("B"));
  for (uint16_t i = 0 ; i < EEPROM.length() ; i++) {
    EEPROM.write(i, x);
    delay(5);
  }
  uint16_t y;
  y = 0;
  for (uint16_t i = 0 ; i < EEPROM.length() ; i++) {
    if (EEPROM.read(i) != x) {
      //lineprint();
      Serial.print( F ("Failed cell: "));
      Serial.println(i + Marker + EEPROM.read(i));
      y++;
    }
    delay(5);
  }
  Serial.print( F ("Test "));
  if (y == 0) {
    Serial.println( F ("passed."));
    lineprint();
    delay(500);
    Reset();
  }
  if (y != 0) Serial.println( F ("failed."));
}

// ----- Принудительная установка ID модема.
void setupmodemid (uint8_t id) {
  Serial.print( F ("Previous ID: "));
  Serial.println(ModemID);
  EEPROM.update(25, id);
  ModemID = id;
  Serial.print( F ("Current ID: "));
  Serial.print(ModemID);
  Serial.print( F (". Modem: "));
  if (id == 0) {
    Serial.println( F ("Autodetect."));
    Serial.println( F ("Reboot."));
    delay(500);
    Reset();
  } else if (id == 1) {
    Serial.println( F ("M590e."));
  } else if (id == 2) {
    Serial.println( F ("SIM800L."));
  } else if (id == 3) {
    Serial.println( F ("A6."));
  } else {
    Serial.println( F ("Not use."));
  }
  lineprint();
}

// ----- Команды запроса баланса
void balance(uint8_t from_console) {
  if (from_console == 1) ConsoleEvent = 1;
  delay(1000);
  mySerial.print(F("AT+CUSD=1,\""));
  mySerial.print(BalanceNumber);
  mySerial.println("\",15");
}


// ----- Удаление SMS
void clearsms() {
  mySerial.print ( F ("AT+CMGD="));
  if (ModemID == 1) mySerial.println( F ("0,4"));
  if (ModemID == 2 || ModemID == 3) mySerial.println( F ("4"));
  //delay(2000);
  Serial.println( F ("SMS removed"));
  LedOK();
}

// ----- Новая строка в консоли
void lineprint() {
  Serial.println();
}

// ----- Сканер I2C устройств

void i2cscan() {
  byte error, i2caddress;
  uint8_t nDevices;

  nDevices = 0;
  for (i2caddress = 1; i2caddress < 127; i2caddress++ ) {
    Wire.beginTransmission(i2caddress);
    error = Wire.endTransmission();
    if (error == 0) {
      Serial.print( F ("I2C device at 0x"));
      if (i2caddress < 16)
        Serial.print( F ("0"));
      Serial.print(i2caddress, HEX);
      //20 hex = 32 dec; 27 hex = 39 dec
      if ((31 < i2caddress && i2caddress < 40) || (55 < i2caddress && i2caddress < 64)) {
        Serial.print(Marker);
        Serial.println( F ("detected PCF8574"));//???
        PCFAddress = i2caddress;
        //Serial.println(PCFAddress);
        //expanderWrite(B00010000);
        PCFDeices++;
      }
      else lineprint();
      nDevices++;
    }
    else if (error == 4) {
      Serial.print( F ("Error at 0x"));
      if (i2caddress < 16)
        Serial.print(F ("0"));
      Serial.println(i2caddress, HEX);
    }
  }
  if (nDevices == 0)
    Serial.println( F ("I2C devices not found"));
  if (PCFDeices != 0) {
    listsensor();
    lorhreadconfig();
    LorHCurrentFlagZero();
  }
}

void expanderWrite(byte _data) {
  Wire.beginTransmission(PCFAddress);
  Wire.write(_data);
  Wire.endTransmission();
}

byte expanderRead() {
  byte _data;
  Wire.requestFrom(PCFAddress, 1, true);
  if (Wire.available()) {
    _data = Wire.read();
  }
  return _data;
}

// ----- Инициализация памяти датчиков
void eepromsensormemory() {
  if (EEPROM.read(98) != 1) {        //Сюда код начальной инициализации памяти датчиков.
    Serial.println( F ("Deleting sensor data."));
    for (uint16_t i = 500 ; i <= 820 ; i++) {
      EEPROM.update(i, 255);
      delay(10);
    }
    Serial.println( F ("Load default sensor data."));
    lineprint();
    for ( uint8_t i = 0; i < 8; i++ ) {
      EEPROM.put(SensorData[i].SensorAddr, SensorData[i].SensorName);
      EEPROM.update(SensorData[i].SensorAddr + LoworHighOffset, SensorData[i].LoworHigh);
    }
    EEPROM.update(98, 1);
  }

  //Ниже только для отладки, пока не вижу смысла читать данные в массив.
  //if (EEPROM.read(98) == 1) {
  //Сюда код чтения из памяти телефонных номеров.
  //listsensor();
  //}
}

void listsensor() {
  Serial.println( F ("Sensor data:"));
  for ( uint8_t i = 0; i < 8; i++ ) {
    EEPROM.get(SensorData[i].SensorAddr, SensorName);
    //Serial.println(String(String(i + 1) + Marker + SensorName + Marker + EEPROM.read(SensorData[i].SensorAddr + LoworHighOffset)));//Orig
    Serial.println(i + 1 + Marker + SensorName + Marker + EEPROM.read(SensorData[i].SensorAddr + LoworHighOffset));
  }
  lineprint();
}

// ----- Переименование датчика
void eepromeditsensor(String EditSensorName, uint8_t SensorNumber, uint8_t LorH ) {
  uint8_t editsensor = 1;
  SensorNumber -= 1;
  if (SensorNumber < 0 || SensorNumber >= 8)  {
    Serial.println( F ("Error sensor number"));
    LedERROR();
    editsensor = 0;
  }
  if (editsensor == 1) {
    EditSensorName.toCharArray(SensorNameCharArray, 38);
    EEPROM.put(SensorData[SensorNumber].SensorAddr, SensorNameCharArray);
    EEPROM.update(SensorData[SensorNumber].SensorAddr + LoworHighOffset, LorH);
    Serial.println( F ("Sensor data saved."));
    LedOK();
  }
  lineprint();
  listsensor();
}

// ----- Обработка команды изменения значений сенсора
void editsensor (String val) {
  String Text = val.substring(String(val.lastIndexOf(":")).toInt() + 1);
  uint8_t SmsHoL = 0;
  //Serial.println(SmsText);
  if (Text.indexOf("#h") > -1) SmsHoL = 1;
  Text.replace("#h", "");
  //Text.replace("(sp)", "");
  //Text.replace("\r", "");
  //Text.replace("\n", "");
  String SmsCell = Text.substring(0, String(Text.indexOf("+")).toInt());
  String SmsEditSensorName = Text.substring(String(Text.lastIndexOf("+")).toInt() + 1);
  eepromeditsensor(SmsEditSensorName, SmsCell.toInt(), SmsHoL);
}

// ----- Читаем работу логики датчиков в массив LorHConfig
void lorhreadconfig() {
  for (uint8_t i = 0; i < 8; i++) {
    LorHConfig[i] = EEPROM.read(SensorData[i].SensorAddr + LoworHighOffset);
    //Serial.print(LorHConfig[i]);
  }
  lineprint();
}

// ----- Забиваем массив LorHCurrentFlag нулями
void LorHCurrentFlagZero () {
  for (uint8_t i = 0; i < 8; i++) {
    LorHCurrentFlag[i] = 0;
  }
}

// ----- Читаем текущее состоние датчиков в массив LorHCurrent и сравниваем с LorHConfig
void LorHCompare() {
  if (PCFDeices > 0 && (guard == 1 || PCFForce == 1)) {
    uint8_t LorHCurrent[8];
    for (uint8_t i = 0; i < 8; i++) {
      LorHCurrent[i] = bitRead(expanderRead(), i);
      if (LorHConfig[i] == LorHCurrent[i] && LorHCurrentFlag[i] == 0) {
        LorHCurrentFlag[i] = 1;
        delay(100);
        if (LedOn == 1) digitalWrite(GLed, LOW);
        EEPROM.get(SensorData[i].SensorAddr, SensorName);
        //Alarm(String(Warn + String (SensorName)), 1);//Orig
        //AlarmPinOn();
        SendSmsText = Warn + SensorName;
        DelayBeforeAlarm = EEPROM.read(22);
        PrepareAlarm(1);
      }
      if (LorHConfig[i] != LorHCurrent[i] && LorHCurrentFlag[i] == 1) {
        LorHCurrentFlag[i] = 0;
        delay(100);
      }
    }
  }
}
/*
  unsigned long previousWatchPowerTimeMillis = 0;
  uint8_t ActivateWatchPowerTime = 0;
  uint8_t WatchPowerTime = 0; //Задержка времени перед отправкой смс при отключении сети питания
*/

//void PrepareAlarm(uint8_t sms_force, uint8_t from_event) {
void PrepareAlarm(uint8_t from_event) {
  if (ActivateDelayBeforeAlarm == 0) previousDelayBeforeAlarmMillis = millis();
  ActivateDelayBeforeAlarm = 1;
  //PrepareAlarmText = text;
  //  PrepareAlarmSMSForce = sms_force;
  PrepareAlarmFromEvent = from_event;
}

//void PrepareWatchPowerTimeAlarm(uint8_t sms_force, uint8_t from_event) {
void PrepareWatchPowerTimeAlarm(uint8_t from_event) {
  if (ActivateWatchPowerTime == 0) previousWatchPowerTimeMillis = millis();
  ActivateWatchPowerTime = 1;
  //  PrepareAlarmText = text;
  //  PrepareAlarmSMSForce = sms_force;
  PrepareAlarmFromEvent = from_event;
}

void DelayAlarm() {
  if (ActivateDelayBeforeAlarm == 1) {
    unsigned long currentDelayBeforeAlarmMillis = millis();
    if ((currentDelayBeforeAlarmMillis - previousDelayBeforeAlarmMillis) / 1000 > DelayBeforeAlarm) {
      AlarmPinOn();
      //SendSmsText = PrepareAlarmText;
      //      SmsAlarm(PrepareAlarmSMSForce, PrepareAlarmFromEvent);
      SmsAlarm(PrepareAlarmFromEvent);
      ActivateDelayBeforeAlarm = 0;
    }
  }
  if (ActivateWatchPowerTime == 1) {
    unsigned long currentWatchPowerTimeMillis = millis();
    if ((currentWatchPowerTimeMillis - previousWatchPowerTimeMillis) / 1000 > WatchPowerTime * 60) {
      if (WatchPowerTime != 0) {
        SendSmsText += WatchPowerTime;
        SendSmsText += F(" minutes ago");
      }
      //SendSmsText = PrepareAlarmText;
      //      SmsAlarm(PrepareAlarmSMSForce, PrepareAlarmFromEvent);
      SmsAlarm(PrepareAlarmFromEvent);
      WatchPowerTimeSmsSended = 1;
      ActivateWatchPowerTime = 0;
    }
  }
}

// ----- Отправка тревожной смс и инициализация тревожного звонка
//void SmsAlarm(uint8_t sms_force, uint8_t from_event) {
void SmsAlarm(uint8_t from_event) {
  if (guard == 1) {
    //    Serial.println(text);
    for (uint8_t i = 0; i < 10; i++) {
      if (from_event == 1) {
        if (EEPROM.read(data[i].addr + SAlarmOffset) == 1) {
          sms("+" + String(EEPROM.get(data[i].addr, PhoneNum)));
          delay(1000);
        }
      }
      if (from_event == 2) {
        if (EEPROM.read(data[i].addr + PAlarmOffset) == 1) {
          sms("+" + String(EEPROM.get(data[i].addr, PhoneNum)));
          delay(1000);
        }
      }
    }
    //    if (from_event == 1 && AlarmRing == 1) {//Orig
    if (from_event == 1) {
      //RingAlarm();//ORIG
      //previousCallTimeMillis =  millis();
      CallFlag = 1;
      //CallNum = 0;
      Call = 1;
    }
  }
}
/*
  // ----- Тревожный звонок
  void RingAlarm() {
  for (uint8_t i = 0; i < 10; i++) {
    if (EEPROM.read(data[i].addr + RAlarmOffset) == 1) {
      delay(5000);
      Serial.print(F("Alarm Ring: +"));
      Serial.println(EEPROM.get(data[i].addr, PhoneNum));
      mySerial.print( F ("ATD+"));
      mySerial.print(EEPROM.get(data[i].addr, PhoneNum));
      mySerial.println( F (";"));
      //Serial.println(RingTime * 1000);
      delay(RingTime * 1000);
      endcall();
    }
  }
  }
*/
// ----- Завершение вызова
void endcall() {
  delay(2000);
  mySerial.println( F ("AT+CHUP"));
  //Serial.println( F ("EndCall"));
  EndCallFlag = 0;
}

// ----- Обработка тревожных звонков
void AlarmCall() {
  if (EndCallFlag == 1) endcall();
  if (Call == 1) {
    if (EEPROM.read(data[CallNum].addr + RAlarmOffset) == 1) {
      previousCallTimeMillis =  millis();
      delay(5000);
      Serial.print(F("Alarm Ring: +"));
      Serial.println(EEPROM.get(data[CallNum].addr, PhoneNum));
      mySerial.print( F ("ATD+"));
      mySerial.print(EEPROM.get(data[CallNum].addr, PhoneNum));
      mySerial.println( F (";"));
      Call = 0;
    }
  }

  if (CallFlag == 1) {
    unsigned long currentCallTimeMillis = millis();
    if ((currentCallTimeMillis - previousCallTimeMillis) / 1000 > RingTime) {
      //Serial.println((currentCallTimeMillis - previousCallTimeMillis) / 1000);
      //endcall();
      EndCallFlag = 1;
      CallNum++;
      //Serial.println(CallNum);
      Call = 1;
    }
  }

  if ((CallNum > 10) || (guard == 0 && CallFlag == 1)) {
    //endcall();
    CallFlag = 0;
    EndCallFlag = 1;
    CallNum = 0;
    Call = 0;
  }
}

// ----- Отправка SMS - сообщений
//void sms(String phone, uint8_t force) {  //Процедура отправки СМС
void sms(String phone) {  //Процедура отправки СМС
  //  if (sendsms == 1 || force == 1 ) {
  //  if (force == 1 ) { //Удалить
  delay(1000);
  mySerial.print( F ("AT+CMGS=\""));
  mySerial.print(phone);
  mySerial.println( F ("\""));
  delay(500);
  mySerial.print(SendSmsText);
  delay(500);
  mySerial.print((char)26);
  delay(500);
  Serial.print("Sent! ");
  //delay(5000);
  //  } else {
  //    Serial.print("NOT Sent! ");
  //  }
  Serial.print(phone);
  Serial.print(Marker);
  //  Serial.println(text);
  Serial.println(SendSmsText);
  delay(5000);
}
