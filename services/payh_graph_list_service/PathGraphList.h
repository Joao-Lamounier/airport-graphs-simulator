#include "../../structures/graph_list/GraphList.h"
#include "../../structures/graph_matrix/GraphMatrix.h"

#ifndef AIRPORT_GRAPHS_SIMULATOR_PATHGRAPHLIST_H
#define AIRPORT_GRAPHS_SIMULATOR_PATHGRAPHLIST_H

/**
 * Obtém e imprime voos diretos de um determinado aeroporto em um grafo de voos.
 *
 * @param graph Grafo de voos.
 */
void getDirectFlights(GraphFlights graph);

/**
 * Encontra e imprime o voo com o menor tempo de viagem entre dois aeroportos em um grafo de voos.
 *
 * @param graphFlights Grafo de voos.
 * @param codOrigin Código do aeroporto de origem.
 * @param codTarget Código do aeroporto de destino.
 */
void shortestPathTime(GraphFlights graphFlights, char *codOrigin, char *codTarget);

#endif //AIRPORT_GRAPHS_SIMULATOR_PATHGRAPHLIST_H
