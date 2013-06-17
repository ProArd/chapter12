#include <Wire.h>
#include "DS1631.h"

// PIN adresses are set to GND
uint8_t DS1631_ADDR = 0x90; // 0x90 >> 1
char temperature[6] = {'00.000'};

// SETUP
void setup(){
    
  // Setup Serial connection
  Serial.begin(9600);
  Serial.println("");
  Serial.println("-----------------------------------");
  Serial.println("DS1631 test: Temp. sensor");
  Serial.println("-----------------------------------");
  Serial.println("");
  
  setUpDS1631() ;
 
}

// Main Loop
void loop(){
  
  getTemp(temperature);

}

void setUpDS1631() 
{
  Wire.begin();             // join I2C bus

  // Stop conversion to be able to modify "Access Config" Register
  Wire.beginTransmission(DS1631_ADDR);
  Wire.write((int)(0x22)); // Stop conversion
  Wire.endTransmission();  
    
  // Read "Access Config" regsiter
  Wire.beginTransmission(DS1631_ADDR);
  Wire.write((int)(0xAC)); // @AC : Acces Config
  Wire.endTransmission();
  Wire.requestFrom(DS1631_ADDR,(uint8_t)1); //Reade 1 byte
  Wire.available();
  int AC = Wire.read(); // receive a byte

  Serial.print("Acces Config (Before): "); Serial.print(AC);  Serial.println("");
    
  // WRITE into "Access Config" Register
  Wire.beginTransmission(DS1631_ADDR);
  Wire.write(0xAC); // @AC : Acces Config
  Wire.write(0x0C); // Continuous conversion & 12 bits resolution
  Wire.endTransmission();
    
  // READ "Access Config" register
  Wire.beginTransmission(DS1631_ADDR);
  Wire.write((int)(0xAC)); // @AC : Acces Config
  Wire.endTransmission();
  Wire.requestFrom(DS1631_ADDR,(uint8_t)1);
  Wire.available();
  AC = Wire.read();

  Serial.print("Acces Config (AFTER): "); Serial.print(AC);  Serial.println("");
  
  // START conversion to get T°
  Wire.beginTransmission(DS1631_ADDR);
  Wire.write((int)(0x51)); // Start Conversion
  Wire.endTransmission(); 
}

void getTemp(char *temp)
{
  
   //READ T°
  Wire.beginTransmission(DS1631_ADDR);
  Wire.write((int)(0xAA)); // @AA : Temperature
  Wire.endTransmission();
  Wire.requestFrom(DS1631_ADDR,(uint8_t) 2); // READ 2 bytes
  Wire.available(); // 1st byte
  int Th = Wire.read(); // receive a byte
  Wire.available(); // 2nd byte
  int Tl = Wire.read(); // receive a byte


  // T° processing
  if(Th>=0x80) //if sign bit is set, then temp is negative
  Th = Th - 256;
  int T_dec=(10*(100*(Tl/16)))/16; // decimal part of the T°

  // Display T° on "Serial Monitor"
  Serial.print("Temperature : ");
  Serial.print(Th);   Serial.print(".");
  if (T_dec<10)   Serial.print("0");
  if (T_dec<100)   Serial.print("0");
  Serial.print(T_dec);   Serial.print(" degC / ");
  Serial.print("Th register: "); Serial.print(Th);  Serial.print(" / ");
  Serial.print("Tl register: "); Serial.print(Tl);  Serial.println("");
  
  // Wait 1s before restart
  delay(1000); 
}

