/*
*
 * HelloLibrary cpp implmentation file
 *
 */

#include "HelloLibrary.h"



void startBlink(int duration)
{
  digitalWrite(LED_PIN, HIGH);
  delay(duration);
  digitalWrite(LED_PIN, LOW);
  delay(duration); 
}

void printHelloLibrary() 
{
  Serial.println("Hello Library");
}


