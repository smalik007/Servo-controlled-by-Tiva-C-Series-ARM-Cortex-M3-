
#include <stdbool.h>
#include <stdint.h>
#include "hw_memmap.h"
#include "gpio.h"
#include "pin_map.h"
#include "pwm.h"
#include "sysctl.h"
#include "tm4c123gh6pm.h"
#include "servo.h"




void Servoinit(servo s)//which pwm pin to initialize
{
 
  // Set the PWM clock to the system clock/8.
    SysCtlPWMClockSet(SYSCTL_PWMDIV_8);
     
  switch(s.pinNo)
  {
    //PWM module 0
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
    
  case 4:SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0); 
         SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB); 
         GPIOPinConfigure(GPIO_PB7_M0PWM1);
         GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_7);
         PWMGenConfigure(PWM0_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN |
                    PWM_GEN_MODE_NO_SYNC);
            
         PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, 40000);
         break;
    
    
  case 58 :SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0); 
               SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB); 
               GPIOPinConfigure(GPIO_PB4_M0PWM2);
               GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_4);
               PWMGenConfigure(PWM0_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN |
                    PWM_GEN_MODE_NO_SYNC);
            
               PWMGenPeriodSet(PWM0_BASE, PWM_GEN_1, 40000);
               break;
    
  case 57 :SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0); 
               SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB); 
               GPIOPinConfigure(GPIO_PB5_M0PWM3);
               GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_5);
               PWMGenConfigure(PWM0_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN |
                    PWM_GEN_MODE_NO_SYNC);
            
               PWMGenPeriodSet(PWM0_BASE, PWM_GEN_1, 40000);
               break;
               
   case 59 :SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0); 
               SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE); 
               GPIOPinConfigure(GPIO_PE4_M0PWM4);
               GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_4);
               PWMGenConfigure(PWM0_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN |
                    PWM_GEN_MODE_NO_SYNC);
            
               PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 40000);
               break;
               
   case 60 :SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0); 
               SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE); 
               GPIOPinConfigure(GPIO_PE5_M0PWM5);
               GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_5);
               PWMGenConfigure(PWM0_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN |
                    PWM_GEN_MODE_NO_SYNC);
            
               PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, 40000);
               break;
               
  case 16 :SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0); 
               SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC); 
               GPIOPinConfigure(GPIO_PC4_M0PWM6);
               GPIOPinTypePWM(GPIO_PORTC_BASE, GPIO_PIN_4);
               PWMGenConfigure(PWM0_BASE, PWM_GEN_3, PWM_GEN_MODE_DOWN |
                    PWM_GEN_MODE_NO_SYNC);
            
               PWMGenPeriodSet(PWM0_BASE, PWM_GEN_3, 40000);
               break;
               
  case 15 :SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0); 
               SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC); 
               GPIOPinConfigure(GPIO_PC5_M0PWM7);
               GPIOPinTypePWM(GPIO_PORTC_BASE, GPIO_PIN_5);
               PWMGenConfigure(PWM0_BASE, PWM_GEN_3, PWM_GEN_MODE_DOWN |
                    PWM_GEN_MODE_NO_SYNC);
            
               PWMGenPeriodSet(PWM0_BASE, PWM_GEN_3, 40000);
               break;
               
  
    //PWM module 1
  case 61: SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1); 
          SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD); 
          GPIOPinConfigure(GPIO_PD0_M1PWM0);
          GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_0);
          PWMGenConfigure(PWM1_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN |
                    PWM_GEN_MODE_NO_SYNC);
           
          PWMGenPeriodSet(PWM1_BASE, PWM_GEN_0, 40000);   
          break;
    
  case 62:SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1); 
         SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD); 
         GPIOPinConfigure(GPIO_PD1_M1PWM1);
         GPIOPinTypePWM(GPIO_PORTD_BASE, GPIO_PIN_1);
         PWMGenConfigure(PWM1_BASE, PWM_GEN_0, PWM_GEN_MODE_DOWN |
                    PWM_GEN_MODE_NO_SYNC);
            
         PWMGenPeriodSet(PWM1_BASE, PWM_GEN_0, 40000);
         break;
    
    
  case 23 :SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1); 
               SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA); 
               GPIOPinConfigure(GPIO_PA6_M1PWM2);
               GPIOPinTypePWM(GPIO_PORTA_BASE, GPIO_PIN_6);
               PWMGenConfigure(PWM1_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN |
                    PWM_GEN_MODE_NO_SYNC);
            
               PWMGenPeriodSet(PWM1_BASE, PWM_GEN_1, 40000);
               break;
    
  case 24 :SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1); 
               SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA); 
               GPIOPinConfigure(GPIO_PA7_M1PWM3);
               GPIOPinTypePWM(GPIO_PORTA_BASE, GPIO_PIN_7);
               PWMGenConfigure(PWM1_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN |
                    PWM_GEN_MODE_NO_SYNC);
            
               PWMGenPeriodSet(PWM1_BASE, PWM_GEN_1, 40000);
               break;
               
   case 28 :SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1); 
               SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); 
               GPIOPinConfigure(GPIO_PF0_M1PWM4);
               GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_0);
               PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN |
                    PWM_GEN_MODE_NO_SYNC);
            
               PWMGenPeriodSet(PWM1_BASE, PWM_GEN_2, 40000);
               break;
               
   case 29 :SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1); 
               SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); 
               GPIOPinConfigure(GPIO_PF1_M1PWM5);
               GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_1);
               PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_DOWN |
                    PWM_GEN_MODE_NO_SYNC);
            
               PWMGenPeriodSet(PWM1_BASE, PWM_GEN_2, 40000);
               break;
               
  case 30 :SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1); 
               SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); 
               GPIOPinConfigure(GPIO_PF2_M1PWM6);
               GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_2);
               PWMGenConfigure(PWM1_BASE, PWM_GEN_3, PWM_GEN_MODE_DOWN |
                    PWM_GEN_MODE_NO_SYNC);
            
               PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3, 40000);
               break;
               
  case 31 :SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1); 
               SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); 
               GPIOPinConfigure(GPIO_PF3_M1PWM7);
               GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_3);
               PWMGenConfigure(PWM1_BASE, PWM_GEN_3, PWM_GEN_MODE_DOWN |
                    PWM_GEN_MODE_NO_SYNC);
            
               PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3, 40000);
               break;   
               
               
    
  }
  
  
}


void ServoMove(servo s , float deg)
{
  // Duty cycle = (deg/90) + 0.4 in msec
  
  float duty = ((deg/90) + 0.4) ;
  
  //1 msec = 2k ticks
  
  float ticks = duty*2; //in kilo
  
   float divf = (40/ticks);  
   
   int divfact = (int)divf;
  
  switch(s.pinNo)
  {
    //PWM module 0 
  case 1 : PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0,
                     PWMGenPeriodGet(PWM0_BASE, PWM_GEN_0) / divfact);
           
           
           PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT, true);
           PWMGenEnable(PWM0_BASE, PWM_GEN_0);
            break;
    
    case 4 : PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1,
                     PWMGenPeriodGet(PWM0_BASE, PWM_GEN_0) / divfact);
           
           
           PWMOutputState(PWM0_BASE, PWM_OUT_1_BIT, true);
           PWMGenEnable(PWM0_BASE, PWM_GEN_0);
            break;
            
     case 58 : PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2,
                     PWMGenPeriodGet(PWM0_BASE, PWM_GEN_1) / divfact);
           
           
           PWMOutputState(PWM0_BASE, PWM_OUT_2_BIT, true);
           PWMGenEnable(PWM0_BASE, PWM_GEN_1);
            break;
            
     case 57 : PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3,
                     PWMGenPeriodGet(PWM0_BASE, PWM_GEN_1) / divfact);
           
           
           PWMOutputState(PWM0_BASE, PWM_OUT_3_BIT, true);
           PWMGenEnable(PWM0_BASE, PWM_GEN_1);
            break; 
            
     case 59 : PWMPulseWidthSet(PWM0_BASE, PWM_OUT_4,
                     PWMGenPeriodGet(PWM0_BASE, PWM_GEN_2) / divfact);
           
           
           PWMOutputState(PWM0_BASE, PWM_OUT_4_BIT, true);
           PWMGenEnable(PWM0_BASE, PWM_GEN_2);
            break; 
            
    case 60 : PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,
                     PWMGenPeriodGet(PWM0_BASE, PWM_GEN_2) / divfact);
           
           
           PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT, true);
           PWMGenEnable(PWM0_BASE, PWM_GEN_2);
            break; 
            
   case 16 : PWMPulseWidthSet(PWM0_BASE, PWM_OUT_6,
                     PWMGenPeriodGet(PWM0_BASE, PWM_GEN_3) / divfact);
           
           
           PWMOutputState(PWM0_BASE, PWM_OUT_6_BIT, true);
           PWMGenEnable(PWM0_BASE, PWM_GEN_3);
            break; 
            
   case 15 : PWMPulseWidthSet(PWM0_BASE, PWM_OUT_7,
                     PWMGenPeriodGet(PWM0_BASE, PWM_GEN_3) / divfact);
           
           
           PWMOutputState(PWM0_BASE, PWM_OUT_7_BIT, true);
           PWMGenEnable(PWM0_BASE, PWM_GEN_3);
            break; 
            
            
    //PWM module 1
  case 61 : PWMPulseWidthSet(PWM1_BASE, PWM_OUT_0,
                     PWMGenPeriodGet(PWM1_BASE, PWM_GEN_0) / divfact);
           
           
           PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT, true);
           PWMGenEnable(PWM1_BASE, PWM_GEN_0);
            break;
    
    case 62 : PWMPulseWidthSet(PWM1_BASE, PWM_OUT_1,
                     PWMGenPeriodGet(PWM1_BASE, PWM_GEN_0) / divfact);
           
           
           PWMOutputState(PWM1_BASE, PWM_OUT_1_BIT, true);
           PWMGenEnable(PWM1_BASE, PWM_GEN_0);
            break;
            
     case 23 : PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2,
                     PWMGenPeriodGet(PWM1_BASE, PWM_GEN_1) / divfact);
           
           
           PWMOutputState(PWM1_BASE, PWM_OUT_2_BIT, true);
           PWMGenEnable(PWM1_BASE, PWM_GEN_1);
            break;
            
     case 24 : PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3,
                     PWMGenPeriodGet(PWM1_BASE, PWM_GEN_1) / divfact);
           
           
           PWMOutputState(PWM1_BASE, PWM_OUT_3_BIT, true);
           PWMGenEnable(PWM1_BASE, PWM_GEN_1);
            break; 
            
     case 28 : PWMPulseWidthSet(PWM1_BASE, PWM_OUT_4,
                     PWMGenPeriodGet(PWM1_BASE, PWM_GEN_2) / divfact);
           
           
           PWMOutputState(PWM1_BASE, PWM_OUT_4_BIT, true);
           PWMGenEnable(PWM1_BASE, PWM_GEN_2);
            break; 
            
    case 29 : PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5,
                     PWMGenPeriodGet(PWM1_BASE, PWM_GEN_2) / divfact);
           
           
           PWMOutputState(PWM1_BASE, PWM_OUT_5_BIT, true);
           PWMGenEnable(PWM1_BASE, PWM_GEN_2);
            break; 
            
   case 30 : PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6,
                     PWMGenPeriodGet(PWM1_BASE, PWM_GEN_3) / divfact);
           
           
           PWMOutputState(PWM1_BASE, PWM_OUT_6_BIT, true);
           PWMGenEnable(PWM1_BASE, PWM_GEN_3);
            break; 
            
   case 31 : PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7,
                     PWMGenPeriodGet(PWM1_BASE, PWM_GEN_3) / divfact);
           
           
           PWMOutputState(PWM1_BASE, PWM_OUT_7_BIT, true);
           PWMGenEnable(PWM1_BASE, PWM_GEN_3);
            break; 
  }
  
}


void delay()
{
  SysCtlDelay((SysCtlClockGet() * 0.8) / 3); // delay of 800ms
}



void ServoStop(servo s)
{
  switch(s.pinNo)
  {
    
    //PWM module 0
  case 1:PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT, false);
         break;
         
  case 4: PWMOutputState(PWM0_BASE, PWM_OUT_1_BIT, false);
          break; 
 
  case 58: PWMOutputState(PWM0_BASE, PWM_OUT_2_BIT, false);
          break; 
          
  case 57: PWMOutputState(PWM0_BASE, PWM_OUT_3_BIT, false);
          break;
          
  case 59: PWMOutputState(PWM0_BASE, PWM_OUT_4_BIT, false);
          break;
          
  case 60: PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT, false);
          break;
          
  case 16: PWMOutputState(PWM0_BASE, PWM_OUT_6_BIT, false);
          break;
          
  case 15: PWMOutputState(PWM0_BASE, PWM_OUT_7_BIT, false);
          break;
          
          
    // PWM module 1      
  case 61:PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT, false);
         break;
         
  case 62: PWMOutputState(PWM1_BASE, PWM_OUT_1_BIT, false);
          break; 
 
  case 23: PWMOutputState(PWM1_BASE, PWM_OUT_2_BIT, false);
          break; 
          
  case 24: PWMOutputState(PWM1_BASE, PWM_OUT_3_BIT, false);
          break;
          
  case 28: PWMOutputState(PWM1_BASE, PWM_OUT_4_BIT, false);
          break;
          
  case 29: PWMOutputState(PWM1_BASE, PWM_OUT_5_BIT, false);
          break;
          
  case 30: PWMOutputState(PWM1_BASE, PWM_OUT_6_BIT, false);
          break;
          
  case 31: PWMOutputState(PWM1_BASE, PWM_OUT_7_BIT, false);
          break;        
          
  }
    
}
