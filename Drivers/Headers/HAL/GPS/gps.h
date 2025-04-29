#ifndef GPS
#define GPS
#include <stdbool.h>
#include "stdint.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846f

#define RADIUS 6371 // Earth radius in kilometers


bool validate_GPRMC_string(const char* GPRMC_String);
bool validate_GPRMC_checksum(const char* GPRMC_String);
void get_Time(const char* GPRMC_String, char* Time_Buffer);
void get_Latitude(const char* GPRMC_String, char* Latitude_Buffer);
void get_Longitude(const char* GPRMC_String, char* Longitude_Buffer);
void getSpeed(const char* GPRMC_String, char* speed_buffer);
float Distance(const char* lat1_str, const char* lon1_str, const char* lat2_str, const char* lon2_str);

#endif // GPS_H_INCLUDED
