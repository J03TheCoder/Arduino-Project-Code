#include "SevenSeg.h"

//Defines the segments A-G: SevenSeg(A, B, C, D, E, F, G);
SevenSeg disp (10,9,8,7,6,11,12);
//Number of 7 segments
const int numOfDigits =1;
//CC(or CA) pins of segment
int digitPins [numOfDigits]={4};

//Variables
int number=1; //Default number
int flag;
int buzzer=5;

void setup() {
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer,LOW);
  pinMode(3,INPUT);
  digitalWrite(3, HIGH);
  randomSeed(analogRead(A0));
  Serial.begin(9600);
  //Defines the number of digits to be "numOfDigits" and the digit pins to be the elements of the array "digitPins"
  disp.setDigitPins ( numOfDigits , digitPins );
  //Only for common cathode 7segments
  disp.setCommonCathode();
  //Control brightness (values 0-100);
  disp.setDutyCycle(50);
  
}

void loop()
{	
    int digitalVal = digitalRead(3);
  if(HIGH == digitalVal)
  {
    number = random(6);
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(buzzer,LOW);
  }
	//Check if incoming data is available:
    if (Serial.available() > 0)
    {
      // If it is, we'll use parseInt() to pull out only numbers:
      number = Serial.parseInt();
      flag=0;
    }

	//Valid range is from 1 to 9
	if (number>=1 && number<=9){
		//Print number to 7 segment display
		disp.writeDigit(number);
		
	    //Print message to serial monito only once
	    if (flag==0){ 
	    	//Print number to serial monitor
	    	Serial.print("Number on 7 segment display:");
	    	Serial.println(number);
	    	flag=1;
	    }
  }
}
