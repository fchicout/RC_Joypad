#pragma once

#include <Arduino.h>

int bin2int(int numvalues, ...);
int powint(int base, int exponent);
bool isSaveLogOn();
void configureDipSwitch();