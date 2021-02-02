#pragma once

#include <Arduino.h>

class Mic{
    private:
        int micPin = A0;
        int micVal = 0;
    public:
        Mic();
        void readMic();
};