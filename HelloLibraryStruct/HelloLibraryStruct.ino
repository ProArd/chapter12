/*
*
 * Hello Library Example
 *
 */

#include "HelloLibrary.h"

Position position;
Position my_position;
Position *pos = &my_position;
//struct Position* pos;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
//  day daypart;
  position.xx = 20;
  position.yy = 30;
  pos->xx = 120;
  pos->yy = 130;
  

  
  //*pos = &position;
  Serial.print(position.xx);
  Serial.print(" ");
  Serial.println(position.yy);
 // Serial.print("pos: ");
  Serial.print(pos->xx);
  Serial.print(" ");
  Serial.println(pos->yy);
  
  printHelloLibrary();
  startBlink(250);
/*
  Serial.print("Part of Day: ");
  Serial.println(MORNING);
  Serial.print("Other part of day: ");

  daypart = AFTERNOON;
  Serial.println(daypart);
  Serial.print("Position: X: ");
  Serial.print(position.xx);
  Serial.print(" Y: ");
  Serial.println(position.yy);
  */
  
  Position pp = movePosition(10,20);
  Serial.print(pp.xx);
  Serial.print(" ");
  Serial.println(pp.yy);
}

Position movePosition(int xx, int yy)
{
    position.xx += xx;
    position.yy += yy;
    return position;
}

