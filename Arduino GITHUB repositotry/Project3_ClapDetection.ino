#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
int Sensor = A0;
int clap = 0;
long detection_range_start = 0;
long detection_range = 0;
boolean status_lights = false;
// By www.andprof.com
void setup() {
pinMode(Sensor, INPUT);
lcd.begin(16, 2);

}

void loop() {
int status_sensor = digitalRead(Sensor);
if (status_sensor == 0)
{
if (clap == 0)
{
detection_range_start = detection_range = millis();
clap++;
}
else if (clap > 0 && millis()-detection_range >= 50)
{
detection_range = millis();
clap++;
}
}
if (millis()-detection_range_start >= 400)
{
if (clap == 2)
{
if (!status_lights)
{
status_lights = true;
lcd.print("Clap Detected");
}
else if (status_lights)
{
status_lights = false;

}
}
clap = 0;
}
}