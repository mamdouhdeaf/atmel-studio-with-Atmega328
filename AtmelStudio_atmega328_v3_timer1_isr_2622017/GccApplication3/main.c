/*
  GccApplication3.c
 
  Created: 21-02-2017 PM 09:35:59
  v1:21/2/2017
  added gpio as output (expect "0" and "1")
  
  v2:23/2/2017
  added uart0.c 9600baud 
	1 to gpio2 ON
	0 to gpio2 OFF
 
 v3:26/2/2017
	timer1 init
	two indenpendant timer for gpio3 and gpio4
  Author : Sudarshan
 */ 

#define F_CPU 16000000UL
#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "INC/gpio_func.c"
#include "INC/uart0.c"
#include "INC/timer.c"


//int state=0;
//unsigned int state, blink_time, SEC1_Timer, Timer1_ON, SECTimer1_ON=0;




int main(void)
{

	uint8_t u8TempData;
	io_init();			//GPIO INPUT
	init_serial0();		//UART0 init
	timer0_init();		//timer.c
	
	sprintf(uart0_buf,"23/2/2017 v2 USART0 and GPIO O/P\r\n");//
	print_uart0();
	sprintf(uart0_buf,"send 1 to gpio2 ON, 0 to gpio OFF\r\n");
	print_uart0();
	
	gpio_timer_flag=1;
	while(1)
	{
			 // Receive data

			gpio1_check();
			 u8TempData = USART0ReceiveByte();//read incoming char from usart0
			 if (u8TempData=='0')
			 {
				 op2_off();
			 }
			 if (u8TempData=='1')
			 {
				 op2_on();
			 }
	}
}







void gpio1_check()
{
	/*if (gpio1_counter <= 1)
	{
		//op3_on();
	}*/
}
