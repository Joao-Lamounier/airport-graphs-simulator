#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "files/readFile.h"
#include "entities/airports/airports.h"
#include "entities/routes/routes.h"
#include "entities/flights/flights.h"


int main() {


//    Airport airports[23];
//    newAirports(airports);
//    for (int i = 0; i < 23; ++i) {
//        printf("\n===========================\n");
//        airports[i]->toString(airports[i]);
//    }

//    Route routes[34];
//    newRoutes(routes);
//    for (int i = 0; i < 34; ++i){
//        routes[i]->toString(routes[i]);
//        printf("\n");
//    }

    Flight flights[723];
    newFlights(flights);
    for (int i = 0; i < 723; ++i) {
        flights[i]->toString(flights[i]);
        printf("\n");
    }
    return 0;
}
