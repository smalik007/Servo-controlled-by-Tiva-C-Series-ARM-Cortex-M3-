#ifndef __SERVO_H__
#define __SERVO_H__

struct servo
{
 int pinNo;
};

void Servoinit(servo s);
void ServoMove(servo s ,float deg);


#endif