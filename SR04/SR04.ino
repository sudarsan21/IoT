#include <LiquidCrystal.h>
LiquidCrystal lcd(A5,A4,A3,A2,A1,A0);
int i;

void setup() {
  Serial.begin(300);
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


void sr04()
{
  pinMode(13, OUTPUT); 
  pinMode(12, INPUT);
  
  for(int i=0;i<100;i++)
  {
  lcd.clear();
  lcd.print("UltraSonic");
  lcd.setCursor(0,1);
  digitalWrite(13, LOW);
  delayMicroseconds(2);
  digitalWrite(13, HIGH);
  delayMicroseconds(10);
  digitalWrite(13, LOW);
  
  long duration = pulseIn(12, HIGH);
  
  int distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  lcd.print("Distance:");
  lcd.print(distance);
  lcd.print("cm");
  Serial.print("Distance:"); 
  Serial.println(distance); 
  delay(100);
  }
  
}

void loop() {

    sr04();
    delay(1000);
  
}
