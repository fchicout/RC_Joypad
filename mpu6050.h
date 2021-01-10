#pragma once

#include <Arduino.h>
#include <Wire.h>
#include "sdcard.h"

void configureMPU6050();
void loadMPUData();

float getTemperature();
float* getAccelVect();
float* getGyroVect();

void logMPU();