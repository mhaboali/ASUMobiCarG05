/*
 * DC_Motors.c
 *
 * Created: 31/03/2018 07:41:46 ص
 *  Author: user
 */ 

#include "Motors.h"
 void init_PWM_T2(uint8_t pin)			//CALCUTE TIME FOR SPEED CALCULATIONS
 {
	 //Fast PWM mode: The Top Value is 0xff ,NonInveting MOde (the OCRx is Cleared on compare match and set on the bottom)
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
	 //Pre scaler 8
	 sbi(TCCR2B,CS21);
	 //direction pins as output
	 sbi(DDRC,R_motor_direc_pin);
	 sbi(DDRC,L_motor_direc_pin);
	 
	 
 }
 void Start_PWM_T2(Motors motor,uint8_t speed)
 {
	 switch(motor)
	 {
		 case(R_motor):
		 {
			 if(speed>=100)
				OCR2A=255;
			 else
				OCR2A=ceil(2.55*speed);
			 break;
		 }
		 case(L_motor):
		 {
			 if(speed>=100)
				OCR2B=255;
			 else
				OCR2B=ceil(2.55*speed);
			 break;
		 }
	 }
 }
void Steer_car(Directions dir)
{
	switch(dir)
	{
		case forward:
		{
			cbi(PORTC,R_motor_direc_pin);
			cbi(PORTC,L_motor_direc_pin);
			Start_PWM50Hz_T1(1,90);
			Start_PWM_T2(R_motor,100);
			Start_PWM_T2(L_motor,100);
			break;
		}
		case backward:
		{
			sbi(PORTC,R_motor_direc_pin);
			sbi(PORTC,L_motor_direc_pin);
			Start_PWM50Hz_T1(1,90);
			Start_PWM_T2(R_motor,100);
			Start_PWM_T2(L_motor,100);
			break;
		}
		case f_right:
		{
			cbi(PORTC,R_motor_direc_pin);
			cbi(PORTC,L_motor_direc_pin);
			Start_PWM_T2(R_motor,100);
			Start_PWM50Hz_T1(1,65);
			Start_PWM_T2(L_motor,40);
			break;
		}
		case f_left:
		{
			cbi(PORTC,R_motor_direc_pin);
			cbi(PORTC,L_motor_direc_pin);
			Start_PWM_T2(R_motor,40);
			Start_PWM50Hz_T1(1,120);
			Start_PWM_T2(L_motor,100);
			break;
		}
		case b_right:
		{
			sbi(PORTC,R_motor_direc_pin);
			sbi(PORTC,L_motor_direc_pin);
			Start_PWM_T2(R_motor,40);
			Start_PWM50Hz_T1(1,65);
			Start_PWM_T2(L_motor,100);
			break;
		}
		case b_left:
		{
			sbi(PORTC,R_motor_direc_pin);
			sbi(PORTC,L_motor_direc_pin);
			Start_PWM_T2(R_motor,100);
			Start_PWM50Hz_T1(1,120);
			Start_PWM_T2(L_motor,40);
			break;
		}
		case stop:
		{
			cbi(PORTC,R_motor_direc_pin);
			cbi(PORTC,L_motor_direc_pin);
			Start_PWM50Hz_T1(1,90);
			Start_PWM_T2(R_motor,0);
			Start_PWM_T2(L_motor,0);
			break;
		}
	}
	
}