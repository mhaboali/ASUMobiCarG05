/*
 * RC_Car_Project.c
 *
 * Created: 03/04/2018 04:54:44 م
 *  Author: aboali
 */ 


#include "main.h"

int main()
{
	////For Indication:
	//sbi(DDRC,PC5);
	//cbi(PORTC,PC5);
	//sbi(DDRB,PB0);
	//sbi(PORTB,PB0);
	//==================
	//UART Initialization:
	UART_init();
	//=====================
	//initialize the servo:
	init_PWM50Hz_T1(1);			//attach the control pin to PB1 "pin 9 on arduino"
	//initialize the dc motors:
	init_PWM_T2(1);				//attach right motor to PB3 "pin 11 on arduino"
	init_PWM_T2(2);				//attach left motor to PD3 "pin 3 on arduino"
	//=======================
	//ultrasonics:
	init_FrontSonic();
	init_RearSonic();
	init_timer0();
	init_ext_interrupts();		//enable ext. interrupt on pins:(PD2,PB0,PD5)
	//=========================
	sei();						//enable global interrupts
	while (1)
	{
		switch(UART_recv)
		{
			case ('F'||'G'||'I'):
				sonar_front();
				deltaT_front=End_Reciv_front-Start_Reciv_front;
				front_dist=front_obst(deltaT_front);
				break;
			case 'B': case 'J': case 'H':
				sonar_rear();
				deltaT_rear=End_Reciv_rear-Start_Reciv_rear;
				rear_dist=rear_obst(deltaT_rear);
				break;				
		}
	}
	return 0;
}

ISR(USART_RX_vect)
{
	UART_recv=UART_receive();
	if(enter_Rx_interrupt==0)
	{
		previous_Recv=UART_recv;
		enter_Rx_interrupt++;
		switch(UART_recv)
		{
			case 'S':
			{
				Steer_car(stop);
				break;
			}
			case 'F':
			{
				if(front_dist>30)
				{
					Steer_car(forward);
				}
				else
				{
					Steer_car(stop);
				}
				break;
			}
			case 'B':
			{
				if(rear_dist>30)
				{
					Steer_car(backward);
				}
				else
				{
					Steer_car(stop);
				}
				break;
			}
			case 'R': case 'I':
			{
				if (front_dist>30)
				{
					Steer_car(f_right);
				}
				else
				{
					Steer_car(stop);
				}
				break;
			}
			case 'L': case 'G':
			{
				if (front_dist>30)
				{
					Steer_car(f_left);
				}
				else
				{
					Steer_car(stop);
				}
				break;
			}
			case 'J':
			{
				if (rear_dist>30)
				{
					Steer_car(b_right);
				}
				else
				{
					Steer_car(stop);
				}
			}
			case 'H':
			{
				if (rear_dist>30)
				{
					Steer_car(b_left);
				}
				else
				{
					Steer_car(stop);
				}
			}
			default:
			break;
		}
	}
	else if(previous_Recv==UART_recv)
	{
		//enter_Rx_interrupt=1;
		((void)0);
	}
	else
	{
		previous_Recv=UART_recv;
		enter_Rx_interrupt++;
		switch(UART_recv)
		{
			case 'S':
			{
				Steer_car(stop);
				break;
			}
			case 'F':
			{
				if(front_dist>30)
				{
					Steer_car(forward);
				}
				else
				{
					Steer_car(stop);
				}
				break;
			}
			case 'B':
			{
				if(rear_dist>30)
				{
					Steer_car(backward);
				}
				else
				{
					Steer_car(stop);
				}
				break;
			}
			case 'R': case 'I':
			{
				if (front_dist>30)
				{
					Steer_car(f_right);
				}
				else
				{
					Steer_car(stop);
				}
				break;
			}
			case 'L': case 'G':
			{
				if (front_dist>30)
				{
					Steer_car(f_left);
				}
				else
				{
					Steer_car(stop);
				}
				break;
			}
			case 'J':
			{
				if (rear_dist>30)
				{
					Steer_car(b_right);
				}
				else
				{
					Steer_car(stop);
				}
			}
			case 'H':
			{
				if (rear_dist>30)
				{
					Steer_car(b_left);
				}
				else
				{
					Steer_car(stop);
				}
			}
			default:
			break;
		}
	}
}
