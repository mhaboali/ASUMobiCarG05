/*
 * ultraSonic_ATmega328p.c
 *
 * Created: 25/03/2018 09:32:23 م
 *  Author: user
 */ 


#include "ultrasonic.h"

//UltraSonics'INTERRUPTS:=====================>
ISR(TIMER0_OVF_vect)
{
	//Get Here Every 1ms
	/*USAGE:
	1.Used in measuring the time of being the echo pin high
	
	*/
	OVF_Counter_front++;				//To know The number of overflow times
	OVF_Counter_rear++;				//To know The number of overflow times
}
ISR(PCINT0_vect)					//get here when logical change occurred on front echo pin PB0
{
	switch(state_front)
	{
		case 0:
		{
			state_front=1;
			frontTCNT1=TCNT0;
			Start_Reciv_front=(OVF_Counter_front*255)+frontTCNT1;
			break;
		}
		case 1:
		{
			state_front=0;
			
			frontTCNT2=TCNT0;
			End_Reciv_front=(OVF_Counter_front*255)+(frontTCNT2-frontTCNT1);
			OVF_Counter_front=0;
			break;
		}
		default:
			break;
	}
}

ISR(PCINT2_vect)				//get here when logical change on the rear echo pin PD5 
{
	switch(state_rear)
	{
		case 0:
		{
			state_rear=1;
			rearTCNT1=TCNT0;
			Start_Reciv_rear=(OVF_Counter_rear*255)+rearTCNT1;
			break;
		}
		case 1:
		{
			state_rear=0;
			rearTCNT2=TCNT0;
			End_Reciv_rear=(OVF_Counter_rear*255)+(rearTCNT2-rearTCNT1);
			OVF_Counter_rear=0;
			break;
		}
		default:
		break;
	}
}
//=====================================<
//Front Sonic Functions:===============>
void init_FrontSonic()
{
	sbi(DDR_front_trig,trig_pin_front);
	cbi(PORT_front_trig,trig_pin_front);
	cbi(DDR_front_echo,echo_pin_front);
	cbi(PORT_front_echo,echo_pin_front);
}
uint16_t front_obst(uint16_t DeltaT)
{
	uint16_t Dist=0;
	echo_Time_front=(DeltaT*4);				//(the difference between the beginning of the echo pulse and the end of it) multiplied by 4 microseconds
	Dist=ceil(echo_Time_front/58.0);
	return Dist;
}
void sonar_front()
{
	sbi(PORT_front_trig,trig_pin_front);
	_delay_us(8);
	cbi(PORT_front_trig,trig_pin_front);
}
//==============================================<
//Rear Sonic Functions:=========================>
void init_RearSonic()
{
	sbi(DDR_rear_sonic,trig_pin_rear);				//Output
	cbi(PORT_rear_sonic,trig_pin_rear);				//initially b zero
	cbi(DDR_rear_sonic,echo_pin_rear);				//input
	cbi(PORT_rear_sonic,echo_pin_rear);
}
uint16_t rear_obst(uint16_t DeltaT)
{
	uint16_t Dist=0;
	echo_Time_rear=(DeltaT*4);				//(the difference between the beginning of the echo pulse and the end of it) multiplied by 4 microseconds
	Dist=ceil(echo_Time_rear/58.0);		//time duration * 0.017
	return Dist;
}
void sonar_rear()
{
	sbi(PORT_rear_sonic,trig_pin_rear);
	_delay_us(8);
	cbi(PORT_rear_sonic,trig_pin_rear);
}
//==================================================<
void init_timer0()
{
	//Initialize Timer0 with Normal mode and its tick 'll be occurred every 4 micro seconds
	sbi(TCCR0B,CS00); 		//PREscaler 64
	sbi(TCCR0B,CS01);
	sbi(TIMSK0,TOIE0);		//enable overflow interrupt
}
void init_ext_interrupts()
{
	sbi(EICRA,ISC00);			//set trigger INT0 for Logical change mode
	sbi(EICRA,ISC01);
	sbi(EIMSK,INT0);			//turn on INT0
	sbi(PCICR,PCIE0);			//enable interrupt on pin change for pins{0:7}
	sbi(PCMSK0,PCINT0);			//choose pin PB0 for trigger the interrupt
	sbi(PCICR,PCIE2);			//enable interrupt on pin change for pins{16:23}
	sbi(PCMSK2,PCINT21);		//choose pin PD7 for trigger the interrupt
	//EICRA|=(1<<ISC01)|(1<<ISC00);	//set triger INT0 for rising edge mode
	//EIMSK|=(1<<INT1);			//turn on INT1
}

