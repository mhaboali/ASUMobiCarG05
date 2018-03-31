/*
 * DC_Motors.c
 *
 * Created: 31/03/2018 07:41:46 ص
 *  Author: user
 */ 

#include "DC_Motor.h"
 void init_PWM_T2(uint8_t pin)			//CALCUTE TIME FOR SPEED CALCULATIONS
 {
	 //Fast PWM mode: The Top Value is oxff ,NonInveting MOde (the OCRx is Cleared on compare match and set on the bottom)
	 sbi(TCCR2A,WGM20);
	 sbi(TCCR2A,WGM21);
	 switch(pin)
	 {
		 case(1):
		 {
			 sbi(DDRB,PB3);
			 cbi(PORTB,PB3);
			 //sbi(TCCR2A,COM2A0);
			 sbi(TCCR2A,COM2A1);
			 OCR2A=255;
			 break;
		 }
		 case(2):
		 {
			 sbi(DDRD,PD3);
			 cbi(PORTD,PD3);
			 //sbi(TCCR2A,COM2B0);
			 sbi(TCCR2A,COM2B1);
			 OCR2B=255;
			 break;
		 }
	 }
	 //Prescaler 8
	 sbi(TCCR2B,CS21);
	 
 }
 void Start_PWM_T2(uint8_t pin,uint8_t speed)
 {
	 switch(pin)
	 {
		 case(1):
		 {
			 if(speed>=100)
			 OCR2A=255;
			 else
			 OCR2A=ceil(2.55*speed);
			 break;
		 }
		 case(2):
		 {
			 if(speed>=100)
			 OCR2B=255;
			 else
			 OCR2B=ceil(2.55*speed);
			 break;
		 }
	 }
 }
