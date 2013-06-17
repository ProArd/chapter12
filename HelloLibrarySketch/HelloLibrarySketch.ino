/*
*
 * Hello Library Example
 *
 */

#include "HelloLibrary.h"

//enum {MORNING, AFTERNOON, EVENING, NIGHT};

enum day {MORNING, AFTERNOON, EVENING, NIGHT};

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  printHelloLibrary();
  startBlink(1000);
  Serial.print("Part of Day: ");
  Serial.println(MORNING);
  Serial.print("Other part of day: ");
  day daypart;
  Serial.println(daypart);
}

