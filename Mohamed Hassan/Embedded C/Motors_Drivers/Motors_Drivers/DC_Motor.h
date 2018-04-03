/*
 * DC_Motor.h
 *
 * Created: 31/03/2018 07:42:26 ص
 *  Author: user
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "config.h"
void init_PWM_T2(uint8_t pin);						//initializing timer2 with out fast pwm mode
void Start_PWM_T2(uint8_t pin,uint8_t speed);




#endif /* DC_MOTOR_H_ */