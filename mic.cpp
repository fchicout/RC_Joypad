#include "mic.h"


Mic::Mic() {
	pinMode(micPin, INPUT);
}


void Mic::readMic() {
	micVal = analogRead(micPin);
  	Serial.println(micVal);
}