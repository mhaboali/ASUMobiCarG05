/*
 * ultrasonic.h
 *
 * Created: 26/03/2018 01:27:40 ص
 *  Author: user
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_


#define F_CPU 16000000 // Clock Speed
#define BAUDRATE 9600
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)
#include <avr/sleep.h>
#include <inttypes.h>
#include <avr/io.h>
#include<stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <math.h>
#define sbi(reg,pin) reg|=_BV(pin)
#define cbi(reg,pin) reg&=~_BV(pin)
#define tbi(reg,pin) reg^=_BV(pin)
#define is_high(reg,pin) (((reg)&_BV(pin))==1)

#define trig_pin	PD5
#define echo_pin	PD2

volatile long unsigned int OVF_Counter=0,Start_Reciv,End_Reciv;
volatile short state=0;
volatile uint16_t DeltaT=0,echo_Time=0,Distance=0;

void init_ultrasonic();
void init_timer0();
void init_ext_interrupts();
ISR(TIMER0_OVF_vect);
void sonar();
ISR(INT0_vect);




#endif /* ULTRASONIC_H_ */