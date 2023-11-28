#ifndef AIRPORT_GRAPHS_SIMULATOR_EDGE_H
#define AIRPORT_GRAPHS_SIMULATOR_EDGE_H

#include "../vertex/Vertex.h"

#include <math.h>

typedef struct _Edge {
    double distance;
} _Edge;

typedef _Edge *Edge;

/**
 * Cria uma nova aresta entre dois vértices, calculando a distância entre os aeroportos associados.
 *
 * @param v1 Primeiro vértice da aresta.
 * @param v2 Segundo vértice da aresta.
 * @return Nova aresta alocada dinamicamente.
 */
Edge newEdge(Vertex v1, Vertex v2);


#endif //AIRPORT_GRAPHS_SIMULATOR_EDGE_H
