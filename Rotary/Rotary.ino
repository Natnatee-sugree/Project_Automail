
 int counter = 0; // กำหนดค่าเริ่มเป็น 0
 int currentState;
 int previousState; 
 String encdir ;
 
 void setup() 
 {  
   pinMode (4,INPUT);// กำหนดค่า 4 เป็นแบบ Input 
   pinMode (5,INPUT);// กำหนดค่า 5 เป็นแบบ Input 
   pinMode (8,OUTPUT);// กำหนดค่า 8 เป็นแบบ OUTPUT 
   Serial.begin (9600); 
   previousState = digitalRead(4);// อ่านค่าสถานะขา 4
   
 } 
 
 void loop() { 

   currentState = digitalRead(4);// อ่านค่าสถานะขา 4

   if (currentState != previousState) 
   { 

     if (digitalRead(5) != currentState) // ค่าสถานะขา 5 ไม่เท่ากับตัวแปร currentState
     { 
       digitalWrite(8, LOW);
       counter --; // แสดงผลลดลง
       encdir ="Core value : "; // แสดงผลคำ Core value : ใน Serial monitor
     } else 
     {
       digitalWrite(8, HIGH);
       counter ++; // แสดงผลเพิ่มขึ้น
       encdir ="Core value : "; // แสดงผลคำ Core value : ใน Serial monitor
     }
     Serial.print(encdir);// แสดงผลคำตัวแปล
     Serial.println(counter);// แสดงผลค่า
   } 
   // อัปเดตค่าด้วยค่าปัจจุบัน
   previousState = currentState; 
 }