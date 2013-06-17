/*
*
 * HelloLibrary Header file
 *
 */
#ifndef HelloLibrary_h
#define HelloLibrary_h



#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#include "pins_arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#endif



#define LED_PIN 1

struct Position {
  int xx;
  int yy;
  int zz;
};

void printHelloLibrary();

void startBlink(int duration);

#endif


