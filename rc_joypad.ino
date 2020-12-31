#include "24conn.h"



void setup(){
	Serial.begin(115200);
	Serial.println(F("--====Communications Log====--"));
	
	printf_begin();

	configureRadio();  
}

void loop()
{

}

