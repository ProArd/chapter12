
#include <Wire.h>
#include "DS1631.h"


uint8_t _temp[2];
uint8_t _addr;

DS1631::DS1631(uint8_t _ADDR)
{
  //Cannot user Wire.begin() here because a declarition time it is unavailable.
  //Shift the address that way the user can use the address as is from the Datasheet
  _addr = _ADDR >> 1;
}

DS1631::~DS1631(){
}

void DS1631::begin()
{
}

void DS1631::stopConversion()
{
  Wire.beginTransmission(_addr);
  Wire.write(0x22); //stop conversion command
  Wire.endTransmission();
}

void DS1631::startConversion()
{
  Wire.beginTransmission(_addr);
  Wire.write(0x51); //start conversion command
  Wire.endTransmission();
}

byte DS1631::getConfig()
{
  byte config;

  stopConversion();
  Wire.beginTransmission(_addr);
  Wire.write(0xAC); //get configuration command
  Wire.endTransmission();
  Wire.requestFrom(_addr, (uint8_t) 0x01); //The configuration is one byte get it
  while (Wire.available())
  {
    config = Wire.read();
  }

  Wire.endTransmission();
  startConversion();
  return config;
}

void DS1631::setConfig(uint8_t config)//configuration options
{
  stopConversion();
  Wire.beginTransmission(_addr);
  Wire.write(0xAC); //get configuration command
  Wire.write(config); //configure with options
  Wire.endTransmission();
  startConversion();
}

float DS1631::getTemp() //0xAA command Read Temp, read 2 bytes, one shot tempuratur read
{
  unsigned char _temp[2];
  int count = 0;

  Wire.beginTransmission(_addr);
  Wire.write(0xAA); // start reading temperature now
  Wire.endTransmission();

  delay(750); //750ms reqiured to get 12 bit resolution temperature
  Wire.requestFrom(_addr,  (uint8_t)2); //get the 2 byte two's complement value back
  while(Wire.available())
  {
    _temp[count] = Wire.read();
    count++;
  }
  float temp = calcTemp(_temp[0],_temp[1]);
  return temp;
}

float DS1631::calcTemp(int msb,  int lsb)
{
  float num = 0.0;
  //Acceptable, but only 2 3 significant digits
   // num = ((((short)msb<<8) | (short)lsb)>>6) / 4.0;  
  lsb = lsb >> 4; // shift out the last 4 bits because they are 0
  if (msb & 0x80) // Compare the sign bit = 1, then less than 0;
  {
    msb = msb - 256;
  }
  // Float conversion
  num = (float) (msb + lsb*0.0625);
  return  num;
}





