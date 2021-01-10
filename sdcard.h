#pragma once

#include <Arduino.h>
#include <SD.h>
#include <SPI.h>
#include "physconf.h"

void diagSDCard();
void configureSDCard();

void logMessage(int severity, char* file, char* messageData);
