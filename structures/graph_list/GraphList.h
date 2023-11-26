#ifndef AIRPORT_GRAPHS_SIMULATOR_GRAPHLIST_H
#define AIRPORT_GRAPHS_SIMULATOR_GRAPHLIST_H

#include "../array_list/ArrayList.h"

typedef struct _GraphList{
    ArrayList lists[MAX_AIRPORTS];
    Vertex vertexes[MAX_VERTEXES];
    void (*toString)(struct _GraphList*);
}_GraphList;

typedef _GraphList *GraphFlights;

GraphFlights newGraphFlights(Vertex vertexes[MAX_VERTEXES]);

void printFlights(GraphFlights graph);


#endif //AIRPORT_GRAPHS_SIMULATOR_GRAPHLIST_H
