#include "LiquidCrystal_I2C.h"
#define sensorPin A1
#include <Servo.h>
Servo myservo; //ประกาศตัวแปรแทน Servo
LiquidCrystal_I2C lcd(0x27, 16, 2);
 #define outputA 6
 #define outputB 7
 int counter = 0; 
 int angle = 0; 
 int currentState;
 int previousState;  
 void setup() 
 { 
   lcd.init();
   lcd.backlight();
   lcd.setCursor(0, 0);
   lcd.print("Position: ");
   lcd.println(counter);
   pinMode(sensorPin, INPUT);
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   myservo.attach(9); // กำหนดขา 9 ควบคุม Servo
   Serial.begin (9600);
   previousState = digitalRead(outputA);   
 } 
 void loop() { 
   currentState = digitalRead(outputA); 
   if (currentState != previousState){     
     if (digitalRead(outputB) != currentState) { 
       counter ++;
     } else {
       counter --;
     }
     Serial.print("Position: ");
     Serial.println(counter);
     lcd.clear();
     lcd.print("Position: ");
     lcd.print(counter); 
     myservo.write(counter);
     lcd.setCursor(0,0);

   } 
  previousState = currentState;
 }