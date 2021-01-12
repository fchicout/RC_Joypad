#include "joypad.h"

int throttlePin = A4;
int yawPin = A5;
int pitchPin = A6;
int rollPin = A7;


void configureJoyPads(){
    pinMode(throttlePin, INPUT);
    pinMode(yawPin, INPUT);
    pinMode(pitchPin, INPUT);
    pinMode(rollPin, INPUT);
}

int throttle(){
    return map(analogRead(throttlePin), 0, 1023, 0, 255);
}

int yaw(){
    return map(analogRead(yawPin), 0, 1023, 0, 255);
}

int pitch(){
    return map(analogRead(pitchPin), 0, 1023, 0, 255);
}

int roll(){
    return map(analogRead(rollPin), 0, 1023, 0, 255);
}