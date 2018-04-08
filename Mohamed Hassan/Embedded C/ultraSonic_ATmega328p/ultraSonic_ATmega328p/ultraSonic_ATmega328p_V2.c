/*
 * ultraSonic_ATmega328p.c
 *
 * Created: 25/03/2018 09:32:23 م
 *  Author: user
 */ 


#include "ultrasonic.h"


int main(void)
{
	////For Indication
	//sbi(DDRB,PB0);
	//cbi(PORTB,PB0);
	//sbi(DDRC,PC5);
	//cbi(PORTC,PC5);
	
	init_ultrasonic();
	init_timer0();
	init_ext_interrupts();
	sei();
    while(1)
    {
		sonar();
        DeltaT_front=(End_Reciv_front-Start_Reciv_front);
		echo_Time_front=(DeltaT_front*4);				//(the difference between the beginning of the echo pulse and the end of it) multiplied by 4 microseconds 
		Distance_front=ceil(echo_Time_front/58.0);
		//if(Distance_front>20)
		//{
			//sbi(PORTB,PB0);
		//}
		//else
		//{
			//cbi(PORTB,PB0);
		//}
	}
}
//INTERRUPTS:
ISR(TIMER0_OVF_vect)
{
	//Get Here Every 1ms
	/*USAGE:
	1.Used in measuring the time of being the echo pin high
	
	*/
	OVF_Counter_front++;				//To know The number of overflow times
	
	
}
ISR(PCINT2_vect)
{
	if(state_front==0)  //Check For Rising Edge "which means that echo pin start to receive the wave
	{
		state_front=1;
		Start_Reciv_front=(OVF_Counter_front*255)+TCNT0;
		//tbi(PORTB,PB0);
	}
	else		//Check For Falling Edge "which means that echo pin Finishing Receiving
	{
		state_front=0;
		End_Reciv_front=(OVF_Counter_front*255)+TCNT0;
		TCNT0=0;
		OVF_Counter_front=0;
		//tbi(PORTC,PC5);
	}
}

ISR(INT0_vect)
{
	
}
//=======================
void init_ultrasonic()
{
	sbi(DDR_front_trig,trig_pin_front);
	cbi(PORT_front_trig,trig_pin_front);
	cbi(DDR_front_echo,echo_pin_front);
	cbi(PORT_front_echo,echo_pin_front);
}
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

void sonar()
{
	sbi(PORT_front_sonic,trig_pin_front);
	_delay_us(10);
	cbi(PORT_front_sonic,trig_pin_front);
}