#include <SPI.h>
#include "RF24.h"
#include "printf.h"

 
RF24 radio(7,8) 
const byte addresses[][6] = {"RCJoyP", "2ndNod"}; 
bool radioNumber = 0;
bool role = 0; // Sender || Receiver

void configureRadio()
{
	radio.begin();
	radio.setPALevel(RF24_PA_HIGH);
	// Open a writing and reading pipe on each radio, with opposite addresses
	if(radioNumber){
		radio.openWritingPipe(addresses[1]);
		radio.openReadingPipe(1,addresses[0]);
	}else{
		radio.openWritingPipe(addresses[0]);
		radio.openReadingPipe(1,addresses[1]);
	}
	radio.startListening();
  	radio.printDetails();
}

void setup(){
	Serial.begin(115200);
	Serial.println(F("--====Communications Log====--"));
	
	printf_begin();

	configureRadio();  
}

uint32_t configTimer =  millis();

void loop()
{

}

void receiveData(){
	if ( role == 0 )
	{
		unsigned long got_time;

		if( radio.available()){
			
			uint32_t failTimer = millis();                              // Variable for the received timestamp
			while (radio.available()) {                                 // While there is data ready
			if(millis()-failTimer > 500){
				Serial.println("Radio available failure detected");
				radio.failureDetected = true;
				break;
			}
			radio.read( &got_time, sizeof(unsigned long) );             // Get the payload
			}
			
			radio.stopListening();                                      // First, stop listening so we can talk   
			radio.write( &got_time, sizeof(unsigned long) );            // Send the final one back.      
			radio.startListening();                                     // Now, resume listening so we catch the next packets.     
			Serial.print(F("Sent response "));
			Serial.println(got_time);  
		}
	}
}

void transmitData(){
	if (role == 1)  {
    
    radio.stopListening();                                    // First, stop listening so we can talk.
    
    
    Serial.println(F("Now sending"));

    unsigned long start_time = micros();                             // Take the time, and send it.  This will block until complete
     if (!radio.write( &start_time, sizeof(unsigned long) )){
       Serial.println(F("failed"));
     }
        
    radio.startListening();                                    // Now, continue listening
    
    unsigned long started_waiting_at = micros();               // Set up a timeout period, get the current microseconds
    boolean timeout = false;                                   // Set up a variable to indicate if a response was received or not
    
    while ( ! radio.available() ){                             // While nothing is received
      if (micros() - started_waiting_at > 200000 ){            // If waited longer than 200ms, indicate timeout and exit while loop
          timeout = true;
          break;
      }      
    }
        
    if ( timeout ){                                             // Describe the results
        Serial.println(F("Failed, response timed out."));
    }else{
        unsigned long got_time;                                 // Grab the response, compare, and send to debugging spew
        
        //Failure Handling:
        uint32_t failTimer = millis();
        while(radio.available()){                               //If available always returns true, there is a problem
          if(millis() - failTimer > 250){
            radio.failureDetected = true;
            Serial.println("Radio available failure detected");
            break;
          }
          radio.read( &got_time, sizeof(unsigned long) );
        }
        unsigned long end_time = micros();
        
        // Spew it
        Serial.print(F("Sent "));
        Serial.print(start_time);
        Serial.print(F(", Got response "));
        Serial.print(got_time);
        Serial.print(F(", Round-trip delay "));
        Serial.print(end_time-start_time);
        Serial.println(F(" microseconds"));
    }

    // Try again 1s later
    delay(1000);
  }
}

void changeRoles(){
	if ( Serial.available() ) 
	{
		char c = toupper(Serial.read());
		if ( c == 'T' && role == 0 ){      
		Serial.println(F("*** CHANGING TO TRANSMIT ROLE ***"));
		role = 1;                  // Become the primary transmitter (ping out)
		
	}else if ( c == 'R' && role == 1 ){
		Serial.println(F("*** CHANGING TO RECEIVE ROLE ***"));      
		role = 0;                // Become the primary receiver (pong back)
		radio.startListening();
		
		}
	}

}