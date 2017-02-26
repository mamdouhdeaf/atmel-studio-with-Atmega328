void timer0_init()
{
	// set up timer with no prescaling
	TCCR0 |= (1 << CS00);
	
	// initialize counter
	TCNT0 = 0;
}