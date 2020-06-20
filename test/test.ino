
long hour = 3600000; // 3600000 milliseconds in an hour
long minute = 60000; // 60000 milliseconds in a minute
long second =  1000; // 1000 milliseconds in a second
void setup(){
Serial.begin (57600);
}
void loop(){
 time();
 delay(1000);
}
void time(){
long timeNow = millis();
int hours = timeNow / hour;                      
int minutes = (timeNow % hour) / minute ;        
int seconds = ((timeNow % hour) % minute) / second;
 Serial.print("H:");
 Serial.print( hours,DEC);    
 Serial.print("M:");
 printDigits(minutes);
 Serial.print("S:");
 printDigits(seconds);
 Serial.println();  
}
void printDigits(byte digits){
 Serial.print(" - ");
 if(digits < 10)
   Serial.print('0');
 Serial.print(digits,DEC);  
}