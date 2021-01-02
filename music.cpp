#pragma once

#include "music.h"

int buzzerPin = 9;

float seno;
int frequencia;
void configureBuzzer(){
	pinMode(buzzerPin,OUTPUT);
}

void alarm(){
	for(int x=0;x<180;x++){
		//converte graus para radiando e depois obtém o valor do seno
		seno=(sin(x*3.1416/180));
		//gera uma frequência a partir do valor do seno
		frequencia = 2000+(int(seno*1000));
		tone(9,frequencia);
		delay(2);
	}
}

int tempo;
int notes, wholenote, divider, noteDuration;

/* // Imperial March
int melody[] = {

		NOTE_A4,-4, NOTE_A4,-4, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_F4,8, REST,8,
		NOTE_A4,-4, NOTE_A4,-4, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_F4,8, REST,8,
		NOTE_A4,4, NOTE_A4,4, NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16,

		NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,//4
		NOTE_E5,4, NOTE_E5,4, NOTE_E5,4, NOTE_F5,-8, NOTE_C5,16,
		NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,
		
		NOTE_A5,4, NOTE_A4,-8, NOTE_A4,16, NOTE_A5,4, NOTE_GS5,-8, NOTE_G5,16, //7 
		NOTE_DS5,16, NOTE_D5,16, NOTE_DS5,8, REST,8, NOTE_A4,8, NOTE_DS5,4, NOTE_D5,-8, NOTE_CS5,16,

		NOTE_C5,16, NOTE_B4,16, NOTE_C5,16, REST,8, NOTE_F4,8, NOTE_GS4,4, NOTE_F4,-8, NOTE_A4,-16,//9
		NOTE_C5,4, NOTE_A4,-8, NOTE_C5,16, NOTE_E5,2,

		NOTE_A5,4, NOTE_A4,-8, NOTE_A4,16, NOTE_A5,4, NOTE_GS5,-8, NOTE_G5,16, //7 
		NOTE_DS5,16, NOTE_D5,16, NOTE_DS5,8, REST,8, NOTE_A4,8, NOTE_DS5,4, NOTE_D5,-8, NOTE_CS5,16,

		NOTE_C5,16, NOTE_B4,16, NOTE_C5,16, REST,8, NOTE_F4,8, NOTE_GS4,4, NOTE_F4,-8, NOTE_A4,-16,//9
		NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,
	}; */

// Green Hill
int melody[] = {

  REST,2, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8, //1
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,8, NOTE_A4,8, NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 

  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_G4,4, NOTE_B4,8, //7
  NOTE_A4,4, NOTE_B4,8, NOTE_A4,4, NOTE_D4,2,
  REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,8, NOTE_A4,8, NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 

  REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8, //13
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_G4,4, NOTE_B4,8,
  NOTE_A4,4, NOTE_B4,8, NOTE_A4,4, NOTE_D4,8, NOTE_D4,8, NOTE_FS4,8,
  NOTE_E4,-1,
  REST,8, NOTE_D4,8, NOTE_E4,8, NOTE_FS4,-1,

  REST,8, NOTE_D4,8, NOTE_D4,8, NOTE_FS4,8, NOTE_F4,-1, //20
  REST,8, NOTE_D4,8, NOTE_F4,8, NOTE_E4,-1, //end 1

  //repeats from 1

  REST,2, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8, //1
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,8, NOTE_A4,8, NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 

  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_G4,4, NOTE_B4,8, //7
  NOTE_A4,4, NOTE_B4,8, NOTE_A4,4, NOTE_D4,2,
  REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,8, NOTE_A4,8, NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8,
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 

  REST,4, NOTE_D5,8, NOTE_B4,4, NOTE_D5,8, //13
  NOTE_CS5,4, NOTE_D5,8, NOTE_CS5,4, NOTE_A4,2, 
  REST,8, NOTE_B4,8, NOTE_B4,8, NOTE_G4,4, NOTE_B4,8,
  NOTE_A4,4, NOTE_B4,8, NOTE_A4,4, NOTE_D4,8, NOTE_D4,8, NOTE_FS4,8,
  NOTE_E4,-1,
  REST,8, NOTE_D4,8, NOTE_E4,8, NOTE_FS4,-1,

  REST,8, NOTE_D4,8, NOTE_D4,8, NOTE_FS4,8, NOTE_F4,-1, //20
  REST,8, NOTE_D4,8, NOTE_F4,8, NOTE_E4,8, //end 2
  NOTE_E4,-2, NOTE_A4,8, NOTE_CS5,8, 
  NOTE_FS5,8, NOTE_E5,4, NOTE_D5,8, NOTE_A5,-4,

};

void SetupSWimperialMarch(){
	tempo = 120;
	notes = sizeof(melody) / sizeof(melody[0]) / 2;
	wholenote = (60000 * 4) / tempo;
	divider = 0, noteDuration = 0;
}

void PlayMusic(){
	for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

		// calculates the duration of each note
		divider = melody[thisNote + 1];
		if (divider > 0) {
		// regular note, just proceed
		noteDuration = (wholenote) / divider;
		} else if (divider < 0) {
		// dotted notes are represented with negative durations!!
		noteDuration = (wholenote) / abs(divider);
		noteDuration *= 1.5; // increases the duration in half for dotted notes
		}

		// we only play the note for 90% of the duration, leaving 10% as a pause
		tone(buzzerPin, melody[thisNote], noteDuration*0.9);

		// Wait for the specief duration before playing the next note.
		delay(noteDuration);
		
		// stop the waveform generation before the next note.
		noTone(buzzerPin);
	}
}

void SetupGreenHill(){
	tempo = 140;

	notes = sizeof(melody) / sizeof(melody[0]) / 2;
	wholenote = (60000 * 4) / tempo;
	divider = 0, noteDuration = 0;
}

