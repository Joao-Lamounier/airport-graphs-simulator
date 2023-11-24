#include <malloc.h>
#include "GraphList.h"

GraphFlights newGraphFlights(Vertex vertexes[MAX_VERTEXES]) {
    GraphFlights graph = (_GraphList *) malloc(sizeof(_GraphList));

    ArrayList lists[MAX_AIRPORTS];
    newArrayLists(lists, vertexes);

    for (int i = 0; i < MAX_AIRPORTS; ++i) {
        graph->lists[i] = lists[i];
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