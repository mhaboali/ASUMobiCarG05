/*
 * DC_Motor.h
 *
 * Created: 31/03/2018 07:42:26 ص
 *  Author: user
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include "config.h"

#define R_motor_direc_pin	PC4
#define L_motor_direc_pin	PC5
typedef enum{forward,backward,f_right,f_left,b_right,b_left,stop}Directions;
typedef enum{R_motor,L_motor}Motors;

void init_PWM_T2(uint8_t pin);						//initializing timer2 with out fast pwm mode
void Start_PWM_T2(Motors m,uint8_t speed);
void Steer_car(Directions dir);

#define Max_Deg 4000
#define Min_Deg 2000

void init_PWM50Hz_T1(uint8_t pin);
void Start_PWM50Hz_T1(uint8_t pin,uint8_t deg);




#endif /* MOTOR_H_ */