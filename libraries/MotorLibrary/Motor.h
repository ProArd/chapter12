#ifndef Motor_h
#define Motor_h


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#include "pins_arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#endif


#define motor1Dir 7
#define motor2Dir 8
#define motor1PWM 9
#define motor2PWM 10
#define motor1Enable 11
#define motor2Enable 12


class Motor
{
 public:
    Motor();
    ~Motor();
    void begin();
    void setMotorVel(int dirPin, int pwmPin, int velocity);
    void setLeftMotorSpeed(int velocity);
    void setRightMotorSpeed(int velocity);
    
 private: 
  
};
#endif
