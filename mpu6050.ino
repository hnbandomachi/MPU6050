#include <LiquidCrystal.h> 
#include "mpu6050.h"

LiquidCrystal lcd(8, 7, 5, 4, 3, 2);
int angleX, angleY, angleZ;
void setup() {
  // put your setup code here, to run once:
   lcd.begin(16, 2);
   mpu6050();
   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  angleX = map(get_accx(), -16384, 16384, -90, 90);
  angleY = map(get_accy(), -16384, 16384, -90, 90);
  angleZ = map(get_accz(), -16384, 16384, -90, 90);

  Serial.print(" angleX: ");
  Serial.print(angleX);
  Serial.print(" angleY: ");
  Serial.print(angleY);
  Serial.print(" angleZ: ");
  Serial.println(angleZ);
  
  if(angleY > 90 || angleY < 0) {
    angleY = abs(angleX);
    if(angleY > 90) angleY = 180 - angleX;
  }     
  lcd.setCursor(0, 0);    
  lcd.print("angle: ");
  lcd.setCursor(7, 0);
  lcd.print(angleY);  
  delay(1000);
  lcd.clear();
}
