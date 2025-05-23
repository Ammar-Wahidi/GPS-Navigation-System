#include "../../../Headers/MCAL/GPIO/GPIO.H"

// Initialize the selected GPIO port and unlock it
void GPIO_Init(GPIO_Port_Select GPPS){
	switch(GPPS){
		case PORTA:
			SET_BIT(RCGCGPIO,PORTA);                  // Enable clock to PORTA
			while((PRGPIO & 0x1<<PORTA) == 0);        // Wait for port to be ready
			GPIO_PORTA_LOCK = GPIO_LOCK_KEY;         // Unlock PORTA
		break;
		case PORTB:
			SET_BIT(RCGCGPIO,PORTB);
			while((PRGPIO & 0x1<<PORTB) == 0);
			GPIO_PORTB_LOCK = GPIO_LOCK_KEY;
		break;
		case PORTC:
			SET_BIT(RCGCGPIO,PORTC);
			while((PRGPIO & 0x1<<PORTC) == 0);
			GPIO_PORTC_LOCK = GPIO_LOCK_KEY;
		break;
		case PORTD:
			SET_BIT(RCGCGPIO,PORTD);
			while((PRGPIO & 0x1<<PORTD) == 0);
			GPIO_PORTD_LOCK = GPIO_LOCK_KEY;
		break;
		case PORTE:
			SET_BIT(RCGCGPIO,PORTE);
			while((PRGPIO & 0x1<<PORTE) == 0);
			GPIO_PORTE_LOCK = GPIO_LOCK_KEY;
		break;
		case PORTF:
			SET_BIT(RCGCGPIO,PORTF);
			while((PRGPIO & 0x1<<PORTF) == 0);
			GPIO_PORTF_LOCK = GPIO_LOCK_KEY;
		break;
	}
}

// Enable digital function and disable alternate/analog modes for the selected pin
void GPIO_Digital_INIT(GPIO_Port_Select GPPS, uint32_t pin){
	switch(GPPS){
		case PORTA:
			SET_BIT(GPIO_PORTA_CR, pin);
			CLR_BIT(GPIO_PORTA_AMSEL, pin);
			CLR_BIT(GPIO_PORTA_AFSEL, pin);
			GPIO_PORTA_PCTL &= ~(0xF << (pin * 4));
			SET_BIT(GPIO_PORTA_DEN, pin);
		break;
		case PORTB:
			SET_BIT(GPIO_PORTB_CR, pin);
			CLR_BIT(GPIO_PORTB_AMSEL, pin);
			CLR_BIT(GPIO_PORTB_AFSEL, pin);
			GPIO_PORTB_PCTL &= ~(0xF << (pin * 4));
			SET_BIT(GPIO_PORTB_DEN, pin);
		break;
		case PORTC:
			SET_BIT(GPIO_PORTC_CR, pin);
			CLR_BIT(GPIO_PORTC_AMSEL, pin);
			CLR_BIT(GPIO_PORTC_AFSEL, pin);
			GPIO_PORTC_PCTL &= ~(0xF << (pin * 4));
			SET_BIT(GPIO_PORTC_DEN, pin);
		break;
		case PORTD:
			SET_BIT(GPIO_PORTD_CR, pin);
			CLR_BIT(GPIO_PORTD_AMSEL, pin);
			CLR_BIT(GPIO_PORTD_AFSEL, pin);
			GPIO_PORTD_PCTL &= ~(0xF << (pin * 4));
			SET_BIT(GPIO_PORTD_DEN, pin);
		break;
		case PORTE:
			SET_BIT(GPIO_PORTE_CR, pin);
			CLR_BIT(GPIO_PORTE_AMSEL, pin);
			CLR_BIT(GPIO_PORTE_AFSEL, pin);
			GPIO_PORTE_PCTL &= ~(0xF << (pin * 4));
			SET_BIT(GPIO_PORTE_DEN, pin);
		break;
		case PORTF:
			SET_BIT(GPIO_PORTF_CR, pin);
			CLR_BIT(GPIO_PORTF_AMSEL, pin);
			CLR_BIT(GPIO_PORTF_AFSEL, pin);
			GPIO_PORTF_PCTL &= ~(0xF << (pin * 4));
			SET_BIT(GPIO_PORTF_DEN, pin);
		break;
	}
}

// Set pin direction and configure pull-up/down resistors based on mode and polarity
void GPIO_Digital_PIN_MODE(GPIO_Port_Select Port, uint8_t pin, GPIO_Mode_Select Mode, GPIO_Polarity_Select Polarity){
	switch(Port){
		case PORTA:
			if(Mode)
				SET_BIT(GPIO_PORTA_DIR, pin);         // Output mode
			else{
				CLR_BIT(GPIO_PORTA_DIR, pin);         // Input mode
				if(Polarity == 0) SET_BIT(GPIO_PORTA_PUR, pin);         // Pull-up
				else if(Polarity == 1) SET_BIT(GPIO_PORTA_PDR, pin);    // Pull-down
				else {
					CLR_BIT(GPIO_PORTA_PUR, pin); CLR_BIT(GPIO_PORTA_PDR, pin); // No pull
				}
			}
		break;
		case PORTB:
			if(Mode)
				SET_BIT(GPIO_PORTB_DIR, pin);
			else{
				CLR_BIT(GPIO_PORTB_DIR, pin);
				if(Polarity == 0) SET_BIT(GPIO_PORTB_PUR, pin);
				else if(Polarity == 1) SET_BIT(GPIO_PORTB_PDR, pin);
				else {
					CLR_BIT(GPIO_PORTB_PUR, pin); CLR_BIT(GPIO_PORTB_PDR, pin);
				}
			}
		break;
		case PORTC:
			if(Mode)
				SET_BIT(GPIO_PORTC_DIR, pin);
			else{
				CLR_BIT(GPIO_PORTC_DIR, pin);
				if(Polarity == 0) SET_BIT(GPIO_PORTC_PUR, pin);
				else if(Polarity == 1) SET_BIT(GPIO_PORTC_PDR, pin);
				else {
					CLR_BIT(GPIO_PORTC_PUR, pin); CLR_BIT(GPIO_PORTC_PDR, pin);
				}
			}
		break;
		case PORTD:
			if(Mode)
				SET_BIT(GPIO_PORTD_DIR, pin);
			else{
				CLR_BIT(GPIO_PORTD_DIR, pin);
				if(Polarity == 0) SET_BIT(GPIO_PORTD_PUR, pin);
				else if(Polarity == 1) SET_BIT(GPIO_PORTD_PDR, pin);
				else {
					CLR_BIT(GPIO_PORTD_PUR, pin); CLR_BIT(GPIO_PORTD_PDR, pin);
				}
			}
		break;
		case PORTE:
			if(Mode)
				SET_BIT(GPIO_PORTE_DIR, pin);
			else{
				CLR_BIT(GPIO_PORTE_DIR, pin);
				if(Polarity == 0) SET_BIT(GPIO_PORTE_PUR, pin);
				else if(Polarity == 1) SET_BIT(GPIO_PORTE_PDR, pin);
				else {
					CLR_BIT(GPIO_PORTE_PUR, pin); CLR_BIT(GPIO_PORTE_PDR, pin);
				}
			}
		break;
		case PORTF:
			if(Mode)
				SET_BIT(GPIO_PORTF_DIR, pin);
			else{
				CLR_BIT(GPIO_PORTF_DIR, pin);
				if(Polarity == 0) SET_BIT(GPIO_PORTF_PUR, pin);
				else if(Polarity == 1) SET_BIT(GPIO_PORTF_PDR, pin);
				else {
					CLR_BIT(GPIO_PORTF_PUR, pin); CLR_BIT(GPIO_PORTF_PDR, pin);
				}
			}
		break;
	}
}

// Write a value to the selected GPIO pin
void GPIO_Write_Pin(GPIO_Port_Select GPPS, uint32_t pin, GPIO_Write_Select data){
	switch(GPPS){
		case PORTA:
			if(data) SET_BIT(GPIO_PORTA_DATA, pin);
			else CLR_BIT(GPIO_PORTA_DATA, pin);
		break;
		case PORTB:
			if(data) SET_BIT(GPIO_PORTB_DATA, pin);
			else CLR_BIT(GPIO_PORTB_DATA, pin);
		break;
		case PORTC:
			if(data) SET_BIT(GPIO_PORTC_DATA, pin);
			else CLR_BIT(GPIO_PORTC_DATA, pin);
		break;
		case PORTD:
			if(data) SET_BIT(GPIO_PORTD_DATA, pin);
			else CLR_BIT(GPIO_PORTD_DATA, pin);
		break;
		case PORTE:
			if(data) SET_BIT(GPIO_PORTE_DATA, pin);
			else CLR_BIT(GPIO_PORTE_DATA, pin);
		break;
		case PORTF:
			if(data) SET_BIT(GPIO_PORTF_DATA, pin);
			else CLR_BIT(GPIO_PORTF_DATA, pin);
		break;
	}
}

// Read the logic level of the selected GPIO pin
uint8_t GPIO_Read_pin(GPIO_Port_Select GPPS, uint32_t pin){
	switch(GPPS){
		case PORTA: return GET_BIT(GPIO_PORTA_DATA, pin);
		case PORTB: return GET_BIT(GPIO_PORTB_DATA, pin);
		case PORTC: return GET_BIT(GPIO_PORTC_DATA, pin);
		case PORTD: return GET_BIT(GPIO_PORTD_DATA, pin);
		case PORTE: return GET_BIT(GPIO_PORTE_DATA, pin);
		case PORTF: return GET_BIT(GPIO_PORTF_DATA, pin);
	}
}

// Activate one color on RGB LED connected to PORTF
void RGB_PORTF_Activate(LED_COLOR_PORTF COLOR)
{
	// Deactivate all colors (turn off all pins)
	GPIO_Write_Pin(PORTF, PIN_1, Set);  // RED off
	GPIO_Write_Pin(PORTF, PIN_2, Set);  // BLUE off
	GPIO_Write_Pin(PORTF, PIN_3, Set);  // GREEN off

	// Activate selected color (drive pin low)
	if (COLOR == RED)
	{
		GPIO_Digital_INIT(PORTF, PIN_1);
		GPIO_Digital_PIN_MODE(PORTF, PIN_1, Output, 2);
		GPIO_Write_Pin(PORTF, PIN_1, Clear); // RED on
	}
	else if (COLOR == BLUE)
	{
		GPIO_Digital_INIT(PORTF, PIN_2);
		GPIO_Digital_PIN_MODE(PORTF, PIN_2, Output, 2);
		GPIO_Write_Pin(PORTF, PIN_2, Clear); // BLUE on
	}
	else if (COLOR == GREEN)
	{
		GPIO_Digital_INIT(PORTF, PIN_3);
		GPIO_Digital_PIN_MODE(PORTF, PIN_3, Output, 2);
		GPIO_Write_Pin(PORTF, PIN_3, Clear); // GREEN on
	}
}