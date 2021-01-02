#include "mic.h"

int micPin = A0;
int micVal = 0;

void configureMic(){
	pinMode(micPin, INPUT);
}

void readMic(){
	micVal = analogRead(micPin);
  	Serial.println(micVal);
}