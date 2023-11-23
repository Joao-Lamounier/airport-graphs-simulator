#include <malloc.h>
#include <string.h>
#include "Flight.h"
#include "../../files/ReadFile.h"

Flight
newFlight(char airLine[4], int idFlight, char source[4], char *departure, char target[4], char *arrival,
          int stops) {
    Flight flight = (Flight) malloc(sizeof(_Flight));
    strcpy(flight->airLine, airLine);
    flight->idFlight = idFlight;
    strcpy(flight->source, source);
    flight->departure = departure;
    strcpy(flight->target, target);
    flight->arrival = arrival;
    flight->stops = stops;
    flight->toString = printFlight;

    return flight;
}

void printFlight(Flight flight) {
    printf("✈️ Companhia Aérea: %s\n", flight->airLine);
    printf("🔢 Voo: %d\n", flight->idFlight);
    printf("🛫 Origem: %s\n", flight->source);
    printf("🕒 Horário de Partida: %s\n", flight->departure);
    printf("🛬 Destino: %s\n", flight->target);
    printf("🕙 Horário de Chegada: %s\n", flight->arrival);
    printf("🛑 Paradas: %d\n", flight->stops);
}

void newFlights(Flight flights[MAX_FLIGHTS]) {
    char *allFlights = readFile(FILEFLIGHTS);
    char *token = strtok(allFlights, "\n");

    int count = 0;
    while (token != NULL && count < MAX_FLIGHTS) {
        char airLine[3];
        int idFlight;
        char source[4];
        char departure[20];
        char target[4];
        char arrival[20];
        int stops;

        if (sscanf(token, "%2s %d %3s %19[^ ] %3s %19[^ ] %d", airLine, &idFlight, source, departure, target, arrival,
                   &stops) == 7) {
            airLine[2] = '\0';
            source[3] = '\0';
            target[3] = '\0';


            flights[count] = newFlight(airLine, idFlight, source, strdup(departure), target, strdup(arrival), stops);
            count++;
        }
        token = strtok(NULL, "\n");
    }
}


