#include <LiquidCrystal.h>

LiquidCrystal lcd(A5,A4,A3,A2,A1,A0);
int i;

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.print("DS_COMPANY IoT");
  lcd.setCursor(0,1);
  lcd.print("WELCOME TO TEAM PVS");
  delay(3000);
  lcd.clear();
  lcd.print("PUSH_BUTTON");
  delay(3000);
  lcd.clear();
}

void pushbutton_led()

{

lcd.clear();
lcd.print("Push Button");
Serial.println("Push Button");
lcd.setCursor(0,1);
lcd.print("Press Key6");
Serial.println("Press Key6");


  
pinMode(7, INPUT);  // turn the LED on (HIGH is the voltage level)
digitalWrite(7, HIGH); 

for (i =2;i<=6;i++)
{
pinMode(i, OUTPUT);  // turn the LED on (HIGH is the voltage level)
digitalWrite(i, HIGH);  
}

while(digitalRead(7));

if(!digitalRead(7))
{
lcd.clear();
lcd.print("Key6 Pressed");
Serial.println("Key6 Pressed");
Serial.println("LED_pattern");
for (i =2;i<=6;i++)
  {
  digitalWrite(i, LOW);
  delay(100);  
  }
for (i =6;i>=2;i--)
  {
  digitalWrite(i, HIGH);
  delay(100);  
  }
  for (i =2;i<=6;i++)
  digitalWrite(i, HIGH);
}


 
}

void loop() {

    pushbutton_led();
    delay(1000);

  
}
