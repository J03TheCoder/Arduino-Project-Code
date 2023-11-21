
#include <Wire.h>
#include <DS3231.h>
#include <LiquidCrystal.h>

DS3231 clock;
RTCDateTime dt;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup()
{
  Serial.begin(9600);

  Serial.println("Initialize RTC module");
  // Initialize DS3231
  clock.begin();
  lcd.begin(16, 2);
  // Print a message to the LCD.


  
  // Manual (YYYY, MM, DD, HH, II, SS
  // clock.setDateTime(2016, 12, 9, 11, 46, 00);
  
  // Send sketch compiling time to Arduino
  clock.setDateTime(__DATE__, __TIME__);    
  /*
  Tips:This command will be executed every time when Arduino restarts. 
       Comment this line out to store the memory of DS3231 module
  */
}

void loop()
{
  lcd.clear();
  dt = clock.getDateTime();

  // For leading zero look to DS3231_dateformat example

  Serial.print("Raw data: ");
  Serial.print(dt.year);   Serial.print("-");
  Serial.print(dt.month);  Serial.print("-");
  Serial.print(dt.day);    Serial.print(" ");
  Serial.print(dt.hour);   Serial.print(":");
  Serial.print(dt.minute); Serial.print(":");
  lcd.print(dt.day); lcd.print("-");
  lcd.print(dt.month); lcd.print("-");
  lcd.print(dt.year);
  lcd.setCursor(0, 1);
    lcd.print(dt.hour); lcd.print(":");
  lcd.print(dt.minute);
  
  
  delay(5000);
}