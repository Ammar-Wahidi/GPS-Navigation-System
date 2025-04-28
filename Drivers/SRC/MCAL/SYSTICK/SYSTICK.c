//
// SYSTICK.h
//

#include "../../../Headers/MCAL/SYSTICK/SYSTICK.H"

// Initialize the SysTick timer
void SYSTICKInit() {
    NVIC_ST_CTRL = SYSTICK_CTRL_DISABLE;       // Disable SysTick during setup
    NVIC_ST_RELOAD = SYSTICK_RELOAD_MAX;        // Set reload register to maximum value
    NVIC_ST_CURRENT = 0;                        // Clear the current value register
    NVIC_ST_CTRL = SYSTICK_CTRL_ENABLE_CORECLK; // Enable SysTick with core clock and no interrupt
}

// Wait for a specific number of clock cycles (blocking delay)
void SYSTICK_Wait(unsigned long delay) {
    NVIC_ST_CTRL = SYSTICK_CTRL_DISABLE;        // Disable SysTick to configure
    NVIC_ST_RELOAD = delay - 1;                 // Set reload register (counts down to zero)
    NVIC_ST_CURRENT = 0;                        // Clear the current value register
    NVIC_ST_CTRL = SYSTICK_CTRL_ENABLE_CORECLK;  // Enable SysTick with core clock

    while ((NVIC_ST_CTRL & SYSTICK_COUNT_FLAG) == 0); // Wait until COUNT flag is set (timer hits 0)
}

// Generate a delay in milliseconds (assuming 80 MHz clock -> 1 ms = 80000 cycles)
void Generic_delay(unsigned long time) {
    int i;
    for (i = 0; i < time; i++) {
        SYSTICK_Wait(80000); // 80000 cycles delay ˜ 1 ms at 80 MHz
    }
}
