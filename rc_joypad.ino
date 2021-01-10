#include "physconf.h"
#include "sdcard.h"
#include "24conn.h"
#include "mpu6050.h"
#include "mic.h"
#include "music.h"


void setup(){
	Serial.begin(115200);
	
	
	printf_begin();

	// configureDipSwitch();
	// configureSDCard();
	// configureRadio();  
	// configureMic();
	// configureBuzzer();
	configureMPU6050();
}


void loop()
{
	loadMPUData();

	// SetupSWimperialMarch();
	// SetupGreenHill();
	// PlayMusic();
	// readMic();
}
