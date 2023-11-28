#ifndef AIRPORT_GRAPHS_SIMULATOR_MENU_H
#define AIRPORT_GRAPHS_SIMULATOR_MENU_H

#include <stdbool.h>
#include "../structures/graph_matrix/GraphMatrix.h"
#include "../structures/graph_list/GraphList.h"

/**
 * Função para exibir o menu principal.
 *
 * @param graphRoutes Grafo de rotas.
 * @param graphFlights Grafo de voos.
 * @param initial Flag indicando se é a primeira execução.
 * @return true se o programa deve continuar a execução, false se deve encerrar.
 */
bool mainMenu(GraphRoutes graphRoutes, GraphFlights graphFlights, bool *initial);

/**
 * Designa a operação a ser realizada com base na opção escolhida pelo usuário.
 *
 * @param graphRoutes Grafo de rotas.
 * @param graphFlights Grafo de voos.
 * @param op Opção escolhida pelo usuário.
 */
void designateOp(GraphRoutes graphRoutes, GraphFlights graphFlights, int op);
#endif //AIRPORT_GRAPHS_SIMULATOR_MENU_H
