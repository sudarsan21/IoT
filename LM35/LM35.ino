#include <LiquidCrystal.h>
LiquidCrystal lcd(A5,A4,A3,A2,A1,A0);
int i;

void setup() {
  Serial.begin(300);
  lcd.begin(16, 2);
  lcd.print("DS_COMPANY IoT");
  lcd.setCursor(0,1);
  lcd.print("WELCOME TO TEAM PVS");
  delay(3000);
  lcd.clear();
  lcd.print("LM35");
  delay(3000);
  lcd.clear();
}

void temperature()
{
  int val;
  float mv;
  float cel;
  float farh;
  
  for(int i=0;i<20;i++)
  {
  lcd.clear();
  lcd.print("Temperature");
  val = analogRead(A6);
  mv = ( val/1024.0)*5000;
  cel = mv/10;
  farh = (cel*9)/5 + 32;
  lcd.setCursor(0,1);
  lcd.print(cel);
  lcd.print("*C");
  Serial.print("temperature:");  
  Serial.println(cel);

  delay(1000);
  }
}

void loop() {
    temperature();
    delay(1000);
 }
