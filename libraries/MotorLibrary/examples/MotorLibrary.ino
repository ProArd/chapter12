
#define motor1Dir 7
#define motor2Dir 8
#define motor1PWM 9
#define motor2PWM 10
#define motor1Enable 11
#define motor2Enable 12

#include "Motor.h"

Motor motor;


void setup()
{
  //motor.begin();
  
  motor.setRightMotorSpeed(255); 
  motor.setLeftMotorSpeed(-255);
  delay(500);
  motor.setRightMotorSpeed(-255); 
  motor.setLeftMotorSpeed(255);
  delay(500);
  motor.setRightMotorSpeed(0); 
  motor.setLeftMotorSpeed(0); 

}

void loop()
{
  //Go Forward 5 secs
  motor.setRightMotorSpeed(255); 
  motor.setLeftMotorSpeed(255); 
  delay(5000);
  //Stop
  motor.setRightMotorSpeed(0); 
  motor.setLeftMotorSpeed(0); 

  //loop here forever.
  while(1);

}



