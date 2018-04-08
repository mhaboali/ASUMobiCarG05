/*
 * Servo.c
 *
 * Created: 31/03/2018 07:40:40 ص
 *  Author: user
 */
#include "Motors.h" 
void init_PWM50Hz_T1(uint8_t pin)
{
	switch(pin)
	{
		case(1):
		{
			//set OC1A Or OC1B FOR generating PWM
			sbi(DDRB,PB1);
			cbi(PORTB,PB1);
			//OCReg=&(OCR1A);
			// inverting mode : to control on servo motion @ last 2ms in period
			sbi(TCCR1A,COM1A0);
			sbi(TCCR1A,COM1A1);
			break;
		}
		case(2):
		{
			//set OC1A Or OC1B FOR generating PWM
			sbi(DDRB,PB2);
			cbi(PORTB,PB2);
			//OCReg=&OCR1B;
			// inverting mode : to control on servo motion @ last 2ms in period
			sbi(TCCR1A,COM1B0);
			sbi(TCCR1A,COM1B1);
			break;
		}
	}

	//SELECT MODE:
	//fast PWM: (with top = ICR1 & update its value @ BOTTOM , TOV flag set on TOP)
	sbi(TCCR1A,WGM11);
	cbi(TCCR1A,WGM10);
	sbi(TCCR1B,WGM13);
	sbi(TCCR1B,WGM12);
	//PRECALING (8):(to have 40000 cycle per second which means that every ms has 4000 cycles)
	sbi(TCCR1B,CS11);
	//setting top value equal 39999 @which starting a new clock
	ICR1=39999;
	OCR1A=39999;	//initially duty cycle is zero
	OCR1B=39999;
}
void Start_PWM50Hz_T1(uint8_t pin,uint8_t deg)
{
	switch(pin)
	{
		case(1):
		{
			OCR1A=(ICR1-2000)-ceil(((Max_Deg-Min_Deg)/180)*(float)deg);
			break;
		}
		case(2):
		{
			OCR1B=(ICR1-2000)-ceil(((Max_Deg-Min_Deg)/180)*(float)deg);
			break;
		}
	}
}