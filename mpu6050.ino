#include <LiquidCrystal.h> 
#include "mpu6050.h"

// D4 --> D4
// D5 --> D5
// D6 --> D6
// D7 --> D7
// RS --> D2
// E  --> D3
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
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

  Serial.print("angleX: ");
  Serial.print(angleX);
  Serial.print("angleY: ");
  Serial.print(angleY);
  Serial.print("angleZ: ");
  Serial.println(angleZ);
  
  if(angleX > 90 || angleX < 0) {
    angleX = abs(angleX);
    if(angleX > 90) angleX = 180 - angleX;
  }     
  lcd.setCursor(0, 0);    
  lcd.print("angleX:");
  lcd.setCursor(7, 0);
  lcd.print(angleX);  
  delay(1000);
  lcd.clear();
}
