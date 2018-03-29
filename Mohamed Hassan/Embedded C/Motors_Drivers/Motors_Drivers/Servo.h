/*
 * Servo.h
 *
 * Created: 30/03/2018 01:08:09 ص
 *  Author: user
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#define F_CPU 16000000 // Clock Speed
#define BAUDRATE 9600
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)
#include <avr/sleep.h>
#include <inttypes.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <math.h>
#define sbi(reg,pin) reg|=_BV(pin)
#define cbi(reg,pin) reg&=~_BV(pin)
#define tbi(reg,pin) reg^=_BV(pin)
#define is_high(reg,pin) (((reg)&_BV(pin))==1)

#define Max_Deg 4000
#define Min_Deg 2000

volatile char *OCReg=0;

void init_PWM50Hz_T1(char pin);
void Move_Servo(uint8_t pin,uint8_t deg);




#endif /* SERVO_H_ */