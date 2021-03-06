#pragma once

#include <Arduino.h> 
#include <avr/sleep.h>

class PhysConfig{
private:
    int dipPinSaveLog = 10;
    int dipPin1 = 11;
    int dipPin2 = 12;
    int dipPin3 = 13;
    int throttlePin = A4;
    int yawPin = A5;
    int pitchPin = A6;
    int rollPin = A7;
    static const int pinLowEnergy = 14;
    int bin2int(int numvalues, ...);
    int powint(int base, int exponent);
public:
    PhysConfig();
    bool isSaveLogOn();
    bool isLowEnergyOn();
    void startLowEnergyMode();
    static void stopLowEnergyMode();
    int throttle();
    int yaw();
    int pitch();
    int roll();
};
