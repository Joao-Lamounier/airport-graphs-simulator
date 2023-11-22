#ifndef AIRPORT_GRAPHS_SIMULATOR_FLIGHTS_H
#define AIRPORT_GRAPHS_SIMULATOR_FLIGHTS_H

#define MAX_FLIGHTS 723

#define FILEFLIGHTS "files/flights.txt"

typedef struct _Flight {
    char airLine[3];
    int idFlight;
    char source[4];
    char *departure;
    char target[4];
    char *arrival;
    int stops;

    void (*toString)(struct _Flight *);
} _Flight;
typedef _Flight *Flight;

Flight
newFlight(char airLine[4], int idFlight, char source[4], char *departure, char target[4], char *arrival, int stops);

void newFlights(Flight flights[MAX_FLIGHTS]);

void printFlight(Flight flight);

#endif //AIRPORT_GRAPHS_SIMULATOR_FLIGHTS_H
