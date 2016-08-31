// see pg. 1233 for pin, module and genrator
// 
//  Module 0 , Generator 0
//     pin 1 = PB6  = M0PWM0 (PWM 0UT 0 )
//     4 = PB7      =  M0PWM1 (PWM OUT 1 )
//
//   
//
//
//
//

#include "tm4c123gh6pm.h"
#include "servo.h"

int main()
{
  servo s1,s2;
  s1.pinNo = 1; //set pin no to get pwm on that
  s2.pinNo = 4;
  
  Servoinit(s1);
  Servoinit(s2);
  
  ServoMove(s1,180); //servomotor , angle of rotation in degree
  ServoMove(s2,180);
  
  
  return 0;
  
}