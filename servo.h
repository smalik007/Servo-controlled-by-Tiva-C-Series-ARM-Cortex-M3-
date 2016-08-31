//////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//   This library is for controlling multiple servos simultaneously using 16 pwm pin
//    of Tiva c Series launchpad TM4C123GH6PM, This Library also require some othe
//   libraries by Ti and can be downloaded from here :http://www.ti.com/tool/sw-tm4c
//  
//    Created By : Mohd Suhail
//    Date       : 30.sept.2016
//
//////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
// 
//
//     see pg. 1233 for pin No. on TM4C123GH6PM data sheet, module and genrator
// 
//     PWM Module 0 
//     
//     Generator 0
//      pin 1 = PB6      =  M0PWM0 (PWM 0UT 0 )
//         4 = PB7       =  M0PWM1 (PWM OUT 1 )
//  
//     Generator 1
//      pin 58 = PB4      =  M0PWM2 (PWM 0UT 2 )
//          57   = PB5    =  M0PWM3 (PWM OUT 3 )
//   
//    Generator 2
//      pin 59 = PE4     =  M0PWM4 (PWM 0UT 4)
//          60 = PE5     =  M0PWM5 (PWM OUT 5)
//
//    Generator 3
//      pin 16 = PC4     =  M0PWM6 (PWM 0UT 6)
//          15 = PC5     =  M0PWM7 (PWM OUT 7)
//
//
//     PWM Module 1 
//     
//     Generator 0
//      pin 61 = PD0      =  M1PWM0 (PWM 0UT 0 )
//         62 = PD1        =  M1PWM1 (PWM OUT 1 )
//  
//     Generator 1
//      pin 23 = PA6      =  M1PWM2 (PWM 0UT 2 )
//          24 = PA7    =  M1PWM3 (PWM OUT 3 )
//   
//    Generator 2
//      pin 28 = PF0     =  M1PWM4 (PWM 0UT 4)
//          29 = PF1     =  M1PWM5 (PWM OUT 5)
//
//    Generator 3
//      pin 30 = PF2     =  M1PWM6 (PWM 0UT 6)
//          31 = PF3     =  M1PWM7 (PWM OUT 7)
/////////////////////////////////////////////////////////////////////////




#ifndef __SERVO_H__
#define __SERVO_H__

struct servo
{
 int pinNo;
};

void Servoinit(servo s);
void ServoMove(servo s ,float deg);
void delay();
void ServoStop(servo s);


#endif
