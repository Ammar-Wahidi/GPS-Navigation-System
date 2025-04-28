//
//GPIO.h
//
//Ammar Ahmed Wahidi
//

#ifndef GPIO
#define GPIO
#include <stdint.h>
#include "../../../Services/Bit_Utilies.h"
//////////////////////////////////////////////////////////////////////
//general defines
#define SYSTEM_CLOCK  80000000
// addresses
#define RCGCGPIO			(*((volatile unsigned long*)0x400FE608))
#define PRGPIO				(*((volatile unsigned long*)0x400FEA08))

//Data Sheet Regesters p662
//Base Addresses
/*
GPIOData(GPIODATA)
 GPIOPortA(APB)base:0x4000.4000
 GPIOPortA(AHB)base:0x4005.8000
 GPIOPortB(APB)base:0x4000.5000
 GPIOPortB(AHB)base:0x4005.9000
 GPIOPortC(APB)base:0x4000.6000
 GPIOPortC(AHB)base:0x4005.A000
 GPIOPortD(APB)base:0x4000.7000
 GPIOPortD(AHB)base:0x4005.B000
 GPIOPortE(APB)base:0x4002.4000
 GPIOPortE(AHB)base:0x4005.C000
 GPIOPortF(APB)base:0x4002.5000
 GPIOPortF(AHB)base:0x4005.D000
 Offset0x000
 TypeRW,reset0x0000.0000
*/

#define BASE_GPIO_PORTA_APB 		(0x40004000)
#define BASE_GPIO_PORTB_APB 		(0x40005000)
#define BASE_GPIO_PORTC_APB 		(0x40006000)
#define BASE_GPIO_PORTD_APB 		(0x40007000)
#define BASE_GPIO_PORTE_APB 		(0x40024000)
#define BASE_GPIO_PORTF_APB 		(0x40025000)

//DIRECTIONS
/*
//////offset0x400/////
GPIODirection(GPIODIR)
 GPIOPortA(APB)base:0x4000.4000
 GPIOPortA(AHB)base:0x4005.8000
 GPIOPortB(APB)base:0x4000.5000
 GPIOPortB(AHB)base:0x4005.9000
 GPIOPortC(APB)base:0x4000.6000
 GPIOPortC(AHB)base:0x4005.A000
 GPIOPortD(APB)base:0x4000.7000
 GPIOPortD(AHB)base:0x4005.B000
 GPIOPortE(APB)base:0x4002.4000
 GPIOPortE(AHB)base:0x4005.C000
 GPIOPortF(APB)base:0x4002.5000
 GPIOPortF(AHB)base:0x4005.D000
 Offset0x400
 TypeRW,reset0x0000.0000
 to end ....
*/

#define GPIO_PORTA_DIR					(*((volatile unsigned long*)(BASE_GPIO_PORTA_APB + 0x400)))
#define GPIO_PORTB_DIR					(*((volatile unsigned long*)(BASE_GPIO_PORTB_APB + 0x400)))
#define GPIO_PORTC_DIR					(*((volatile unsigned long*)(BASE_GPIO_PORTC_APB + 0x400)))
#define GPIO_PORTD_DIR					(*((volatile unsigned long*)(BASE_GPIO_PORTD_APB + 0x400)))
#define GPIO_PORTE_DIR					(*((volatile unsigned long*)(BASE_GPIO_PORTE_APB + 0x400)))
#define GPIO_PORTF_DIR					(*((volatile unsigned long*)(BASE_GPIO_PORTF_APB + 0x400)))

//AlternateFunction offset0x420 (UART BIT [1:0])
#define GPIO_PORTA_AFSEL					(*((volatile unsigned long*)(BASE_GPIO_PORTA_APB + 0x420)))
#define GPIO_PORTB_AFSEL					(*((volatile unsigned long*)(BASE_GPIO_PORTB_APB + 0x420)))
#define GPIO_PORTC_AFSEL					(*((volatile unsigned long*)(BASE_GPIO_PORTC_APB + 0x420)))
#define GPIO_PORTD_AFSEL					(*((volatile unsigned long*)(BASE_GPIO_PORTD_APB + 0x420)))
#define GPIO_PORTE_AFSEL					(*((volatile unsigned long*)(BASE_GPIO_PORTE_APB + 0x420)))
#define GPIO_PORTF_AFSEL					(*((volatile unsigned long*)(BASE_GPIO_PORTF_APB + 0x420)))

//GPIOPortControl(GPIOPCTL),offset0x52C
#define GPIO_PORTA_PCTL					(*((volatile unsigned long*)(BASE_GPIO_PORTA_APB + 0x52C)))
#define GPIO_PORTB_PCTL					(*((volatile unsigned long*)(BASE_GPIO_PORTB_APB + 0x52C)))
#define GPIO_PORTC_PCTL					(*((volatile unsigned long*)(BASE_GPIO_PORTC_APB + 0x52C)))
#define GPIO_PORTD_PCTL					(*((volatile unsigned long*)(BASE_GPIO_PORTD_APB + 0x52C)))
#define GPIO_PORTE_PCTL					(*((volatile unsigned long*)(BASE_GPIO_PORTE_APB + 0x52C)))
#define GPIO_PORTF_PCTL					(*((volatile unsigned long*)(BASE_GPIO_PORTF_APB + 0x52C)))

//Digital enable offset0x51C
#define GPIO_PORTA_DEN				(*((volatile unsigned long*)(BASE_GPIO_PORTA_APB + 0x51C)))
#define GPIO_PORTB_DEN				(*((volatile unsigned long*)(BASE_GPIO_PORTB_APB + 0x51C)))
#define GPIO_PORTC_DEN				(*((volatile unsigned long*)(BASE_GPIO_PORTC_APB + 0x51C)))
#define GPIO_PORTD_DEN				(*((volatile unsigned long*)(BASE_GPIO_PORTD_APB + 0x51C)))
#define GPIO_PORTE_DEN				(*((volatile unsigned long*)(BASE_GPIO_PORTE_APB + 0x51C)))
#define GPIO_PORTF_DEN				(*((volatile unsigned long*)(BASE_GPIO_PORTF_APB + 0x51C)))

//Data/READ/WRITE register
#define GPIO_PORTA_DATA				(*((volatile unsigned long*)(BASE_GPIO_PORTA_APB+0x3FC)))
#define GPIO_PORTB_DATA				(*((volatile unsigned long*)(BASE_GPIO_PORTB_APB+0x3FC)))
#define GPIO_PORTC_DATA				(*((volatile unsigned long*)(BASE_GPIO_PORTC_APB+0x3FC)))
#define GPIO_PORTD_DATA				(*((volatile unsigned long*)(BASE_GPIO_PORTD_APB+0x3FC)))
#define GPIO_PORTE_DATA				(*((volatile unsigned long*)(BASE_GPIO_PORTE_APB+0x3FC)))
#define GPIO_PORTF_DATA				(*((volatile unsigned long*)(BASE_GPIO_PORTF_APB+0x3FC)))

//Analog enable
#define GPIO_PORTA_AMSEL				(*((volatile unsigned long*)(BASE_GPIO_PORTA_APB + 0x528)))
#define GPIO_PORTB_AMSEL				(*((volatile unsigned long*)(BASE_GPIO_PORTB_APB + 0x528)))
#define GPIO_PORTC_AMSEL				(*((volatile unsigned long*)(BASE_GPIO_PORTC_APB + 0x528)))
#define GPIO_PORTD_AMSEL				(*((volatile unsigned long*)(BASE_GPIO_PORTD_APB + 0x528)))
#define GPIO_PORTE_AMSEL				(*((volatile unsigned long*)(BASE_GPIO_PORTE_APB + 0x528)))
#define GPIO_PORTF_AMSEL				(*((volatile unsigned long*)(BASE_GPIO_PORTF_APB + 0x528)))

//LOCK register
#define GPIO_PORTA_LOCK				(*((volatile unsigned long*)(BASE_GPIO_PORTA_APB + 0x520)))
#define GPIO_PORTB_LOCK				(*((volatile unsigned long*)(BASE_GPIO_PORTB_APB + 0x520)))
#define GPIO_PORTC_LOCK				(*((volatile unsigned long*)(BASE_GPIO_PORTC_APB + 0x520)))
#define GPIO_PORTD_LOCK				(*((volatile unsigned long*)(BASE_GPIO_PORTD_APB + 0x520)))
#define GPIO_PORTE_LOCK				(*((volatile unsigned long*)(BASE_GPIO_PORTE_APB + 0x520)))
#define GPIO_PORTF_LOCK				(*((volatile unsigned long*)(BASE_GPIO_PORTF_APB + 0x520)))

//Commit register
#define GPIO_PORTA_CR				(*((volatile unsigned long*)(BASE_GPIO_PORTA_APB + 0x524)))
#define GPIO_PORTB_CR				(*((volatile unsigned long*)(BASE_GPIO_PORTB_APB + 0x524)))
#define GPIO_PORTC_CR				(*((volatile unsigned long*)(BASE_GPIO_PORTC_APB + 0x524)))
#define GPIO_PORTD_CR				(*((volatile unsigned long*)(BASE_GPIO_PORTD_APB + 0x524)))
#define GPIO_PORTE_CR				(*((volatile unsigned long*)(BASE_GPIO_PORTE_APB + 0x524)))
#define GPIO_PORTF_CR				(*((volatile unsigned long*)(BASE_GPIO_PORTF_APB + 0x524)))

//May be we don't use
//Pull UP
#define GPIO_PORTA_PUR				(*((volatile unsigned long*)(BASE_GPIO_PORTA_APB + 0x510)))
#define GPIO_PORTB_PUR				(*((volatile unsigned long*)(BASE_GPIO_PORTB_APB + 0x510)))
#define GPIO_PORTC_PUR				(*((volatile unsigned long*)(BASE_GPIO_PORTC_APB + 0x510)))
#define GPIO_PORTD_PUR				(*((volatile unsigned long*)(BASE_GPIO_PORTD_APB + 0x510)))
#define GPIO_PORTE_PUR				(*((volatile unsigned long*)(BASE_GPIO_PORTE_APB + 0x510)))
#define GPIO_PORTF_PUR				(*((volatile unsigned long*)(BASE_GPIO_PORTF_APB + 0x510)))
// GPIO Pull-Down Select
#define GPIO_PORTA_PDR				(*((volatile unsigned long*)(BASE_GPIO_PORTA_APB + 0x514)))
#define GPIO_PORTB_PDR				(*((volatile unsigned long*)(BASE_GPIO_PORTB_APB + 0x514)))
#define GPIO_PORTC_PDR				(*((volatile unsigned long*)(BASE_GPIO_PORTC_APB + 0x514)))
#define GPIO_PORTD_PDR				(*((volatile unsigned long*)(BASE_GPIO_PORTD_APB + 0x514)))
#define GPIO_PORTE_PDR				(*((volatile unsigned long*)(BASE_GPIO_PORTE_APB + 0x514)))
#define GPIO_PORTF_PDR				(*((volatile unsigned long*)(BASE_GPIO_PORTF_APB + 0x514)))

//Open-drain register
#define GPIO_PORTA_ODR				(*((volatile unsigned long*)(BASE_GPIO_PORTA_APB+0x50C)))
#define GPIO_PORTB_ODR				(*((volatile unsigned long*)(BASE_GPIO_PORTB_APB+0x50C)))
#define GPIO_PORTC_ODR				(*((volatile unsigned long*)(BASE_GPIO_PORTC_APB+0x50C)))
#define GPIO_PORTD_ODR				(*((volatile unsigned long*)(BASE_GPIO_PORTD_APB+0x50C)))
#define GPIO_PORTE_ODR				(*((volatile unsigned long*)(BASE_GPIO_PORTE_APB+0x50C)))
#define GPIO_PORTF_ODR				(*((volatile unsigned long*)(BASE_GPIO_PORTF_APB+0x50C)))
////////////////////////////////////////////////////////////////////////////////////////

//PINS
#define GPIO_LOCK_KEY					0x4C4F434B
#define PIN_0							0
#define PIN_1							1
#define PIN_2							2
#define PIN_3							3
#define PIN_4							4
#define PIN_5							5
#define PIN_6							6
#define PIN_7							7

////////////////////////////////////////////////////////////////////////////
//enums
// for initing GPIO
typedef enum{
	PORTA,PORTB,PORTC,PORTD,PORTE,PORTF
}GPIO_Port_Select;
//for init a pin
typedef enum{
	Input, Output
}GPIO_Mode_Select;
typedef enum{
	Clear, Set
}GPIO_Write_Select;
typedef enum{
	Pull_down, Pull_up,Floating
}GPIO_Polarity_Select;
typedef enum{
	RED=1,BLUE,GREEN
}LED_COLOR_PORTF;

/////////////////////////////////////////////////////////////////////////////////
//ProtoTypes
void GPIO_Init(GPIO_Port_Select GPPS); // just give clock to the GPIO
void GPIO_Digital_INIT(GPIO_Port_Select GPPS,uint32_t pin);// enable one pin as an input digital
void GPIO_Digital_PIN_MODE(GPIO_Port_Select Port,uint8_t pin, GPIO_Mode_Select Mode, GPIO_Polarity_Select Polarity);
void GPIO_Write_Pin(GPIO_Port_Select GPPS, uint32_t pin, GPIO_Write_Select data);
uint8_t GPIO_Read_pin(GPIO_Port_Select GPPS, uint32_t pin);
void RGB_PORTF_Activate(LED_COLOR_PORTF COLOR);
#endif
