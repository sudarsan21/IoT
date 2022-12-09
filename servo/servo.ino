#include <LiquidCrystal.h>
#include <Servo.h>
Servo myservo;
LiquidCrystal lcd(A5,A4,A3,A2,A1,A0);
int i;

void setup() {
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



void servoSweep()
{
  lcd.clear();
  lcd.print("Servo Demo");
  
   myservo.attach(11);
   int pos;

for(int i=0; i<2;i++)
{
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              //ell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position/ t
    lcd.setCursor(0,1);
    lcd.print("   ");
    lcd.setCursor(0,1);
    lcd.print(pos);
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    lcd.setCursor(0,1);
    lcd.print("   ");
    lcd.setCursor(0,1);
    lcd.print(pos);
    Serial.println("Servo motor Degree");
    Serial.println(pos);
  }
}

}



void loop() {


    servoSweep();
    delay(1000);

  
}
