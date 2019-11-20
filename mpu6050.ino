#include <LiquidCrystal.h> 
#include "mpu6050.h"

LiquidCrystal lcd(8, 7, 5, 4, 3, 2);
float x, y, z;
float angle;
void setup() {
  // put your setup code here, to run once:
   lcd.begin(16, 2);
   mpu6050();
   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  x = map(get_accx(), -16384, 16384, -90, 90);
  y = map(get_accy(), -16384, 16384, -90, 90);
  z = map(get_accz(), -16384, 16384, -90, 90);

  x = x*3.141592/180;
  y = y*3.141592/180;
  z = z*3.141592/180;

  angle = acos(sin(z)/sqrt(sin(x)*sin(x) + sin(y)*sin(y) + sin(z)*sin(z)));
  angle = angle/3.141592*180;

//  if(x > y) angle = x;
//  else      angle = y;
//
//  if(angle > 90) angle = 180 - angle;

  Serial.print(" X: ");
  Serial.print(x);
  Serial.print(" Y: ");
  Serial.print(y);
  Serial.print(" Z: ");
  Serial.print(z);
  Serial.print(" angle: ");
  Serial.println(angle);
       
  lcd.setCursor(0, 0);    
  lcd.print("angle: ");
  lcd.setCursor(7, 0);
  lcd.print(angle);  
  delay(1000);
  lcd.clear();
}
