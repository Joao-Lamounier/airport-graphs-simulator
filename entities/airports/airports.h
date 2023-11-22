#ifndef AIRPORT_GRAPHS_SIMULATOR_AIRPORTS_H
#define AIRPORT_GRAPHS_SIMULATOR_AIRPORTS_H

#define MAX_AIRPORTS 23

#define FILEAIRPORT "files/airports.txt"

typedef struct _Airport {
    char code[4];
    int timezone;
    int latitude;
    int longitude;
    char *city;
    char *state;

    void (*toString)(struct _Airport*);
} _Airport;
typedef _Airport *Airport;


Airport newAirport(char code[4], int timezone, int latitude, int longitude, char *city, char *state);

void newAirports(Airport airports [MAX_AIRPORTS]);

void printAirport(Airport airport);

#endif //AIRPORT_GRAPHS_SIMULATOR_AIRPORTS_H
