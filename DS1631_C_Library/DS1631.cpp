
#include <Wire.h>
#include "DS1631.h"


uint8_t _Temp[2];

DS1631::DS1631(uint8_t _ADDR)
{
  //Wire.begin(); //Start i2c connection
  //  stopConversion( _ADDR);

  //Can start continuous converstion here  
  // startConversion( _ADDR);
}

DS1631::~DS1631(){
}

void DS1631::begin()
{
}

void DS1631::stopConversion(uint8_t _ADDR)
{
  Wire.beginTransmission(_ADDR);
  Wire.write(0x22); //stop conversion command
  Wire.endTransmission();
}

void DS1631::startConversion(uint8_t _ADDR)
{
  Wire.beginTransmission(_ADDR);
  Wire.write(0x51); //start conversion command
  Wire.endTransmission();
}

byte DS1631::getConfig(uint8_t _ADDR)
{
  byte config;

  stopConversion(_ADDR);
  Wire.beginTransmission(_ADDR);
  Wire.write(0xAC); //get configuration command
  Wire.endTransmission();
  Wire.requestFrom(_ADDR, (uint8_t) 0x01); //The configuration is one byte get it
  while (Wire.available())
  {
    config = Wire.read();
  }

  Wire.endTransmission();
  startConversion(_ADDR);
  return config;
}

void DS1631::setConfig(uint8_t _ADDR, uint8_t config)//configuration options
{
  stopConversion(_ADDR);
  Wire.beginTransmission(_ADDR);
  Wire.write(0xAC); //get configuration command
  Wire.write(config); //configure with options
  Wire.endTransmission();
  startConversion(_ADDR);
}

float DS1631::getTemp(uint8_t _ADDR) //0xAA command Read Temp, read 2 bytes, one shot tempuratur read
{
  unsigned char _Temp[2];
  int count = 0;

  Wire.beginTransmission(_ADDR);
  Wire.write(0xAA); // start reading temperature now
  Wire.endTransmission();
  Wire.requestFrom(_ADDR,  (uint8_t)2); //get the 2 byte two's complement value back

  while(Wire.available())
  {
    _Temp[count] = Wire.read();
    count++;
  }


  Serial.print("Th: ");
  Serial.print(_Temp[0]);
  Serial.print(" Tl: ");
  Serial.println(_Temp[1]);
  float temp = getTwosCompliment(_Temp[0],_Temp[1]);
  return temp;
}

float DS1631::getTwosCompliment(int Th,  int Tl)
{
  float num = 0.0;
 //Acceptable, but only 2 3 significant digits
 //float  altnum = ((((short)Th<<8) | (short)Tl)>>6) / 4.0;  
   
  Tl = Tl >> 4; // shift out the last 4 bits because they are 0
  if (Th & 0x80) // Compare the sign bit = 1, then less than 0;
  {
    Th = Th - 256;
  }
  // Float conversion
  num = (float) (Th + Tl*0.0625);
 
  return  num;
}




