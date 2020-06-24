#include <Servo.h>
#include "LiquidCrystal_I2C.h"
#define sensorPin A1
LiquidCrystal_I2C lcd(0x27, 16, 2);
//SERVO_0
Servo myservo_0;
int counter_0 = 0;
int currentState_0;
int previousState_0; 
String encdir_0 = "SERVO 0 :";  
//SERVO_1
Servo myservo_1;
int counter_1 = 0; 
int currentState_1;
int previousState_1; 
String encdir_1 = "SERVO 1 :";
//SERVO_2
Servo myservo_2;
int counter_2 = 0; 
int currentState_2;
int previousState_2; 
String encdir_2 = "SERVO 2 :";
 void setup() 
 {  
   pinMode (2,INPUT);
   pinMode (3,INPUT);
   pinMode (4,INPUT);
   pinMode (5,INPUT);
   pinMode (6,INPUT);
   pinMode (7,INPUT);  
   pinMode(sensorPin, INPUT);
   myservo_0.attach(11);
   myservo_1.attach(9);
   myservo_2.attach(10);
   Serial.begin (9600); 
   previousState_0 = digitalRead(2);
   previousState_1 = digitalRead(4);
   previousState_2 = digitalRead(6);
   lcd.init();
   lcd.backlight();
   lcd.setCursor(0, 0);
   lcd.print("Automail Ready"); 
 } 
void SERVO_0()
{
currentState_0 = digitalRead(2);

   if (currentState_0 != previousState_0) 
   { 

     if (digitalRead(3) != currentState_0)
     { 
       if (counter_0>179)counter_0=179;
       counter_0 ++;
     } else 
     {
       if (counter_0<1)counter_0=1;
       counter_0 --;
     }
     Serial.print(encdir_0);
     Serial.println(counter_0);
     myservo_0.write(counter_0);
     lcd.clear();
     lcd.print(encdir_0);
     lcd.print(int(counter_0));
     lcd.setCursor(0,0);
   } 
   previousState_0 = currentState_0;                                                
}
void SERVO_1()
{
   currentState_1 = digitalRead(4);

   if (currentState_1 != previousState_1) 
   { 

     if (digitalRead(5) != currentState_1)
     { 
       if (counter_1>179)counter_1=179;
       counter_1 ++;
     } else 
     {
       if (counter_1<1)counter_1=1;
       counter_1 --;
     }
     Serial.print(encdir_1);
     Serial.println(counter_1);
     myservo_1.write(counter_1);
     lcd.clear();
     lcd.print(encdir_1);
     lcd.print(int(counter_1));
     lcd.setCursor(0,0);
   } 
   previousState_1 = currentState_1;
} 
void SERVO_2()
{
   currentState_2 = digitalRead(6);

   if (currentState_2 != previousState_2) 
   { 

     if (digitalRead(7) != currentState_2)
     { 
       if (counter_2>179)counter_2=179;
       counter_2 ++;
     } else 
     {
       if (counter_2<1)counter_2=1;
       counter_2 --;
     }
     Serial.print(encdir_2);
     Serial.println(counter_2);
     myservo_2.write(counter_2);
     lcd.clear();
     lcd.print(encdir_2);
     lcd.print(int(counter_2));
     lcd.setCursor(0,0);
   } 
   previousState_2 = currentState_2;
}
void loop() 
{ 
SERVO_0();
SERVO_1();
SERVO_2();
}