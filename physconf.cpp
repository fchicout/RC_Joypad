#include "physconf.h"


PhysConfig::PhysConfig() {
    pinMode(dipPinSaveLog, INPUT_PULLUP);
    pinMode(dipPin1, INPUT_PULLUP);
    pinMode(dipPin2, INPUT_PULLUP);
    pinMode(dipPin3, INPUT_PULLUP);

    pinMode(throttlePin, INPUT);
    pinMode(yawPin, INPUT);
    pinMode(pitchPin, INPUT);
    pinMode(rollPin, INPUT);
}

int PhysConfig::bin2int(int numvalues, ...)
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
 
int PhysConfig::powint(int base, int exponent)
{
    int result = 1;
    for(;exponent > 0; exponent--)
        result *= base;
    return result;
}

bool PhysConfig::isSaveLogOn(){
    return bin2int(1, dipPinSaveLog);
}

bool PhysConfig::isLowEnergyOn(){
    return digitalRead(pinLowEnergy);
}

void PhysConfig::startLowEnergyMode(){
    attachInterrupt(digitalPinToInterrupt(pinLowEnergy), stopLowEnergyMode, LOW);
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    delay(500);
    sleep_cpu();
}

void PhysConfig::stopLowEnergyMode(){
    sleep_disable();
    detachInterrupt(digitalPinToInterrupt(pinLowEnergy));
}

int PhysConfig::throttle(){
    return map(analogRead(throttlePin), 0, 1023, 0, 255);
}

int PhysConfig::yaw(){
    return map(analogRead(yawPin), 0, 1023, 0, 255);
}

int PhysConfig::pitch(){
    return map(analogRead(pitchPin), 0, 1023, 0, 255);
}

int PhysConfig::roll(){
    return map(analogRead(rollPin), 0, 1023, 0, 255);
}