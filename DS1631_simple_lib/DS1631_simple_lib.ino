#include <Wire.h>
#include "DS1631.h"

uint8_t conf = 0x0C;
uint8_t dev1 = 0x90 >> 1;  
  
DS1631 Tmp(dev1); //Wire.begin hasn't happened yet

void setup()
{
  Serial.println("Setup: Start");
//  uint8_t _ADDR = 0x90;
  Serial.begin(9600);
  Wire.begin();
  
  //stop conversion
 /*
  Wire.beginTransmission(dev1);
  Wire.write(0x22); //stop conversion command
  Wire.endTransmission();
  (/
  */
  
  Tmp.stopConversion(dev1);
  
  //get current configuration:
  
  Wire.beginTransmission(dev1);
  Wire.write(0xAC); // @AC : Acces Config
  Wire.endTransmission();
  Wire.requestFrom(dev1,(uint8_t)1); //Reade 1 byte
  Wire.available();
  int AC = Wire.read(); // receive a byte
  Serial.print("Device: ");
  Serial.print(0x90);
  Serial.print(" : " );
  Serial.println(dev1);
  Serial.print("Manual Read: ");
  Serial.print(AC);
  Serial.print(" Hex: ");
  Serial.print(AC, HEX);
  Serial.print(" BIN: ");
  Serial.println(AC, BIN);

    // WRITE into "Access Config" Register
  Wire.beginTransmission(dev1);
  Wire.write(0xAC); // @AC : Acces Config
  Wire.write(0x0C); // Continuous conversion & 12 bits resolution
  Wire.endTransmission();
  
  
  Serial.print("Tmp current config: ");
  int config_b = Tmp.getConfig(dev1);
  Serial.print(config_b,DEC);
  Serial.print(" Hex: ");
  Serial.print(config_b, HEX);
  Serial.print(" BIN: ");
  Serial.println(config_b, BIN);
  
  Serial.print("Tmp requested config: ");
  Serial.print(conf,DEC);
  Serial.print(" Hex: ");
  Serial.print(conf, HEX);
  Serial.print(" BIN: ");
  Serial.println(conf, BIN);
  
  Tmp.setConfig(dev1, conf);

  config_b = Tmp.getConfig(dev1);
  Serial.print("Config: ");
  Serial.print(config_b,DEC);
  Serial.print(" Hex: ");
  Serial.print(config_b, HEX);
  Serial.print(" BIN: ");
  Serial.println(config_b, BIN);
  Serial.println("Setup: Complete");
}

void loop()
{

  Serial.print("TempC: ");
  float temp = Tmp.getTemp(dev1);
  Serial.print(temp, 4);
  Serial.print(" tempF: ");
  Serial.println((temp*9/5) + 32);;
  delay(1000); 
}


