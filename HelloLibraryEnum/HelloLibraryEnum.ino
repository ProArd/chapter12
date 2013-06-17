/*
*
 * Hello Library Example
 *
 */

#include "HelloLibrary.h"

day daypart = AFTERNOON;


void setup()
{
  Serial.begin(9600);
}

void loop()
{
  
  printHelloLibrary();
  startBlink(250);
  Serial.print("Part of Day: ");
  Serial.println(MORNING);
  Serial.print("Other part of day: ");
  Serial.println(daypart);
  Serial.print("Next part: ");
  daypart = getNextPart(daypart);
  Serial.println(daypart);

}

day getNextPart(day dd)
{
 dd = dd + 1;
return dd; 
  
}
