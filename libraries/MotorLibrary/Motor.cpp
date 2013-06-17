
#include "Motor.h"

Motor::Motor()
{
  pinMode(motor1Dir, OUTPUT);
  pinMode(motor2Dir, OUTPUT);

  pinMode(motor1Enable, OUTPUT);
  pinMode(motor2Enable, OUTPUT);
  digitalWrite(motor1Enable,HIGH);
  digitalWrite(motor2Enable,HIGH);
  setLeftMotorSpeed(0); // make sure the motors are stopped
  setRightMotorSpeed(0);
}

Motor::~Motor() {}
void begin()
{
}

void Motor::setMotorVel(int dirPin, int pwmPin, int velocity)
{
  if (velocity >= 255) 
  {
    velocity = 255;
  }
  if (velocity <= -255)
  {
    velocity = -255;
  }

  if (velocity == 0)
  {
    digitalWrite(dirPin, HIGH);
    digitalWrite(pwmPin, HIGH);
  }
  else if(velocity <0){ // Reverse
    digitalWrite(dirPin, HIGH);
    analogWrite(pwmPin, 255+velocity);
  }
  else if(velocity >0){ // Forward
    digitalWrite(dirPin,LOW);
    analogWrite(pwmPin, velocity);
  }

}


void Motor::setLeftMotorSpeed(int velocity)
{
  //Serial.print("Set Left: ");
  //Serial.println(velocity);
  setMotorVel(motor1Dir, motor1PWM, -velocity);

}

void Motor::setRightMotorSpeed(int velocity)
{
  //Serial.print("Set Right: ");
  //Serial.println(velocity);
  setMotorVel(motor2Dir, motor2PWM, -velocity);
}

