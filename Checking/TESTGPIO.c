//TEST GPIO
#include "../Drivers/Headers/MCAL/GPIO/GPIO.h"

int main(){
	GPIO_Init(PORTF) ;
	while (1)
	{
	RGB_PORTF_Activate(RED) ;
	}
}
