#include "physconf.h"
#include "sdcard.h"
#include "24conn.h"
#include "mpu6050.h"
#include "mic.h"
#include "music.h"
#include "joypad.h"

PhysConfig pc;

void setup(){
	Serial.begin(115200);
	
	
	printf_begin();
	
	configureSDCard();
	// configureRadio();  
	// configureMic();
	// configureBuzzer();
	configureMPU6050();
	configureJoyPads();
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
