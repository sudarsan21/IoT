#include <LiquidCrystal.h>
LiquidCrystal lcd(A5,A4,A3,A2,A1,A0);
int i;

void setup() 
{
  Serial.begin(300);
  lcd.begin(16, 2);
  Serial.println("Hello World");

  lcd.print("Hello World");
  lcd.setCursor(0,1);
  delay(3000);
  lcd.clear();
 
 }
void loop()
{
   setup();
}
