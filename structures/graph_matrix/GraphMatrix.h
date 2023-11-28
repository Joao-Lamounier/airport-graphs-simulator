#ifndef AIRPORT_GRAPHS_SIMULATOR_GRAPHMATRIX_H
#define AIRPORT_GRAPHS_SIMULATOR_GRAPHMATRIX_H

#include "../vertex/Vertex.h"
#include "../edge/Edge.h"

typedef struct _Graph {
    Vertex vertexes[MAX_VERTEXES];
    Edge distances[MAX_VERTEXES][MAX_VERTEXES];

    void (*toString)(struct _Graph *);
} _Graph;

typedef _Graph *GraphRoutes;

/**
 * Cria um novo grafo de rotas com base em um array de vértices e um array de rotas.
 *
 * @param vertexes Array de vértices associados aos aeroportos.
 * @return Novo grafo de rotas alocado dinamicamente.
 */
GraphRoutes newGraphRoutes(Vertex vertexes[23]);

#endif //AIRPORT_GRAPHS_SIMULATOR_GRAPHMATRIX_H
