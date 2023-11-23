#ifndef AIRPORT_GRAPHS_SIMULATOR_VERTEX_H
#define AIRPORT_GRAPHS_SIMULATOR_VERTEX_H

#include "../../entities/airports/Airport.h"

#define MAX_VERTEXES 23

typedef struct _Vertex{
    Airport airport;
}_Vertex;

typedef _Vertex *Vertex;

Vertex newVertex(Airport airport);

void newVertexes(Vertex vertexes[23]);

int *selectVertices(Vertex vertexes[MAX_VERTEXES], char v1[4], char v2[4]);

#endif //AIRPORT_GRAPHS_SIMULATOR_VERTEX_H
