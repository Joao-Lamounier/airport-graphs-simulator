#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "files/readFile.h"
#include "entities/airports/airports.h"


int main() {


    Airport airports[23];
    newAirports(airports);
    for (int i = 0; i < 23; ++i) {
        printf("\n===========================\n");
        airports[i]->print_airport(airports[i]);

    }
    return 0;
}
