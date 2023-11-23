#ifndef AIRPORT_GRAPHS_SIMULATOR_ARRAYLIST_H
#define AIRPORT_GRAPHS_SIMULATOR_ARRAYLIST_H

#include "../../entities/flights/Flight.h"
#include "../vertex/Vertex.h"

typedef struct _ArrayList {
    int size;
    Flight *flights;
} _ArrayList;
typedef _ArrayList *ArrayList;

ArrayList newArrayList();

void append(ArrayList list, Flight flight);

void newArrayLists(ArrayList lists[MAX_AIRPORTS], Vertex vertexes[MAX_VERTEXES]);

#endif //AIRPORT_GRAPHS_SIMULATOR_ARRAYLIST_H
