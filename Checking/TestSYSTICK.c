#include "../Drivers/Headers/MCAL/SYSTICK/SYSTICK.h"   // Include SysTick (delay) driver
#include "../Drivers/Headers/MCAL/GPIO/GPIO.h"      // Include GPIO driver

int main()
{
    GPIO_Init(PORTF);   // Enable clock and initialize PORTF (for RGB LEDs)
    SYSTICKInit();      // Initialize SysTick timer for delay generation

    while (1)           // Infinite loop
    {
        Generic_delay(1000);          // Wait 1000 ms (1 second)
        RGB_PORTF_Activate(RED);       // Turn ON RED LED

        Generic_delay(1000);          // Wait 1 second
        RGB_PORTF_Activate(BLUE);      // Turn ON BLUE LED

        Generic_delay(1000);          // Wait 1 second
        RGB_PORTF_Activate(GREEN);     // Turn ON GREEN LED

        // This sequence repeats forever
    }
}
