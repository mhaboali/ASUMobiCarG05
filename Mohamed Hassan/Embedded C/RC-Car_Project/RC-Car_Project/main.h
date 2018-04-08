/*
 * main.h
 *
 * Created: 08/04/2018 11:36:48 ص
 *  Author: user
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#include "config.h"
#include "UART.h"
#include "Motors.h"
#include "ultrasonic.h"

//global variables :

volatile uint16_t front_dist,rear_dist;
volatile long unsigned int deltaT_front,deltaT_rear;
extern volatile long unsigned int Start_Reciv_front,End_Reciv_front;
extern volatile long unsigned int Start_Reciv_rear,End_Reciv_rear;

volatile uint8_t enter_Rx_interrupt=0;
volatile char previous_Recv;				//for knowing the previous received data on uart

#endif /* MAIN_H_ */