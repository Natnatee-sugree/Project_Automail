#include <Servo.h>
Servo myServo_0;  
Servo myServo_1;
int counter = 0; // กำหนดค่าเริ่มเป็น 0
String encdir ; 
int currentState;
int previousState;
Servo myServo_2;
int currentState1;
int previousState1;
int counter1 = 0;
String encdir1 ;
void setup()
{
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  myServo_0.attach(9); 
  myServo_1.attach(10); 
  myServo_2.attach(11); 
  pinMode (4,INPUT);// กำหนดค่า 4 เป็นแบบ Input 
  pinMode (5,INPUT);// กำหนดค่า 5 เป็นแบบ Input
  pinMode (6,INPUT); 
  pinMode (7,INPUT);
  previousState = digitalRead(4);
  previousState1 = digitalRead(6);
}
void servo_1()
{
 currentState = digitalRead(4);
 if (currentState != previousState) 
   { 
     if (digitalRead(5) != currentState ) 
     { 
       encdir ="Core value : ";
       counter --;
       if (counter<0)
	   counter=0; 
     } else 
     {
       encdir ="Core value : ";
       counter ++; // แสดงผลเพิ่มขึ้น
       if (counter>180)
	   counter=180;
     }
     Serial.print(encdir);// แสดงผลคำตัวแปล
     Serial.println(counter);// แสดงผลค่า
     myServo_1.write(counter);
   } 
    previousState = currentState; 
}
void servo_2()
{
    currentState1 = digitalRead(6);
    if(currentState1 != previousState1)
    {
       if(digitalRead(7) != currentState1)
       {
         encdir1 = "Core value_2 : ";
         counter1 --;
         if(counter1<0)
         counter1=0;
       } else
       {
           encdir1 = "Core value_2 : ";
           counter1 ++;
           if(counter1>180)
           counter1=180;
       }
     Serial.print(encdir1);// แสดงผลคำตัวแปล
     Serial.println(counter1);// แสดงผลค่า
     myServo_2.write(counter1);
    }
    previousState1 = currentState1; 
}
void loop()
{           
  servo_1();
  servo_2();
  int analog_0 = analogRead(A0);           
  int counter_0 = map(analog_0, 0, 1023, 0, 180);     
  myServo_0.write(counter_0);              
}
