#include <malloc.h>
#include "GraphList.h"
#include "../../services/airports_service/AirportsServices.h"

GraphFlights newGraphFlights(Vertex vertexes[MAX_VERTEXES]) {
    GraphFlights graph = (_GraphList *) malloc(sizeof(_GraphList));

    ArrayList lists[MAX_AIRPORTS];
    newArrayLists(lists, vertexes);

    for (int i = 0; i < MAX_AIRPORTS; ++i) {
        graph->lists[i] = lists[i];
    }
    for (int i = 0; i < MAX_VERTEXES; ++i) {
        graph->vertexes[i] = vertexes[i];
    }

    graph->toString = printFlights;

    return graph;
}

void printFlights(GraphFlights graph) {
    int count = 0;
    for (int i = 0; i < MAX_VERTEXES; ++i) {
        for (int j = 0; j < graph->lists[i]->size; ++j) {
            printf("\n-----------------------\n");
            graph->lists[i]->flights[j]->toString(graph->lists[i]->flights[j]);
            count++;
        }
    }
}


void shortestPath(GraphFlights graphFlights){
    char origin[4], destin[4];
    getCodeFromUser("Origem", origin);
    getCodeFromUser("Destino", destin);

    int position = designatePosition(graphFlights->vertexes, origin);

    graphFlights->lists[position]->flights;
}