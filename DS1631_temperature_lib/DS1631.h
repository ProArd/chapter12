/*
*
 * DS1631 library object.
 * Articles used in reference for this:
 * http://www.maxim-ic.com/app-notes/index.mvp/id/135
 * http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1221926830
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

class DS1631 : public Print 
{
public:
  DS1631(uint8_t DS1631_ADDR);
  ~DS1631();
  void begin();
  uint8_t getConfig(uint8_t DS1631_ADDR);
  void setConfig(uint8_t DS1631_ADDR, uint8_t config);
  float getTemp(uint8_t DS1631_ADDR);
  float getTripHigh(uint8_t DS1631_ADDR);
  void setTripHigh(uint8_t DS1631_ADDR);
  float getTripLow(uint8_t DS1631_ADDR);
  void setTripLow(uint8_t DS1631_ADDR);

  void printTemp();
  char* getStrTemp();
  using Print::write;

private:  
  float getTwosCompliment(uint8_t th, uint8_t tl);
  };
#endif




