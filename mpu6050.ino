#include "mpu6050.h"
#include <LiquidCrystal.h> 

// D4 --> D4
// D5 --> D5
// D6 --> D6
// D7 --> D7
// RS --> D8
// E  --> D9
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int angle;
void setup() {
  // put your setup code here, to run once:
   lcd.begin(16, 2);
   mpu6050();
   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  angle = map(get_accx(), -16384, 16384, -90, 90);
  if(angle > 90 || angle < 0) {
    angle = abs(angle);
    if(angle > 90) angle = 180 - angle;
  }
  Serial.println(angle);    
  lcd.setCursor(0, 0);    
  lcd.print("Angle:");
  lcd.setCursor(7, 0);
  lcd.print(angle);  
  delay(1000);
  lcd.clear();
}
