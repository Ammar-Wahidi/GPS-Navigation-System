//
//SYSTICK.h
//

#ifndef SYSTICK
#define SYSTICK
#include "../GPIO/GPIO.h"
#include <stdint.h>
#include "../../../Services/Bit_Utilies.h"

//general defines
#define NVIC_ST_CTRL     (*((volatile uint32_t*)0xE000E010))
#define NVIC_ST_RELOAD   (*((volatile uint32_t*)0xE000E014))
#define NVIC_ST_CURRENT  (*((volatile uint32_t*)0xE000E018))

// ------------ Macro Definitions ------------
#define SYSTICK_CTRL_ENABLE_CORECLK  0x05      // Enable SysTick Timer, use system clock, no interrupt
#define SYSTICK_CTRL_DISABLE         0x00      // Disable SysTick Timer
#define SYSTICK_RELOAD_MAX            0xFFFFFF // 24-bit maximum reload value
#define SYSTICK_COUNT_FLAG            0x00010000 // COUNT flag position (bit 16)

//PROTOTYPES
/**
 * @brief Initialize the SysTick timer.
 *
 * Sets the SysTick to use the core clock, sets maximum reload value,
 * and enables the counter without interrupts.
 */
void SYSTICKInit();
/**
 * @brief Wait for a specific number of clock cycles (busy-wait delay).
 *
 * @param delay Number of cycles to wait.
 */
void SYSTICK_Wait(unsigned long delay);
/**
 * @brief Generate a generic delay based on milliseconds.
 *
 * @param time Number of milliseconds to delay.
 *
 * @note Assumes system clock is 80 MHz (each ms ˜ 80000 cycles).
 */
void Generic_delay(unsigned long time);
#endif
