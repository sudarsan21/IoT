/*
  WriteMultipleFields
  
  Description: Writes values to fields 1,2,3,4 and status in a single ThingSpeak update every 20 seconds.
  
  Hardware: ESP8266 based boards
  
  !!! IMPORTANT - Modify the secrets.h file for this project with your network connection and ThingSpeak channel details. !!!
  
  Note:
  - Requires ESP8266WiFi library and ESP8622 board add-on. See https://github.com/esp8266/Arduino for details.
  - Select the target hardware from the Tools->Board menu
  - This example is written for a network using WPA encryption. For WEP or WPA, change the WiFi.begin() call accordingly.
  
  ThingSpeak ( https://www.thingspeak.com ) is an analytic IoT platform service that allows you to aggregate, visualize, and 
  analyze live data streams in the cloud. Visit https://www.thingspeak.com to sign up for a free account and create a channel.  
  
  Documentation for the ThingSpeak Communication Library for Arduino is in the README.md folder where the library was installed.
  See https://www.mathworks.com/help/thingspeak/index.html for the full ThingSpeak documentation.
  
  For licensing information, see the accompanying license file.
  
  Copyright 2020, The MathWorks, Inc.
*/

#include <ESP8266WiFi.h>
#include "secrets.h"
#include "ThingSpeak.h" // always include thingspeak header file after other header files and custom macros
#include <SoftwareSerial.h>

SoftwareSerial swSer(D6, D7);

char ssid[] = SECRET_SSID;   // your network SSID (name) 
char pass[] = SECRET_PASS;   // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient  client;

unsigned long myChannelNumber = SECRET_CH_ID;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;

// Initialize our values
float number1 = 0;
float number2 = 0;
float number3 = 0;
float number4 = 0;
float number5 = 0;
float number6 = 0;
float number7 = 0;
float number8 = 0;


String myStatus = "";
String response;

int ESPwait(String stopstr, int timeout_secs)
{
  bool found = false;
  char c;
  long timer_init;
  long timer;

  response="";
  timer_init = millis();
  while (!found) {
    timer = millis();
    if (((timer - timer_init) / 1000) > timeout_secs) { // Timeout?
      Serial.println("!Timeout!");
      return 0;  // timeout
    }
    if (swSer.available()) {
      c = swSer.read();
      //Serial.print(c);
      response += c;
      if (response.endsWith(stopstr)) {
        found = true;
        delay(10);
        swSer.flush();
        Serial.flush();
        Serial.println();
      }
    } // end Serial1_available()
  } // end while (!found)
  return 1;
}

int ESPwait1(String stopstr, int timeout_secs)
{
  bool found = false;
  char c;
  long timer_init;
  long timer;

  response="";
  timer_init = millis();
  while (!found) {
    timer = millis();
    if (((timer - timer_init) / 1000) > timeout_secs) { // Timeout?
      Serial.println("!Timeout!");
      return 0;  // timeout
    }
    if (Serial.available()) {
      c = Serial.read();
      Serial.print(c);
      response += c;
      if (response.endsWith(stopstr)) {
        found = true;
        delay(10);
        Serial.flush();
        Serial.println();
      }
    } // end Serial1_available()
  } // end while (!found)
  return 1;
}


void setup() {
  Serial.begin(9600);  // Initialize serial
  swSer.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo native USB port only
  }
  
  WiFi.mode(WIFI_STA); 
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}

void loop() {
  char c;
  
  // Connect or reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(SECRET_SSID);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected.");

    for(int i=0;i<5;i++)
    {
    digitalWrite(LED_BUILTIN,LOW);
    delay(100);
    digitalWrite(LED_BUILTIN,HIGH);
    delay(100);
    }
    
  }

if(swSer.available())
  {
   
  c=swSer.read();
  swSer.println(c);
  if(c=='*')
    {
      if(ESPwait("#",3))
      {
      char * strtokIndx;
      response.remove(response.length()-1);
      
      strtokIndx = strtok(const_cast<char*>(response.c_str()),",");      // get the first part - the string
      number1 = atof(strtokIndx);
      
//      strtokIndx = strtok(NULL, ","); 
//      number2 = atof(strtokIndx);
//
//      strtokIndx = strtok(NULL, ","); 
//      number3 = atof(strtokIndx);
//
//      strtokIndx = strtok(NULL, ","); 
//      number4 = atof(strtokIndx);
//      
//      strtokIndx = strtok(NULL, ","); 
//      number5 = atof(strtokIndx);
//      
//      strtokIndx = strtok(NULL, ","); 
//      number6 = atof(strtokIndx);
//      
//      strtokIndx = strtok(NULL, ","); 
//      number7 = atof(strtokIndx);
//      
//      strtokIndx = strtok(NULL, ","); 
//      number8 = atof(strtokIndx);

      Serial.println(response);
      response="";
      
  ThingSpeak.setField(1, number1);
//  ThingSpeak.setField(2, number2);
//  ThingSpeak.setField(3, number3);
//  ThingSpeak.setField(4, number4);
//  ThingSpeak.setField(5, number5);
//  ThingSpeak.setField(6, number6);
//  ThingSpeak.setField(7, number7);
//  ThingSpeak.setField(8, number8);
  
//  myStatus = String("System Normal"); 
//  ThingSpeak.setStatus(myStatus);
  
  //int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  Serial.println(analogRead(A0));
  int x = ThingSpeak.writeField(myChannelNumber, 1, analogRead(A0), myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
    digitalWrite(LED_BUILTIN,LOW);
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
    digitalWrite(LED_BUILTIN,HIGH);
  }
  Serial.println("Sent");
  
      }
    }
  }
  else
  {
    int val = analogRead(A0);
    float mv = ( val/1024.0)*3300;
    float cel = mv/10;
    Serial.println(cel);
  int x = ThingSpeak.writeField(myChannelNumber, 1, cel, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
    digitalWrite(LED_BUILTIN,LOW);
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
    digitalWrite(LED_BUILTIN,HIGH);
  }
  Serial.println("Sent");
  }
  delay(10000); // Wait 20 seconds to update the channel again
}
