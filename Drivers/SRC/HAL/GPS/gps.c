#include "../../../Headers/HAL/GPS/gps.h"
#include "../../../Headers/MCAL/UART/UART.h"

bool validate_GPRMC_string(const char* GPRMC_String) {
    if (!GPRMC_String) return false;
    return (strncmp(GPRMC_String, "$GPRMC,", 7) == 0);
}

bool validate_GPRMC_checksum(const char* GPRMC_String) {
    const char* checksum_start;
    int calculated_checksum = 0;
    int expected_checksum = 0;
    const char* p;

    if (!GPRMC_String) return false;

    checksum_start = strchr(GPRMC_String, '*');
    if (!checksum_start || strlen(checksum_start) < 3) return false;

    for (p = GPRMC_String + 1; p < checksum_start; ++p) {
        calculated_checksum ^= *p;
    }

    expected_checksum = (int)strtol(checksum_start + 1, NULL, 16);
    return (expected_checksum == calculated_checksum);
}

bool is_GPRMC_data_valid(char* GPRMC_String) {
    int index = 0;
    int commas = 0;

    if (!GPRMC_String) return false;

    while (GPRMC_String[index] && commas < 2) {
        if (GPRMC_String[index++] == ',') commas++;
    }

    if (GPRMC_String[index] == 'A') {
        return true; // Data is Active
    }
    return false; // Data is Void (invalid)
}

void get_Time(char* GPRMC_String, char* Time_Buffer) {

    int index = 0;
    int commas = 0;
    char time_raw[11] = {0};
    int i = 0;
    long time_val;
    int h, m, s;

    if (!GPRMC_String || !Time_Buffer) return;

    while (GPRMC_String[index] && commas < 1) {
        if (GPRMC_String[index++] == ',') commas++;
    }

    while (GPRMC_String[index] != ',' && GPRMC_String[index] && i < 10) {
        time_raw[i++] = GPRMC_String[index++];
    }

    if (i == 0) {
        strcpy(Time_Buffer, "00:00:00");
        return;
    }

    time_val = atol(time_raw);
    h = time_val / 10000;
    m = (time_val % 10000) / 100;
    s = time_val % 100;

    sprintf(Time_Buffer, "%02d:%02d:%02d", h, m, s);
}

void get_Latitude(char* GPRMC_String, char* Latitude_Buffer) {
    int index = 0;
    int commas = 0;
    char lat_raw[20] = {0};
    char ns_indicator = 'N';
    int i = 0;
    float raw;
    int degrees;
    float minutes;
    float decimal;

    if (!GPRMC_String || !Latitude_Buffer) return;

    while (GPRMC_String[index] && commas < 3) {
        if (GPRMC_String[index++] == ',') commas++;
    }

    while (GPRMC_String[index] != ',' && GPRMC_String[index] && i < 15) {
        lat_raw[i++] = GPRMC_String[index++];
    }
    lat_raw[i] = '\0';
		lat_raw[i+1] = '\0';
		

    if (GPRMC_String[index] == ',') {
        ns_indicator = GPRMC_String[++index];
    }

    raw = atof(lat_raw);
    degrees = (int)(raw / 100);
    minutes = raw - (degrees * 100);
    decimal = degrees + minutes / 60.0;

    if (ns_indicator == 'S') {
        decimal *= -1;
    }

    sprintf(Latitude_Buffer, "%.8f", decimal);
				UART0_Print("\n\r");//
		UART0_Print("lat in function :"); //
			  UART0_Print(Latitude_Buffer); //
		UART0_Print("\n\r"); //
}

void get_Longitude(char* GPRMC_String, char* Longitude_Buffer) {
		char temp [16];
    int index = 0;
    int commas = 0;
    char lon_raw[16] = {0};
    char ew_indicator = 'E';
    int i = 0;
    float raw;
    int degrees;
    float minutes;
    float decimal;

    if (!GPRMC_String || !Longitude_Buffer) return;

    while (GPRMC_String[index] && commas < 5) {
        if (GPRMC_String[index++] == ',') commas++;
    }

    while (GPRMC_String[index] != ',' && GPRMC_String[index] && i < 15) {
        lon_raw[i++] = GPRMC_String[index++];
    }
    lon_raw[i] = '\0';

    if (GPRMC_String[index] == ',') {
        ew_indicator = GPRMC_String[++index];
    }

    raw = atof(lon_raw);
    degrees = (int)(raw / 100);
    minutes = raw - (degrees * 100);
    decimal = degrees + minutes / 60.0f;

    if (ew_indicator == 'W') {
        decimal *= -1;
    }
		
    sprintf(Longitude_Buffer, "%.8f", decimal);
}

void getSpeed(char* GPRMC_String, char* speed_buffer) {
    int index = 0;
    int commas = 0;
    char speed_knots[10] = {0};
    int i = 0;
    float speed;

    if (!GPRMC_String || !speed_buffer) return;

    while (GPRMC_String[index] && commas < 7) {
        if (GPRMC_String[index++] == ',') commas++;
    }

    while (GPRMC_String[index] != ',' && GPRMC_String[index] && i < 9) {
        speed_knots[i++] = GPRMC_String[index++];
    }
    speed_knots[i] = '\0';

    speed = atof(speed_knots) * 0.514444f; // Convert knots to m/s
    sprintf(speed_buffer, "%.2f", speed);
}
