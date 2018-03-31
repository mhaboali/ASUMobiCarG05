/*
 * Motors_Drivers.c
 *
 * Created: 29/03/2018 10:54:38 م
 *  Author: user
 */ 


#include "config.h"
int main()
{
	init_PWM50Hz_T1(1);
	Start_PWM50Hz_T1(1,150);
	init_PWM_T2(1);						//initializing timer2 with out fast pwm mode
	init_PWM_T2(2);						//initializing timer2 with out fast pwm mode
	while (1)
	{
		Start_PWM_T2(1,100);
		Start_PWM_T2(2,50);
	}
	return 0;
}