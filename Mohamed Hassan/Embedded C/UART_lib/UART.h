/*
 * UART.h
 *
 * Created: 26/03/2018 01:25:04 ص
 *  Author: user
 */ 


#ifndef UART_H_
#define UART_H_

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

volatile unsigned char rec;
void UART_init(void);
unsigned char UART_receive(void);
void UART_send( unsigned char data);
void WriteUART(uint16_t data);
void UART_putstring(char* StringPtr);
ISR(USART_RX_vect);



#endif /* UART_H_ */