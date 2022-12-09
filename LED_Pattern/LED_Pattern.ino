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
  lcd.print("LED_PATTERN");
  delay(3000);
  lcd.clear();
}


void ledPattern()
{

  lcd.clear();
  lcd.print("LED Pattern");

  for (i =2;i<=7;i++)
{
pinMode(i, OUTPUT);  // turn the LED on (HIGH is the voltage level)
digitalWrite(i, HIGH);  
}

 for(int j=0;j<5;j++)
 {
    for (i =2;i<=7;i++)
      {
     digitalWrite(i, LOW);
      delay(100);  
      }
    for (i =7;i>=2;i--)
      {
      digitalWrite(i, HIGH);
      delay(100);  
      }
 } 
  for (i =2;i<=7;i++)
  digitalWrite(i, HIGH);

  for (i =2;i<=7;i++)
  pinMode(i, INPUT);
  Serial.println("LED_Pattern"); 
}





void loop() {

    ledPattern();
    delay(1000);
  
}
