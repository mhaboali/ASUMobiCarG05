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

#define DDR_front_echo		DDRB
#define PORT_front_echo		PORTB
#define DDR_front_trig		DDRD
#define PORT_front_trig		PORTD
#define trig_pin_front		PB0
#define echo_pin_front		PD7

#define DDR_rear_sonic		DDRD
#define PORT_rear_sonic		PORTD
#define trig_pin_rear		PD6
#define echo_pin_rear		PD5


volatile long unsigned int OVF_Counter_front=0,Start_Reciv_front,End_Reciv_front;
volatile short state_front=0;
volatile uint16_t DeltaT_front=0,echo_Time_front=0,Distance_front=0;

void init_ultrasonic();
void init_timer0();
void init_ext_interrupts();
ISR(TIMER0_OVF_vect);
void sonar();
ISR(INT0_vect);
ISR(PCINT0_vect);
ISR(PCINT2_vect);



#endif /* ULTRASONIC_H_ */