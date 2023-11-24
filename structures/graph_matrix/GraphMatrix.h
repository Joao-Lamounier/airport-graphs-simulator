#ifndef AIRPORT_GRAPHS_SIMULATOR_GRAPHMATRIX_H
#define AIRPORT_GRAPHS_SIMULATOR_GRAPHMATRIX_H

#include "../vertex/Vertex.h"
#include "../edge/Edge.h"

typedef struct _Graph{
    Vertex vertexes[MAX_VERTEXES];
    Edge distances[MAX_VERTEXES][MAX_VERTEXES];

    void (*toString)(struct _Graph*);
}_Graph;

typedef _Graph *GraphRoutes;

GraphRoutes newGraphRoutes(Vertex vertexes[23]);

void printRoutes(GraphRoutes graph);

#endif //AIRPORT_GRAPHS_SIMULATOR_GRAPHMATRIX_H
