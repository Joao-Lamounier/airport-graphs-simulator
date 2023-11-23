#ifndef AIRPORT_GRAPHS_SIMULATOR_GRAPHMATRIX_H
#define AIRPORT_GRAPHS_SIMULATOR_GRAPHMATRIX_H

#include "../vertex/Vertex.h"
#include "../edge/Edge.h"

typedef struct _Graph{
    Vertex vertex[MAX_VERTEXES];
    Edge distances[MAX_VERTEXES][MAX_VERTEXES];

    void (*toString)(struct _Graph*);
}_Graph;

typedef _Graph *GraphRoutes;

GraphRoutes newGraph(Vertex vertexes[MAX_VERTEXES];);

void printRoutes(GraphRoutes graph);

#endif //AIRPORT_GRAPHS_SIMULATOR_GRAPHMATRIX_H
