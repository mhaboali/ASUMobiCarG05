/*
 * config.h
 *
 * Created: 31/03/2018 07:43:16 ص
 *  Author: user
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

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



#endif /* CONFIG_H_ */