
 int counter = 0; // กำหนดค่าเริ่มเป็น 0
 int currentStateCLK;
 int previousStateCLK; 
 String encdir ;
 
 void setup() 
 {  
   pinMode (4,INPUT);// กำหนดโหมดเป็นแบบ Input 
   pinMode (5,INPUT);// กำหนดโหมดเป็นแบบ Input 
   pinMode (8,OUTPUT);// กำหนดโหมดเป็นแบบ OUTPUT 
   Serial.begin (9600); 
   previousStateCLK = digitalRead(4);
 
 } 
 
 void loop() { 

   currentStateCLK = digitalRead(4);

   if (currentStateCLK != previousStateCLK)
   { 

     if (digitalRead(5) != currentStateCLK) 
     { 
       counter ++; // แสดงผลเพิ่มขึ้น
       encdir ="Core value : "; // แสดงผลคำ Core value : ใน Serial monitor
       digitalWrite(8, HIGH);

     } else {

       counter --; // แสดงผลลดลง
       encdir ="Core value : "; // แสดงผลคำ Core value : ใน Serial monitor
       digitalWrite(8, LOW);
     }
     Serial.print(encdir);// แสดงผลคำตัวแปล
     Serial.println(counter);// แสดงผลค่า
   } 
   // อัปเดตค่าด้วยค่าปัจจุบัน
   previousStateCLK = currentStateCLK; 
 }