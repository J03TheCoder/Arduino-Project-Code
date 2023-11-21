#include <LedControl.h>
#include <Servo.h>
#include "IRremote.h"
Servo myservo;
#define ENABLE 5
#define DIRA 3
#define DIRB 4


int receiver = 8;
IRrecv irrecv(receiver);    // create instance of 'irrecv'
uint32_t last_decodedRawData = 0;

// Define the pin connections for the matrix display
const int dataPin = 12;
const int clkPin = 10;
const int csPin = 11;


byte leds = 0;

LedControl lc = LedControl(dataPin, clkPin, csPin, 1); // Initialize the LedControl library

// Define the smiley face pattern
byte smiley[8] = {
  B00000000,
  B00100100,
  B00000000,
  B00000000,
  B10000001,
  B01111110,
  B00000000,
  B00000000
};

// Define the eyes pattern
byte eyes[8] = {
  B00000000,
  B01100110,
  B01100110,
  B00000000,
  B10000001,
  B01111110,
  B00000000,
  B00000000
};

void setup() {
  Serial.begin(9600);
   myservo.attach(9);
  myservo.write(120);
  lc.shutdown(0, false); // Wake up the matrix display
  lc.setIntensity(0, 8); // Set the brightness (0-15)
  lc.clearDisplay(0);
  irrecv.enableIRIn();
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
}

void loop() {
  drawSmiley(); // Draw the smiley face
  delay(2000);  // Delay for 2 seconds
  drawEyes();   // Draw the eyes
  delay(2000);
 if (irrecv.decode()) // have we received an IR signal?
  {
    // Check if it is a repeat IR code
    if (irrecv.decodedIRData.flags)
    {
      //set the current decodedRawData to the last decodedRawData
      irrecv.decodedIRData.decodedRawData = last_decodedRawData;
    }
    switch (irrecv.decodedIRData.decodedRawData)
    {

      case 0xF609FF00: // UP button pressed
        digitalWrite(ENABLE,HIGH);
       digitalWrite(DIRA,HIGH); //one way
        digitalWrite(DIRB,LOW);
        delay(3500);
        digitalWrite(DIRA,LOW);
        digitalWrite(ENABLE,LOW);
        break;

      case 0xF807FF00: // DOWN button pressed
        digitalWrite(ENABLE,HIGH);
        digitalWrite(DIRA,LOW);  //reverse
        digitalWrite(DIRB,HIGH);
        delay(3500);
        digitalWrite(DIRB,LOW);
        digitalWrite(ENABLE,LOW);
        break;

      case 0xB847FF00: // FUNC/STOP button pressed
        myservo.write(190);
        delay(1000);
        myservo.write(120);
        break;

    }
    //store the last decodedRawData
    last_decodedRawData = irrecv.decodedIRData.decodedRawData;
    irrecv.resume(); // receive the next value
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
}
}

void drawSmiley() {
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, smiley[row]);
  }
}

void drawEyes() {
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, eyes[row]);
  }
}