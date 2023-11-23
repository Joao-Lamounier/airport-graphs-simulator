#ifndef AIRPORT_GRAPHS_SIMULATOR_EDGE_H
#define AIRPORT_GRAPHS_SIMULATOR_EDGE_H

#include "../vertex/Vertex.h"

#include <math.h>

typedef struct _Edge {
    double distance;
} _Edge;

typedef _Edge *Edge;

Edge newEdge(Vertex v1, Vertex v2);

#endif //AIRPORT_GRAPHS_SIMULATOR_EDGE_H
