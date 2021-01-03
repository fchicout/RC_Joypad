#include "sdcard.h"
#include "24conn.h"
#include "mic.h"
#include "music.h"


void setup(){
	Serial.begin(115200);
	Serial.println(F("--====Communications Log====--"));
	
	printf_begin();

	configureSDCard();
	configureRadio();  
	configureMic();
	configureBuzzer();
}


void loop()
{
	// SetupSWimperialMarch();
	// SetupGreenHill();
	// PlayMusic();
	readMic();
}
