#include "LiquidCrystal_I2C.h"
#define sensorPin A1
// // จอกว้าง 16 ตัวอักษร 2 บรรทัด รหัสประจำตัว 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Hello, world!"); // แสดงผลคำว่า Hello world! ออกหน้าจอ
  lcd.setCursor(0, 1);// เลื่อนเคเซอร์ไปบรรทัดที่ 2 ลำดับที่ 0 (ก่อนหน้าตัวอักษรแรก)
  lcd.print("Hi"); // แสดงผลคำว่า Hi ออกหน้าจอ
  delay(2000); //หน่วงเวลา 2 วินาที
  pinMode(sensorPin, INPUT);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Hello, world!");// แสดงผลคำว่า Hello world! ออกหน้าจอ

  lcd.setCursor(0, 1);// เลื่อนเคเซอร์ไปบรรทัดที่ 2 ลำดับที่ 0 (ก่อนหน้าตัวอักษรแรก)
  lcd.print("Hi");
}

