#ifndef GPS
#define GPS
#include <stdbool.h>
#include "stdint.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265359f

#define RADIUS 6371.000000f // Earth's radius in Km


//float toRadians(float degree);
bool validate_GPRMC_string(const char* GPRMC_String);
bool validate_GPRMC_checksum(const char* GPRMC_String);
void get_Time(char* GPRMC_String, char* Time_Buffer);
void get_Latitude(char* GPRMC_String, char* Latitude_Buffer);
void get_Longitude(char* GPRMC_String, char* Longitude_Buffer);
void getSpeed(char* GPRMC_String, char* speed_buffer);
//float calc_distance(float lon1, float lat1, float lon2, float lat2);

#endif // GPS_H_INCLUDED
