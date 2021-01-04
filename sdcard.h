#pragma once

#include <Arduino.h>
#include <SD.h>
#include <SPI.h>

void diagSDCard();
void configureSDCard();
void appendToLog(char* logName, char* data);