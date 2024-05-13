#include "GroveOfflineSensor.h"
#include <SoftwareSerial.h>
#define RX_VC02 10
#define TX_VC02 11

SoftwareSerial groveSerial(RX_VC02, TX_VC02); // RX, TX

void setup() {
  Serial.begin(115200);
  
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  
  while (!Serial); // wait for serial port to connect. Needed for native USB port only , This port is for displaying data Grove Sensor sends

  groveSerial.begin(115200); // Make sure to set the baud rate to match your communication
}

void loop() {
  // Your main code here
   uint8_t *voiceData = detectVoiceFromGroveSensor(&groveSerial);

  if(voiceData != NULL){
    String response = getCommandInString(voiceData);
    Serial.println(response);
    if(response == "ok, turn off the light")
    {
      digitalWrite(2, HIGH);
    }
    if(response == "ok, turn on the light")
    {
      digitalWrite(2, LOW);
    }
    if(response == "ok, stop to fan")
    {
      digitalWrite(3, HIGH);
    }
    if(response == "ok, start to fan")
    {
      digitalWrite(3, LOW);
    }

  }
  delay(1000);
}
