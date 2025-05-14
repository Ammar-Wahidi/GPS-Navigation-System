// Includes: standard C libs, TM4C hardware defs, and custom modules (GPS, LCD, UART, etc.)
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#include <stdlib.h>
#include "../../../Headers/HAL/GPS/GPS.h"
#include "../../../Headers/HAL/LCD/LCD.h"
#include "../../../Headers/MCAL/UART/UART.h"
#include "../../../Headers/MCAL/SYSTICK/SYSTICK.h"
#include "../../../Headers/MCAL/SYSTICK/GPIO/GPIO.h"
#include "../../../Services/tm4c123gh6pm.h"
#include <stdio.h>
#include <ctype.h>

#define LCD_Clear() lcd_cmd(0x01)
#define LCD_OutString(str) lcd_string(str, strlen(str))

// Global vars for current position and distance
float theta;
float latit;
float longit;

// Landmark structure and list
typedef struct {
    char name[50];
    float latitude;
    float longitude;
    float trigger_distance;
} Landmark;

Landmark faculty_landmarks[] = {
    {"Hall A", 30.06445885f, -31.28033829f, 50.0},
    {"Luban Workshop", 30.06307030f, -31.27904892f, 50.0},
    {"Civil", 30.06437302f, -31.27773094f, 50.0},
    {"Fountain", 30.06564522f, -31.27839088f, 50.0},
    {"Library", 30.06504440f, -31.27994537f, 50.0},
    {"zeroerror", 0.0f, 0.0f, 0.0},
    {"zeroerror", 0.0f, 0.0f, 0.0}
};

#define NUM_LANDMARKS (sizeof(faculty_landmarks)/sizeof(faculty_landmarks[0]))

// Function prototypes
int FindNearestLandmark(float lat, float lon);
float calc_distance(float lon1, float lat1, float lon2, float lat2);
float to_radians(float degrees);
float abss(float x);
float str_to_float(const char *str);

int main(void) {
    // Initialization
    char gprmc[100], Latitude[16], Longitude[16], speed[16];
    int indee;
    GPIO_Init(PORTA);
    GPIO_Init(PORTD);
    UART0_Init(); 
    UART2_Init();
    UART0_Print("RST");
    LCDSystem();
    lcdin();
    LCD_Clear();
    LCD_OutString("GPS System");

    // Main loop: read GPS data, calculate distance, update LCD
    while (1) {
        UART2_ReadLine(gprmc, 100);
        if (!validate_GPRMC_string(gprmc) || !validate_GPRMC_checksum(gprmc)) continue;

        UART0_Print(gprmc);
        get_Longitude(gprmc, Longitude);			
        get_Latitude(gprmc, Latitude);	
        getSpeed(gprmc, speed);

        latit = str_to_float(Latitude);
        longit = str_to_float(Longitude) * -1.0f;

        indee = FindNearestLandmark(latit, longit);

        LCD_Clear();
        lcd_cmd(0x80);
        LCD_OutString("Speed: ");
        LCD_OutString(speed);
        lcd_cmd(0xC0);
        LCD_OutString(faculty_landmarks[indee].name);

        // Alert if Library is reached
        if (strcmp(faculty_landmarks[indee].name, "Library") == 0) {
            GPIO_PORTA_DATA_R |= (1U << 2);
            Generic_delay(200);
            GPIO_PORTA_DATA_R &= ~(1U << 2);
        }

        Generic_delay(200);
    }
}

// Find index of nearest landmark
int FindNearestLandmark(float lat, float lon) {
    int idx = 0;
    float minDist = FLT_MAX;
    for (int i = 0; i < NUM_LANDMARKS; i++) {
        dist = calc_distance(lat, lon, faculty_landmarks[i].latitude, faculty_landmarks[i].longitude);
        if (dist < minDist) {
            minDist = dist;
            idx = i;
        }
    }
    theta = minDist * 1000;
    return idx;
}

// Calculate distance using Haversine formula
float calc_distance(float lon1, float lat1, float lon2, float lat2) {
    float dlat = to_radians(abss(lat2 - lat1));
    float dlon = to_radians(abss(lon2 - lon1));
    float a = sinf(dlat/2) * sinf(dlat/2) +
              cosf(to_radians(lat1)) * cosf(to_radians(lat2)) *
              sinf(dlon/2) * sinf(dlon/2);
    float c = 2 * atanf(sqrtf(a) / sqrtf(1 - a));
    
    char temppp[16];
    sprintf(temppp, "%.8f", RADIUS * c * 1000.0f);
    UART0_Print("dist:\n\r");
    UART0_Print(temppp);
    UART0_Print("\n\r");

    return RADIUS * c * 1000.0f;
}

// Degree to radian conversion
float to_radians(float degrees) {
    return degrees * (M_PI / 180.0f);
}

// Absolute value
float abss(float x) {
    return (x < 0) ? -x : x;
}

// Convert string to float
float str_to_float(const char *str) {
    float result = 0.0f, decimal_factor = 0.1f;
    int sign = 1, decimal_found = 0;

    while (isspace(*str)) str++;
    if (*str == '-') { sign = -1; str++; }
    else if (*str == '+') str++;

    while (*str) {
        if (*str == '.') {
            if (decimal_found) break;
            decimal_found = 1;
        } else if (isdigit(*str)) {
            int digit = *str - '0';
            if (!decimal_found)
                result = result * 10.0f + digit;
            else {
                result += digit * decimal_factor;
                decimal_factor *= 0.1f;
            }
        } else break;
        str++;
    }

    return sign * result;
}