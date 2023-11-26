#include <stdbool.h>
#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <string.h>
#include "PathGraphList.h"
#include "../../structures/graph_list/GraphList.h"
#include "../airports_service/AirportsServices.h"
#include "../../structures/graph_matrix/GraphMatrix.h"
#include "../../utils/utils.h"

void getDirectFlights(GraphFlights graph) {
    char code[4];
    getCodeFromUser("Origem", code);
    int position = designatePosition(graph->vertexes, code);

    bool directed = false;

    for (int i = 0; i < graph->lists[position]->size; ++i) {
        if (graph->lists[position]->flights[i]->stops == 0) {
            if (!directed) {
                printf("\n✈️ Voos Diretos de %s", code);
            }
            directed = true;
            printf("\n");
            graph->lists[position]->flights[i]->toString(graph->lists[position]->flights[i]);
        }
    }

    if (!directed) {
        printf("\n😔 Não há voos diretos partindo de: %s", code);
    }
}

int getFlightDuration(GraphFlights graphFlights, char *origin, char *destin, int nFlights) {

    char h1[6];
    char h2[6];
    int a1 = designatePosition(graphFlights->vertexes, origin);
    int a2 = designatePosition(graphFlights->vertexes, destin);


    timeZoneToUTC(graphFlights->lists[a1]->flights[nFlights]->departure, h1,
                  graphFlights->vertexes[a1]->airport->timezone);
    timeZoneToUTC(graphFlights->lists[a1]->flights[nFlights]->arrival, h2,
                  graphFlights->vertexes[a2]->airport->timezone);

    return timeDifference(h1, h2);
}

void shortestPathTime(GraphFlights graphFlights, char *codOrigin, char *codTarget) {

    int position = designatePosition(graphFlights->vertexes, codOrigin);

    int smaller = -1;
    int current;
    int index = -1;
    for (int i = 0; i < graphFlights->lists[position]->size; ++i) {
        if (strcmp(graphFlights->lists[position]->flights[i]->target, codTarget) == 0) {
            current = getFlightDuration(graphFlights, codOrigin, codTarget, i);
            if (current < smaller || smaller == -1) {
                index = i;
                smaller = current;
            }
        }
    }
    if (smaller != -1) {
        char hour[6];
        convertMinutesToHours(hour, smaller);
        printf("\n");
        graphFlights->lists[position]->flights[index]->toString(graphFlights->lists[position]->flights[index]);
        printf("Menor tempo de voo: %s", hour);
    }

}