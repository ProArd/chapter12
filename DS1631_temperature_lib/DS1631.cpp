
#include <Wire.h>
#include "DS1631.h"



DS1631::DS1631(uint8_t DS1631_ADDR)
{
  Wire.begin(); //Start i2c connection
  Wire.beginTransmission(DS1631_ADDR);
  Wire.write(0x22); //0x22 is the stop conversion command
  Wire.endTransmission();

  //Can start continuous converstion here  

}

DS1631::~DS1631(){
}

void DS1631::begin()
{
}

uint8_t getConfig(uint8_t DS1631_ADDR)
{
  Wire.beginTransmission(DS1631_ADDR);
  Wire.write(0xAC); //get configuration command
  Wire.endTransmission();
  Wire.requestFrom(DS1631_ADDR, (uint8_t) 1); //The configuration is one byte get it
  Wire.available();
  uint8_t config = Wire.read();
  Wire.endTransmission();
  return config;
}

void setConfig(uint8_t DS1631_ADDR, uint8_t config) //configuration options
{
  Wire.beginTransmission(DS1631_ADDR);
  Wire.write(0xAC); //get configuration command
  Wire.write(config); //configure with options
  Wire.endTransmission();
}

float DS1631::getTemp(uint8_t DS1631_ADDR) //0xAA command Read Temp, read 2 bytes, one shot tempuratur read
{
  Wire.beginTransmission(DS1631_ADDR);
  Wire.write(0xAA); // start reading temperature now
  Wire.endTransmission();
  Wire.requestFrom(DS1631_ADDR, (uint8_t) 2); //get the 2 byte twos compliment value back
  Wire.available();
  uint8_t Th = Wire.read(); //High Byte
  Wire.available();
  uint8_t Tl = Wire.read(); //Low Byte
  float temp = getTwosCompliment(Th,Tl);
  return temp;
}
/*
void DS1631::printTemp()
{
}
char* DS1631::getStrTemp()
{
  return "sad";
}
*/


float getTwosCompliment(uint8_t Th, uint8_t Tl)
{
  float num;
  //The sign but is 0x80
  if(Th >= 0x80)
  {
    num = (float) ((Th<<8 + Th) - 65536)*0.0625;
  }
  else
  {
    num = (float)(Th<<8 + Tl)*0.0625;
  }
  return num;
}

