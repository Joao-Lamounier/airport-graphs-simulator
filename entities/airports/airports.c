#include <malloc.h>
#include <string.h>
#include "airports.h"
#include "../../files/readFile.h"

Airport newAirport(char code[3], int timezone, int latitude, int longitude, char *city, char *state) {
    Airport airport = (Airport) malloc(sizeof(_Airport));
    strcpy(airport->code, code);
    airport->timezone = timezone;
    airport->latitude = latitude;
    airport->longitude = longitude;
    airport->city = city;
    airport->state = state;
    airport->toString = printAirport;
    return airport;
}

void printAirport(Airport airport) {
    printf("🔢 Código: %s\n", airport->code);
    printf("🕒 Fuso Horário: %d\n", airport->timezone);
    printf("🌐 Latitude: %d\n", airport->latitude);
    printf("🌐 Longitude: %d\n", airport->longitude);
    printf("📍 Cidade: %s\n", airport->city);
    printf("📍 Estado: %s\n", airport->state);
}

void newAirports(Airport airports[MAX_AIRPORTS]) {
    char *allAirports = readFile(FILEAIRPORT);
    char *token = strtok(allAirports, "\n");

    int count = 0;
    while (token != NULL && count < MAX_AIRPORTS) {
        char code[4];
        int timezone, latitude, longitude;
        char city[50], state[50];

        if (sscanf(token, "%3s %d, %d, %d, %49[^,], %49[^\n]", code, &timezone, &latitude, &longitude, city, state) == 6) {
            code[3] = '\0';

            airports[count] = newAirport(code, timezone, latitude, longitude, strdup(city), strdup(state));
            count++;

        }
        token = strtok(NULL, "\n");
    }
}

