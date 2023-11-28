#ifndef AIRPORT_GRAPHS_SIMULATOR_PATHGRAPHSMATRIX_H
#define AIRPORT_GRAPHS_SIMULATOR_PATHGRAPHSMATRIX_H

#include <stdbool.h>
#include "../../structures/graph_matrix/GraphMatrix.h"

/**
 * Encontra e imprime o caminho em um grafo de rotas entre dois vértices especificados pelo usuário.
 *
 * @param graph Grafo de rotas.
 */
void pathInGraph(GraphRoutes graph);

/**
 * Encontra e imprime o caminho mais curto em um grafo de rotas usando o algoritmo de Dijkstra.
 *
 * @param graph Grafo de rotas.
 * @param codOrigin Código do vértice de origem.
 * @param codTarget Código do vértice de destino.
 */
void shortestWay(GraphRoutes graph, char *codOrigin, char *codTarget);

/**
 * Verifica se é possível acessar todos os vértices de um grafo de rotas a partir de um vértice de origem.
 * Realiza a análise de dependência do aeroporto se não estiver verificando a propriedade hamiltoniana.
 * Imprime o caminho percorrido.
 *
 * @param graphRoutes Grafo de rotas.
 * @param verifyHamiltoniano Flag para verificar a propriedade hamiltoniana (true para verificar, false para ignorar).
 * @return true se for possível acessar todos os vértices, false caso contrário.
 */
bool accessToAll(GraphRoutes graphRoutes, bool verifyHamiltoniano);

#endif //AIRPORT_GRAPHS_SIMULATOR_PATHGRAPHSMATRIX_H
