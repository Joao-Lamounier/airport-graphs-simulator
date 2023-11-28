#ifndef AIRPORT_GRAPHS_SIMULATOR_GRAPHLIST_H
#define AIRPORT_GRAPHS_SIMULATOR_GRAPHLIST_H

#include "../array_list/ArrayList.h"

typedef struct _GraphList{
    ArrayList lists[MAX_AIRPORTS];
    Vertex vertexes[MAX_VERTEXES];
    void (*toString)(struct _GraphList*);
}_GraphList;

typedef _GraphList *GraphFlights;

/**
 * Cria um novo grafo de voos com base em um array de vértices.
 *
 * @param vertexes Array de vértices associados aos aeroportos.
 * @return Novo grafo de voos alocado dinamicamente.
 */
GraphFlights newGraphFlights(Vertex vertexes[MAX_VERTEXES]);


#endif //AIRPORT_GRAPHS_SIMULATOR_GRAPHLIST_H
