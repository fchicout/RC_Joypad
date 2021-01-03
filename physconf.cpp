#include "physconf.h"

int pinSaveLog = 10;
int pin1 = 11;
int pin2 = 12;
int pin3 = 13;

int bin2int(int numvalues, ...)
{
    int total = 0;
    va_list values;
    va_start(values, numvalues);
 
    for(;numvalues > 0; numvalues--)
        if (!(digitalRead(va_arg(values, int))) )
            total += powint(2, numvalues-1);
 
    va_end(values);
    return total;
 
}
 
int powint(int base, int exponent)
{
    int result = 1;
    for(;exponent > 0; exponent--)
        result *= base;
    return result;
}

void configureDipSwitch() {
  pinMode(pinSaveLog, INPUT_PULLUP);
  pinMode(pin1, INPUT_PULLUP);
  pinMode(pin2, INPUT_PULLUP);
  pinMode(pin3, INPUT_PULLUP);
}

bool isSaveLogOn(){
    return bin2int(1, pinSaveLog);
}