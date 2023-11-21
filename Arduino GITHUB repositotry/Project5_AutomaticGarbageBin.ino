#include "SR04.h"
#include "Servo.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;
int distance = 0;
Servo myservo;

void setup() {
   Serial.begin(9600);
   delay(1000);
   myservo.attach(10);
   delay(100);
   myservo.write(200);
  delay(500);
  myservo.write(60);
}

void loop() {
   distance = a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
   delay(100);
  if ((distance <= 5)&&(distance > 0)) {
    myservo.write(200);
    delay(2000);
    myservo.write(60);
}
   }
