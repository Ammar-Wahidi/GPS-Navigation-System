//
//UART.h
//
//
#include "../../../Headers/MCAL/UART/UART.h"

void UART_INIT(UART_Select U_N){
	switch (U_N)
	{
		case (UART0):
			            SET_BIT (SYSCTL_RCGCUART,0);
		              GPIO_Init(PORTA);
									CLR_BIT(UART0_CTL,1);
									UART0_IBRD = IBRD ;
									UART0_FBRD = FBRD;
									UART0_LCRH = eight_bit_word_length_enfifio;
								  UART0_CTL = rx_tx_clk;
									SET_BIT (GPIO_PORTA_AFSEL,0);
									SET_BIT (GPIO_PORTA_AFSEL,1);                                //set pins 0,1 to operate in alternate mode
                  GPIO_PORTA_CR |= GPIO_PA0_U0RX | GPIO_PA1_U0TX;              //eneble committing
                  GPIO_PORTA_AFSEL |= GPIO_PA0_U0RX | GPIO_PA1_U0TX;           //set pins 0,1 to operate in alternate mode
                  GPIO_PORTA_PCTL |= GPIO_PCTL_PA0_U0RX | GPIO_PCTL_PA1_U0TX;  //select UART as alternate function
									GPIO_PORTA_DIR |= GPIO_PA1_U0TX;                             //set TX to be output
									GPIO_PORTA_DIR &= ~GPIO_PA0_U0RX;                            //set RX to be input
									GPIO_PORTA_AMSEL &= ~(GPIO_PA0_U0RX | GPIO_PA1_U0TX);        //disable analog function
									GPIO_PORTA_DEN |= GPIO_PA0_U0RX | GPIO_PA1_U0TX;             //eneble digital function
									break;
		case (UART1):
			            SET_BIT (SYSCTL_RCGCUART,0);
		              GPIO_Init(PORTB);
									CLR_BIT(UART1_CTL,1);
									UART1_IBRD = IBRD ;
									UART1_FBRD = FBRD;
									UART1_LCRH = eight_bit_word_length_enfifio;
								  UART1_CTL = rx_tx_clk;
									SET_BIT (GPIO_PORTB_AFSEL,0);
									SET_BIT (GPIO_PORTB_AFSEL,1);                                //set pins 0,1 to operate in alternate mode
									GPIO_PORTB_CR |= GPIO_PB0_U1RX | GPIO_PB1_U1TX;              //eneble committing
									GPIO_PORTB_PCTL |= GPIO_PCTL_PB0_U1RX | GPIO_PCTL_PB1_U1TX;  //select UART as alternate function
									GPIO_PORTB_DIR |= GPIO_PB1_U1TX;                             //set TX to be output
									GPIO_PORTB_DIR &= ~GPIO_PB0_U1RX;                            //set RX to be input
									GPIO_PORTB_AMSEL &= ~(GPIO_PB0_U1RX | GPIO_PB1_U1TX);        //disable analog function
									GPIO_PORTB_DEN |= GPIO_PB0_U1RX | GPIO_PB1_U1TX;             //eneble digital function
									break;
		case (UART2):
			            SET_BIT (SYSCTL_RCGCUART,0);
		              GPIO_Init(PORTC);
									CLR_BIT(UART2_CTL,1);
									UART2_IBRD = IBRD ;
									UART2_FBRD = FBRD;
									UART2_LCRH = eight_bit_word_length_enfifio;
								  UART2_CTL = rx_tx_clk;
									SET_BIT (GPIO_PORTC_AFSEL,6);
									SET_BIT (GPIO_PORTC_AFSEL,7);                                //set pins 0,1 to operate in alternate mode
									GPIO_PORTD_CR |= GPIO_PD6_U2RX | GPIO_PD7_U2TX;              //eneble committing
									GPIO_PORTD_PCTL |= GPIO_PCTL_PD6_U2RX | GPIO_PCTL_PD7_U2TX;  //select UART as alternate function
									GPIO_PORTD_DIR |= GPIO_PD7_U2TX;                             //set TX to be output
									GPIO_PORTD_DIR &= ~GPIO_PD6_U2RX;                            //set RX to be input
									GPIO_PORTD_AMSEL &= ~(GPIO_PD6_U2RX | GPIO_PD7_U2TX);        //disable analog function
									GPIO_PORTD_DEN |= GPIO_PD6_U2RX | GPIO_PD7_U2TX;             //eneble digital function
									break;
		case (UART3):
			            SET_BIT (SYSCTL_RCGCUART,0);
		              GPIO_Init(PORTD);
									CLR_BIT(UART3_CTL,1);
									UART3_IBRD = IBRD ;
									UART3_FBRD = FBRD;
									UART3_LCRH = eight_bit_word_length_enfifio;
								  UART3_CTL = rx_tx_clk;
									SET_BIT (GPIO_PORTD_AFSEL,6);
									SET_BIT (GPIO_PORTD_AFSEL,7);                                //set pins 0,1 to operate in alternate mode
									GPIO_PORTC_CR |= GPIO_PC6_U3RX | GPIO_PC7_U3TX;              //eneble committing
									GPIO_PORTC_PCTL |= GPIO_PCTL_PC6_U3RX | GPIO_PCTL_PC7_U3TX;  //select UART as alternate function
									GPIO_PORTC_DIR |= GPIO_PC7_U3TX;                             //set TX to be output
									GPIO_PORTC_DIR &= ~GPIO_PC6_U3RX;                            //set RX to be input
									GPIO_PORTC_AMSEL &= ~(GPIO_PC6_U3RX | GPIO_PC7_U3TX);        //disable analog function
									GPIO_PORTC_DEN |= GPIO_PC6_U3RX | GPIO_PC7_U3TX;             //eneble digital function
									break;
	}
}

unsigned char UART_ReadAvailable(UART_Select UART_NO){
    switch(UART_NO)
    {
        case UART0:
        return ((UART0_FR & UART_FR_RXFE) == UART_FR_RXFE) ? 1 : 0;  //empty = 1 , 0 otherwise
        break;

        case UART1:
        return ((UART1_FR & UART_FR_RXFE) == UART_FR_RXFE) ? 1 : 0;
        break;

        case UART2:
        return ((UART2_FR & UART_FR_RXFE) == UART_FR_RXFE) ? 1 : 0;
        break;

        case UART3:
        return ((UART3_FR & UART_FR_RXFE) == UART_FR_RXFE) ? 1 : 0;;
        break;

        default : return 0; break;
    }
}




unsigned char UART_SendAvailable(UART_Select UART_NO){
    switch(UART_NO)
    {
        case UART0:
        return ((UART0_FR & UART_FR_TXFF) == UART_FR_TXFF) ? 1 : 0;  //full = 1 , 0 otherwise
        break;

        case UART1:
        return ((UART1_FR & UART_FR_TXFF) == UART_FR_TXFF) ? 1 : 0;
        break;

        case UART2:
        return ((UART2_FR & UART_FR_TXFF) == UART_FR_TXFF) ? 1 : 0;
        break;

        case UART3:
        return ((UART3_FR & UART_FR_TXFF) == UART_FR_TXFF) ? 1 : 0;
        break;

        default :  return 0; break;
    }
}


void UART_SendChar(UART_Select UART_NO , uint8_t Data){

    switch(UART_NO)
    {
        case UART0:
        while(UART_SendAvailable(UART_NO));
        UART0_DR = Data;
        break;

        case UART1:
        while(UART_SendAvailable(UART_NO));
        UART1_DR = Data;
        break;

        case UART2:
        while(UART_SendAvailable(UART_NO));
        UART2_DR = Data;
        break;

        case UART3:
        while(UART_SendAvailable(UART_NO));
        UART3_DR = Data;
        break;

        default : break;
    }
}

uint8_t UART_ReadChar(UART_Select UART_NO){

    switch(UART_NO)
    {
        case UART0:
        while(UART_ReadAvailable(UART_NO));
        return (uint8_t)(UART0_DR &= UART_DATA_MASK) ;
        break;

        case UART1:
        while(UART_ReadAvailable(UART_NO));
        return (uint8_t)(UART1_DR &= UART_DATA_MASK) ;
        break;

        case UART2:
        while(UART_ReadAvailable(UART_NO));
        return (uint8_t)(UART2_DR &= UART_DATA_MASK) ;
        break;

        case UART3:
        while(UART_ReadAvailable(UART_NO));
        return (uint8_t)(UART3_DR &= UART_DATA_MASK) ;
        break;

        default : break;
    }
}


void UART_SendString(UART_Select UART_NO, uint8_t *str) {
    while (*str != '\0') {
        UART_SendChar(UART_NO, *str);
        str++;
    }
}

void UART_ReadString(uint8_t UART_NO, uint8_t *buffer) {
    int i = 0;
    while (1) {  // Continue indefinitely
        char c = UART_ReadChar(UART_NO);
        if (c == '\0') {
            break;  // Break if null terminator is received
        }
        buffer[i++] = c;
    }
    buffer[i] = '\0';  // Null-terminate the string
}
