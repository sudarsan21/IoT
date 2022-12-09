#include <LiquidCrystal.h>

LiquidCrystal lcd(A5,A4,A3,A2,A1,A0);
int i;

void setup() {
  // set up the LCD's number of columns and rows:

  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("SR Arduino IoT");
  lcd.setCursor(0,1);
  lcd.print("Experimenter");
  delay(3000);
  lcd.clear();
  lcd.print("Hello World");
  delay(3000);
  lcd.clear();
}

void led_blink()
{
  lcd.clear();
  lcd.print("LED Blink");

  for(int i=0;i<10;i++)
  {
    digitalWrite(13,HIGH);
    Serial.println("Pin13 On");
    Serial.println("Delay 500ms");
    delay(500);
    digitalWrite(13,LOW);
    Serial.println("Pin13 Off");
    Serial.println("Delay 500ms");
    delay(500);
  }
}



void loop() {

    led_blink();
    delay(1000);
 
}
