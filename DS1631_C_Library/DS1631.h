/*
*
 * DS1631 library object.
 * Articles used in reference for this:
 * http://www.maxim-ic.com/app-notes/index.mvp/id/135
 * http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1221926830
 * http://www.peyregne.info/wp/?p=211
 */
#ifndef DS1631_h
#define DS1631_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#include "pins_arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#endif

class DS1631 
{
public:
  DS1631(uint8_t);
  ~DS1631();
  void begin( );
  byte getConfig(uint8_t );
  void setConfig(uint8_t ,uint8_t );
  float getTemp(uint8_t );
  void stopConversion(uint8_t );
  void startConversion(uint8_t );

  float getTripHigh(uint8_t );
  void setTripHigh(uint8_t );
  float getTripLow(uint8_t );
  void setTripLow(uint8_t );


  void printTemp();
  char* getStrTemp();


private:  
  float getTwosCompliment(int, int);
};
#endif





