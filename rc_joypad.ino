#include "physconf.h"
#include "sdcard.h"
#include "24conn.h"
#include "mpu6050.h"
#include "mic.h"
#include "music.h"


void setup(){
	PhysConfig pc;
	Serial.begin(115200);
	
	
	printf_begin();
	
	configureSDCard();
	// configureRadio();  
	// configureMic();
	// configureBuzzer();
	configureMPU6050();
}


void loop()
{
	// loadMPUData();
	// logMPU();
	// SetupSWimperialMarch();
	// SetupGreenHill();
	// PlayMusic();
	// readMic();
}
