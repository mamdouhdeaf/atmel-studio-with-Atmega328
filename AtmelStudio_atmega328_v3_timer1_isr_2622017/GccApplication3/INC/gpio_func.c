/*							Port	Arduino	*/
//#define output0		0	//PD0	Rx 0
//#define output1		1	//PD1	Tx 1
	#define output2		2	//PD2 2
	#define output3		3	//PD3 3
	#define output4		4	//PD4 4
	#define output5		5	//PD5 5
	#define output6		6	//PD6 6
	#define output7		7	//PD7 7

	#define output8		0	//PB0 8
	#define output9		1	//PB1 9
	#define output10	2	//PB2 10
	#define output11	3	//PB3 11
	#define output12	4	//PB4 12
	#define output13	5	//PB5 13




void io_init(void)
{
DDRD |= (/*(1<<output0) | (1<<output1) |*/ (1<<output2) | (1<<output3) | (1<<output4) | (1<<output5) | (1<<output6) | (1<<output7));
DDRB |= ((1<<output8) | (1<<output9) | (1<<output10) | (1<<output11) | (1<<output12) | (1<<output13));
}

/*
void op0_on()	{PORTD |= (1<<output0);}
void op0_off()	{PORTD &= ~(1<<output0);}

void op1_on()	{PORTD |= (1<<output1);}
void op1_off()	{PORTD &= ~(1<<output1);}
*/
void op2_on()	{PORTD |= (1<<output2);}
void op2_off()	{PORTD &= ~(1<<output2);}

void op3_on()	{PORTD |= (1<<output3);}
void op3_off()	{PORTD &= ~(1<<output3);}

void op4_on()	{PORTD |= (1<<output4);}
void op4_off()	{PORTD &= ~(1<<output4);}
	

void op5_on()	{PORTB |= (1<<output5);}
void op5_off()	{PORTB &= ~(1<<output5);}	
	
void op6_on()	{PORTB |= (1<<output6);}
void op6_off()	{PORTB &= ~(1<<output6);}


void op7_on()	{PORTB |= (1<<output7);}
void op7_off()	{PORTB &= ~(1<<output7);}	
