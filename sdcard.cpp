#include "sdcard.h"

int sdPin = 53;

void configureSDCard(){
    if (SD.begin()) {
        Serial.println("SD Card pronto para uso.");
    } else {
        Serial.println("Falha na inicialização do SD Card.");
        return;
    }
}