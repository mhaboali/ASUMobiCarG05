/*
 * ultrasonic.h
 *
 * Created: 26/03/2018 01:27:40 ص
 *  Author: user
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "config.h"

#define DDR_front_echo		DDRB
#define PORT_front_echo		PORTB
#define DDR_front_trig		DDRD
#define PORT_front_trig		PORTD
#define trig_pin_front		PD7
#define echo_pin_front		PB0			//pin change interrupt PCINT0

#define DDR_rear_sonic		DDRD
#define PORT_rear_sonic		PORTD
#define trig_pin_rear		PD6
#define echo_pin_rear		PD5			//pin change interrupt PCINT21

//static to make these global variables accessible only by the ultrasonics.c file
//To capture the receiving time duration
volatile long unsigned int Start_Reciv_front,End_Reciv_front;			
static volatile long unsigned int OVF_Counter_front=0,frontTCNT1,frontTCNT2;
static volatile short state_front=0;			//To know the echo signal state (rising edge or falling edge)...assuming it's initially rising edge
static volatile uint16_t echo_Time_front=0;		//receiving duration time in ticks unit...which every tick =4microseconds
//To capture the receiving time duration
volatile long unsigned int Start_Reciv_rear,End_Reciv_rear;		
static volatile long unsigned int OVF_Counter_rear=0,rearTCNT1,rearTCNT2;
static volatile short state_rear=0;			//To know the echo signal state (rising edge or falling edge)...assuming it's initially rising edge
static volatile uint16_t echo_Time_rear=0;		//receiving duration time in ticks unit...which every tick =4microseconds

void init_FrontSonic();
void sonar_front();
uint16_t front_obst(uint16_t DeltaT);

void init_RearSonic();
uint16_t rear_obst(uint16_t DeltaT);
void sonar_rear();

void init_timer0();
void init_ext_interrupts();


ISR(TIMER0_OVF_vect);
ISR(PCINT0_vect);
ISR(PCINT2_vect);



#endif /* ULTRASONIC_H_ */