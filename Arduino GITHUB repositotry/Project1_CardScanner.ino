#include <LiquidCrystal.h>
#include <SPI.h>
#include <MFRC522.h>
    // Reset pin for the RFID reader module
#define SS_PIN 2   // Slave Select pin for the RFID reader module
LiquidCrystal lcd(7,8,9,10,11,12);
MFRC522 rfid(SS_PIN);   // Create an instance of the MFRC522 RFID reader
int buzzer = 5;
int greenLED = 2;
int blueLED = 3;
int redLED = 4;

// Define the expected UID (change this to your desired UID)
byte expectedUID[] = {0x4F, 0x75, 0x48, 0x06};

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("    Welcome! ث");
  lcd.setCursor(0,1);
  lcd.print(" Scan Your Card");  
  pinMode(buzzer,OUTPUT); 
  pinMode(greenLED,OUTPUT); 
  pinMode(blueLED,OUTPUT); 
  pinMode(redLED,OUTPUT);
  digitalWrite(greenLED,LOW); // Initialize the serial communication
  
  SPI.begin();          // Initialize SPI bus
  rfid.PCD_Init();      // Initialize RFID reader module
  rfid.PCD_DumpVersionToSerial();  // Print the firmware version of the RFID reader
}

void loop() {
  digitalWrite(greenLED,LOW);
  // Check for an RFID card
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    // Get the UID of the card
    byte currentUID[4];
    for (byte i = 0; i < 4; i++) {
      currentUID[i] = rfid.uid.uidByte[i];
    }

    // Compare the UID with the expected UID
    if (memcmp(currentUID, expectedUID, 4) == 0) {
      // UID matches, access granted
      lcd.clear();
      lcd.print("Scanning...");
      digitalWrite(blueLED,HIGH);
      delay(2000);
      lcd.clear();
      digitalWrite(blueLED,LOW);
        digitalWrite(buzzer,HIGH);
        digitalWrite(greenLED, HIGH);
      delay(200);
      digitalWrite(buzzer,LOW);
      lcd.clear();
      lcd.print("Access granted");
      delay(3500);
      lcd.clear();
      lcd.print("Welcome Joe");
      delay(1500);
      digitalWrite(greenLED, LOW);
      lcd.clear();
      lcd.print("    Welcome!");
      lcd.setCursor(0,1);
      lcd.print(" Scan Your Card");
      Serial.println("Access granted");
      
    } else {
      // UID does not match, access denied
      Serial.println("Access denied");
      lcd.clear();
      lcd.print("Scanning...");
      digitalWrite(blueLED,HIGH);
      delay(2000);
      lcd.clear();
      digitalWrite(blueLED,LOW);
        digitalWrite(buzzer,HIGH);
        digitalWrite(redLED,HIGH);
      delay(100);
      digitalWrite(buzzer,LOW);
      delay(100);
      digitalWrite(buzzer,HIGH);
      delay(100);
      digitalWrite(buzzer,LOW);
      lcd.clear();
      lcd.print("Access denied");
      delay(5000);
      digitalWrite(redLED,LOW);
      lcd.clear();
      lcd.print("    Welcome!");
      lcd.setCursor(0,1);
      lcd.print(" Scan Your Card");
      
    }

    rfid.PICC_HaltA();     // Halt PICC
    rfid.PCD_StopCrypto1(); // Stop encryption on PCD
  }
}
// good job. thats a project complete

