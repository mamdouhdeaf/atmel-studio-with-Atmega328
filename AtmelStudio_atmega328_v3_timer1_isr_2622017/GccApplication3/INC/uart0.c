/*
UART0 initialization
*/

#define USART_BAUDRATE 9600
#define UBRR_VALUE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)
char uart0_buf[];
void print_uart0(void); 
void putchar0 (int ch);


void init_serial0 (void)
{
	UBRR0H = (uint8_t)(UBRR_VALUE>>8);
	UBRR0L = (uint8_t)UBRR_VALUE;
	UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);	// Set frame format to 8 data bits, no parity, 1 stop bit
	UCSR0B |= (1<<RXEN0)|(1<<TXEN0);	//enable transmission and reception
}

/*
void USART0SendByte(uint8_t u8Data)
{
	while(!(UCSR0A&(1<<UDRE0))){};		//wait while previous byte is completed	
	UDR0 = u8Data;						// Transmit data
}
*/


uint8_t USART0ReceiveByte()
{
	while(!(UCSR0A&(1<<RXC0))){};		// Wait for byte to be received		
	return UDR0;						// Return received data
}




void putchar0 (int ch)
{
	if (ch == '\n')
	{
		while (!(UCSR0A & 0x20));//								// Wait TXD Buffer Empty
		UDR0 = 0x0D;                          					// Write CR
	}
	while (!(UCSR0A & 0x20)); 									// Wait TXD Buffer Empty
	UDR0 = ch;						    						// Write Character
}


void print_uart0(void)
{
	char *p;													// Pointer Buffer
	p = uart0_buf;												// UART Buffer
	do 															// Get char & Print Until null
	{
		putchar0(*p); 											// Write char to UART
		p++;													// Next char
	}
	while(*p != '\0');											// End of ASCII (null)
	return;
}
