void gpio1_check(void);



void timer0_init()
{
	OCR1A = 0x3D08;

	TCCR1B |= (1 << WGM12);
	// Mode 4, CTC on OCR1A

	TIMSK1 |= (1 << OCIE1A);
	//Set interrupt on compare match

	TCCR1B |= (1 << CS12);//TCCR1B |= (1 << CS12) | (1 << CS10);// set prescaler to 1024 and start the timer


	sei();
}

unsigned int gpio_timer_flag,gpio1_counter=10;
void timer1()
{
	//PORTB ^= (1 << 13);
	gpio1_counter=gpio1_counter-1;
	if (gpio1_counter < 5)
	{
		op3_on();
	}
	if (gpio1_counter > 5)
	{
		op3_off();
	}
	if (gpio1_counter ==0)
	{
		gpio1_counter=10;
	}
}
unsigned int gpio2_timer_flag,gpio2_counter=5;
void timer2()
{
	//PORTB ^= (1 << 13);
	gpio2_counter=gpio2_counter-1;
	if (gpio2_counter < 3)
	{
		op4_on();
	}
	if (gpio2_counter > 3)
	{
		op4_off();
	}
	if (gpio2_counter ==0)
	{
		gpio2_counter=5;
	}
}

ISR (TIMER1_COMPA_vect)
{
	// action to be done every 1 sec
	if (gpio_timer_flag==1)
	{
		timer1();
		timer2();
	}
}
