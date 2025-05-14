//UART.C
#include "../../../Headers/MCAL/UART/UART.h"

void UART0_Init(void) {
    // Enable UART0 and Port A clocks
    SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R0;
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;
    while ((SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R0) == 0);

    // Configure PA0, PA1 for UART
    GPIO_PORTA_AFSEL_R |= (1 << 1) | (1 << 0);
    GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R & 0xFFFFFF00) | 0x00000011;
    GPIO_PORTA_DEN_R |= (1 << 1) | (1 << 0);

    // Setup UART0: disable, configure baud, line control, enable
    UART0_CTL_R &= ~(uint32_t)UART_CTL_UARTEN;
    UART0_IBRD_R = 104;
    UART0_FBRD_R = 11;
    UART0_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN);
    UART0_CTL_R |= (UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE);
}

void UART2_Init(void) {
    // Enable UART2 and Port D clocks
    SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R2;
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R3;
    while ((SYSCTL_PRGPIO_R & SYSCTL_PRGPIO_R3) == 0);

    // Unlock and configure PD6, PD7 for UART
    GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY;
    GPIO_PORTD_CR_R |= (1 << 7);
    GPIO_PORTD_AFSEL_R |= (1 << 7) | (1 << 6);
    GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R & 0x00FFFFFF) | 0x11000000;
    GPIO_PORTD_DEN_R |= (1 << 7) | (1 << 6);
    GPIO_PORTD_AMSEL_R &= ~((1 << 7) | (1 << 6));

    // Setup UART2: disable, set clock, baud, line control, enable
    UART2_CTL_R &= ~(uint32_t)UART_CTL_UARTEN;
    UART2_CC_R = 0x00;
    UART2_IBRD_R = 104;
    UART2_FBRD_R = 11;
    UART2_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN);
    UART2_CTL_R |= (UART_CTL_UARTEN | UART_CTL_RXE | UART_CTL_TXE);
}

void UART0_Print(const char *buf) {
    // Send null-terminated string over UART0
    while (*buf) {
        while (UART0_FR_R & UART_FR_TXFF);
        UART0_DR_R = *buf++;
    }
}

char UART2_InChar(void) {
    // Receive one character from UART2
    while (UART2_FR_R & UART_FR_RXFE);
    return (char)(UART2_DR_R & 0xFF);
}

void UART2_ReadLine(char *buffer, uint32_t max_len) {
    // Read characters into buffer until '\n' or limit
    uint32_t idx = 0;
    char c;

    if (max_len == 0) return;

    while (idx < max_len - 1) {
        c = UART2_InChar();
        buffer[idx++] = c;
        if (c == '\n') break;
    }

    buffer[idx] = '\0';
}