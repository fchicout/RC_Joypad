#include "sdcard.h"
#include "24conn.h"
#include "music.h"
#include "mic.h"

void setup(){
	Serial.begin(115200);
	Serial.println(F("--====Communications Log====--"));
	
	printf_begin();

	configureRadio();  
	configureBuzzer();
	configureMic();
	configureSDCard()
}


void loop()
{
	//SetupSWimperialMarch();
	//SetupGreenHill();
	//PlayMusic();
	readMic();
}
