void setup() 
{
  Serial.begin(9600);
}
void loop()
{
  int sensorValue = analogRead(A0);// อ่านค่าอินพุตที่ขาอะนาล็อก 0
  Serial.println(sensorValue);// แสดงผลคำว่าที่อ่าน
  delay(1);  //หน่วงเวลา 1 วินาที
}