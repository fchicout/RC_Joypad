#pragma once

#include <SPI.h>
#include "RF24.h"
#include "printf.h"

void configureRadio();


void receiveData();
void transmitData();

void changeRoles();