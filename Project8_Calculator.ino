// made by joe
#include <LiquidCrystal.h>
#include <Keypad.h>

String currentOperation = "";
int firstNumber = 0;
String input = "";
int answer = 0;
String LCDInput = "";
LiquidCrystal lcd(22, 23, 24, 25, 26, 27);


const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','x'},
  {'0','AC','=','/'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
    lcd.begin(16, 2);
  // Print a message to the LCD
}
  
void loop(){
  char key = customKeypad.getKey();
  
  
  if (key != NO_KEY){
    if (key=='1')
    {Serial.println("S1 key pressed");
      input += "1";
      LCDInput += "1";
      lcd.clear();
      lcd.print(LCDInput);
    }
    if (key=='2'){
      Serial.println("S2 key pressed");
      input += "2";
      LCDInput += "2";
      lcd.clear();
      lcd.print(LCDInput);
       }
    if (key=='3'){ 
      Serial.println("S3 key pressed");
      input += "3";
      LCDInput += "3";
      lcd.clear();
      lcd.print(LCDInput);
      }
    if (key=='+'){
       Serial.println("S4 key pressed");
       currentOperation = "+";
       firstNumber = input.toInt();
       input = "";
       LCDInput += "+";
      lcd.clear();
      lcd.print(LCDInput);
       }
    if (key=='4'){ 
      Serial.println("S5 key pressed");
      input += "4";
      LCDInput += "4";
      lcd.clear();
      lcd.print(LCDInput);
      }
    if (key=='5'){ 
      Serial.println("S6 key pressed");
      input += "5";
       LCDInput += "5";
      lcd.clear();
      lcd.print(LCDInput);
      }
    if (key=='6'){ 
      Serial.println("S7 key pressed");
      input += "6";
       LCDInput += "6";
      lcd.clear();
      lcd.print(LCDInput);
      }
    if (key=='-') {
     Serial.println("S8 key pressed");
     currentOperation = "-";
     firstNumber = input.toInt();
     input = "";
      LCDInput += "-";
      lcd.clear();
      lcd.print(LCDInput);
     }
    if (key=='7'){ 
      Serial.println("S9 key pressed");
      input += 7;
       LCDInput += "7";
      lcd.clear();
      lcd.print(LCDInput);
      }
    if (key=='8'){
       Serial.println("S10 key pressed");
       input += "8";
        LCDInput += "8";
      lcd.clear();
      lcd.print(LCDInput);
       }
    if (key=='9'){ 
      Serial.println("S11 key pressed");
      input += "9";
       LCDInput += "9";
      lcd.clear();
      lcd.print(LCDInput);
      }
    if (key=='x'){ 
      Serial.println("S12 key pressed");
      currentOperation = "x";
      firstNumber = input.toInt();
      input = "";
       LCDInput += "x";
      lcd.clear();
      lcd.print(LCDInput);
      }
    if (key=='0'){ 
      Serial.println("S13 key pressed");
      input += 0;
       LCDInput += "0";
      lcd.clear();
      lcd.print(LCDInput);
      }
    if (key=='AC'){ 
      Serial.println("S14 key pressed");
      input = "";
      currentOperation = "";
      firstNumber = 0;
      answer = 0;
      LCDInput = "";
      lcd.clear();
      lcd.print("AC clicked");
      delay(1000);
      lcd.clear();
      }
    if (key=='='){
       Serial.println("S15 key pressed");
      int secondNumber = input.toInt();
        if (currentOperation == "+") {
          answer = firstNumber + secondNumber;
          Serial.println(String(answer));
          input = "";
          lcd.setCursor(0,1);
          lcd.print(String(answer));
          delay(5000);
                input = "";
      currentOperation = "";
      firstNumber = 0;
      answer = 0;
      LCDInput = "";
      lcd.clear();
        } else if (currentOperation == "-") {
          answer = firstNumber - secondNumber;
          Serial.println(String(answer));
          input = "";
            lcd.setCursor(0,1);
          lcd.print(String(answer));
                    delay(5000);
                input = "";
      currentOperation = "";
      firstNumber = 0;
      answer = 0;
      LCDInput = "";
      lcd.clear();
        } else if (currentOperation == "x") {
          answer = firstNumber * secondNumber;
          Serial.println(String(answer));
          input = "";
            lcd.setCursor(0,1);
          lcd.print(String(answer));
                    delay(5000);
                input = "";
      currentOperation = "";
      firstNumber = 0;
      answer = 0;
      LCDInput = "";
      lcd.clear();
        } else if (currentOperation == "/") {
          answer = firstNumber / secondNumber;
          Serial.println(String(answer));
          input = "";
          lcd.setCursor(0,1);
          lcd.print(String(answer));
                    delay(5000);
                input = "";
      currentOperation = "";
      firstNumber = 0;
      answer = 0;
      LCDInput = "";
      lcd.clear();
        } 
       }
    if (key=='/'){
       Serial.println("S16 key pressed");
       currentOperation = "/";
       firstNumber = input.toInt();
       input = "";
           LCDInput += "/";
      lcd.clear();
      lcd.print(LCDInput);
       }
  }
}


// void loop(){
// char key = keypad.getKey();

// if (key != NO_KEY){
// Serial.println(key);

// if (key=="a"){Serial.println("S1 key pressed");}
// if (key=="b"){Serial.println("S2 key pressed"); }
// if (key=="c"){ Serial.println("S3 key pressed");}
// if (key=="d"){ Serial.println("S4 key pressed");}
// if (key=="e"){ Serial.println("S5 key pressed");}
// if (key=="f"){ Serial.println("S6 key pressed");}
// if (key=="g"){ Serial.println("S7 key pressed");}
// if (key=="h"){ Serial.println("S8 key pressed");}
// if (key=="i"){ Serial.println("S9 key pressed");}
// if (key=="j"){ Serial.println("S10 key pressed");}
// if (key=="k"){ Serial.println("S11 key pressed");}
// if (key=="l"){ Serial.println("S12 key pressed");}
// if (key=="m"){ Serial.println("S13 key pressed");}
// if (key=="n"){ Serial.println("S14 key pressed");}
// if (key=="o"){ Serial.println("S15 key pressed");}
// if (key=="p"){ Serial.println("S16 key pressed");}
// }
// }
// }
