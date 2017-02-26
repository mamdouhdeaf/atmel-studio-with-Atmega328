/*
 * GccApplication3.c
 *	Avr studio 7 AtMega328 simplified embedded c for arduino
 * Using usbASP programmer
 * Created: 21-02-2017 PM 09:35:59
 * Author : sdrshnptl
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "INC/gpio_func.c"
//#include "INC/TimerInit.c"



int main(void)
{
	io_init();
	//timer0_init();
	while(1)
	{
		op13_on();				//OnBoard led on Arduino
		op2_off();
		op3_off();
		_delay_ms(1000);        //Delay for 1000ms => 1 sec
		
		op13_off();
		op2_on();
		op3_off();
		_delay_ms(1000);        //Delay for 1000ms => 1 sec
		
		op13_off();
		op2_off();
		op3_on();
		_delay_ms(1000);        //Delay for 1000ms => 1 sec
	}
}