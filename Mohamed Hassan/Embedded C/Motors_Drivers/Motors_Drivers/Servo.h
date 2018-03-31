/*
 * Servo.h
 *
 * Created: 30/03/2018 01:08:09 ص
 *  Author: user
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#include "config.h"

#define Max_Deg 4000
#define Min_Deg 2000

volatile char *OCReg=0;

void init_PWM50Hz_T1(char pin);
void Start_PWM50Hz_T1(uint8_t pin,uint8_t deg);




#endif /* SERVO_H_ */