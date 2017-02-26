// set timer0 counter initial value to 0
TCNT0=0x00;
// start timer0 with /1024 prescaler
TCCR0 = (1<<CS02) | (1<<CS00);

// timer1 overflow
ISR(TIMER1_OVF_vect) {
	// process the timer1 overflow here
}

void timer_init(void)
{
TIMSK=(1<<TOIE0) | (1<<TOIE1);
}