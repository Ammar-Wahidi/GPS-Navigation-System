#include "../Drivers/Headers/MCAL/UART/UART.h"
#include <string.h>
int main()
{
	UART_INIT(UART0);

	UART_SendString(UART0, "hello world /n");

}
