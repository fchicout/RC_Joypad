#include "physconf.h"
#include "sdcard.h"
#include "24conn.h"
#include "mic.h"
#include "music.h"


void setup(){
	Serial.begin(115200);
	
	
	printf_begin();

	configureDipSwitch();
	// configureSDCard();
	// configureRadio();  
	// configureMic();
	// configureBuzzer();
	
}


void loop()
{
	Serial.println(isSaveLogOn());
	// SetupSWimperialMarch();
	// SetupGreenHill();
	// PlayMusic();
	// readMic();
}
