
 int counter = 0; 
 int currentStateCLK;
 int previousStateCLK; 
 String encdir ="";
 
 void setup() 
 {  
   pinMode (4,INPUT);
   pinMode (5,INPUT);
   pinMode (8,OUTPUT);
   Serial.begin (9600); 
   previousStateCLK = digitalRead(4);
 
 } 
 
 void loop() { 

   currentStateCLK = digitalRead(4);

   if (currentStateCLK != previousStateCLK)
   { 

     if (digitalRead(5) != currentStateCLK) 
     { 
       counter --;
       encdir ="Core value ";
       digitalWrite(8, HIGH);

     } else {

       counter ++;
       encdir ="Core value";
       digitalWrite(8, LOW);
     }
     Serial.print("Direction: ");
     Serial.print(encdir);
     Serial.print(" -- Value: ");
     Serial.println(counter);
   } 
   // Update previousStateCLK with the current state
   previousStateCLK = currentStateCLK; 
 }