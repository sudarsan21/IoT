#include <LiquidCrystal.h>
LiquidCrystal lcd(A5,A4,A3,A2,A1,A0);
int i;

void setup() {
  Serial.begin(300);
  lcd.begin(16, 2);
  lcd.print("DS_COMPANY IoT");
  lcd.setCursor(0,1);
  lcd.print("Welcome To TEAM PVS");
  delay(3000);
  lcd.clear();
  lcd.print("Hello World");
  delay(3000);
  lcd.clear();
}

void ir_sensor()
{
  pinMode(10,INPUT);
  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
  
  for(int i=0;i<100;i++)
  {
    if(!digitalRead(10))
    {
      lcd.clear();
      lcd.print("IR Triggered");
      Serial.println("IR Triggered");


      digitalWrite(2,LOW);
    }
    else
    {
     lcd.clear();
      lcd.print("IR Not Triggered");
      Serial.println("IR Not Triggered");
      digitalWrite(2,HIGH); 
    }
    delay(100);
  }
}

void loop() {

    ir_sensor();
    delay(1000000);
  
}
