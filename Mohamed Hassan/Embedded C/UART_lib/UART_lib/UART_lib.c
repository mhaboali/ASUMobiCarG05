/*
 * UART_lib.c
 *
 * Created: 26/03/2018 01:21:11 ص
 *  Author: user
 */ 


#include "UART.h"

ISR(USART_RX_vect)
{
	
}



int main()
{
	// Write your code here
	UART_init();
	sei();
	while (1)
	{
	
	}
	return 0;
}

//UART==================
void UART_init(void)
{
	UBRR0H = (uint8_t)(BAUD_PRESCALLER>>8);
	UBRR0L = (uint8_t)(BAUD_PRESCALLER);
	UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);
	UCSR0C = (3<<UCSZ00);
}

unsigned char UART_receive(void)
{
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
	
}

void UART_send( unsigned char data)
{
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
}

void WriteUART(uint16_t data)
{
	while(!(UCSR0A & (1<<0x05)));	//Wait for empty transmit buffer
	UDR0 = data;		//Write data into the buffer and transmit
}

void UART_putstring(char* StringPtr)
{
	while(*StringPtr != 0x00)
	{
		UART_send(*StringPtr);
		StringPtr++;
	}
}

//===========================