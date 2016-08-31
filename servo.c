
#include <stdbool.h>
#include <stdint.h>
#include "hw_memmap.h"
#include "gpio.h"
#include "pin_map.h"
#include "pwm.h"
#include "sysctl.h"
#include "tm4c123gh6pm.h"
#include "servo.h"

#define GPIO_PB6_M0PWM0         0x00011804   //pin 1 , see data sheet at pg. 1233
#define GPIO_PB7_M0PWM1         0x00011C04   //pin 4


void Servoinit(servo s)//which pwm pin to initialize
{
 
  // Set the PWM clock to the system clock/8.
    SysCtlPWMClockSet(SYSCTL_PWMDIV_8);
    
  int p  = s.pinNo;
  
  switch(p)
  {
  case 1: SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0); // The PWM peripheral must be enabled for use.
          SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB); // GPIO port B needs to be enabled so these pins can be used.
         
             // Configure the GPIO pin muxing to select PWM00 functions for these pins.
            // This step selects which alternate function is available for these pins.
           // This is necessary if your part supports GPIO pin function muxing.
           GPIOPinConfigure(GPIO_PB6_M0PWM0);
          
            // Configure the PWM function for this pin.
            // Consult the data sheet to see which functions are allocated per pin.
            // TODO: change this to select the port/pin you are using.
            GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_6);
          
            // Configure the PWM0 to count up/down without synchronization.
            PWMGenConfigure(PWM0_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN |
                    PWM_GEN_MODE_NO_SYNC);
            
           // Set the PWM period to 50Hz.  To calculate the appropriate parameter
          // use the following equation: N = (1 / f) * SysClk.  Where N is the
         // function parameter, f is the desired frequency, and SysClk is the
         // system clock frequency.
         // In this case you get: (1 / 50Hz) * (16MHz/8) = 40000 cycles.  Note that
         // the maximum period you can set is 2^16.
    
          PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, 40000);   
          break;
    
  case 4:SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0); // The PWM peripheral must be enabled for use.
          SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB); // GPIO port B needs to be enabled so these pins can be used.
         
             // Configure the GPIO pin muxing to select PWM00 functions for these pins.
            // This step selects which alternate function is available for these pins.
           // This is necessary if your part supports GPIO pin function muxing.
           GPIOPinConfigure(GPIO_PB7_M0PWM1);
          
            // Configure the PWM function for this pin.
            // Consult the data sheet to see which functions are allocated per pin.
            // TODO: change this to select the port/pin you are using.
            GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_7);
          
            // Configure the PWM0 to count up/down without synchronization.
            PWMGenConfigure(PWM0_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN |
                    PWM_GEN_MODE_NO_SYNC);
            
           // Set the PWM period to 50Hz.  To calculate the appropriate parameter
          // use the following equation: N = (1 / f) * SysClk.  Where N is the
         // function parameter, f is the desired frequency, and SysClk is the
         // system clock frequency.
         // In this case you get: (1 / 50Hz) * (16MHz/8) = 40000 cycles.  Note that
         // the maximum period you can set is 2^16.
    
          PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, 40000);
    break;
    
    
  }
  
  
}


void ServoMove(servo s , float deg)
{
  // Duty cycle = (deg/90) + 0.4 in msec
  
  float duty = ((deg/90) + 0.4) ;
  
  //1 msec = 2k ticks
  
  float ticks = duty*2; //in kilo
  
   float divfact = (40/ticks);  
   
   int p  = s.pinNo;
  
  switch(p)
  {
  case 1 : PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0,
                     PWMGenPeriodGet(PWM0_BASE, PWM_GEN_0) / divfact);
           
           
           PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT, true);
           PWMGenEnable(PWM0_BASE, PWM_GEN_0);
           SysCtlDelay((SysCtlClockGet() * 0.8) / 3);
           PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT, false);
    break;
    
    case 4 : PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1,
                     PWMGenPeriodGet(PWM0_BASE, PWM_GEN_0) / divfact);
           
           
           PWMOutputState(PWM0_BASE, PWM_OUT_1_BIT, true);
           PWMGenEnable(PWM0_BASE, PWM_GEN_0);
           SysCtlDelay((SysCtlClockGet() * 0.8) / 3);
           PWMOutputState(PWM0_BASE, PWM_OUT_1_BIT, false);
    break;
  
  }
  
}
