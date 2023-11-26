#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "files/ReadFile.h"
#include "entities/airports/Airport.h"
#include "entities/routes/Route.h"
#include "entities/flights/Flight.h"
#include "structures/vertex/Vertex.h"
#include "structures/graph_matrix/GraphMatrix.h"
#include "structures/array_list/ArrayList.h"
#include "structures/graph_list/GraphList.h"
#include "utils/utils.h"
#include "services/path_graph_matrix_service/PathGraphsMatrix.h"
#include "services/payh_graph_list_service/PathGraphList.h"
#include "services/airports_service/AirportsServices.h"

bool mainMenu(GraphRoutes graphRoutes, GraphFlights graphFlights, bool *initial);
void designateOp(GraphRoutes graphRoutes, GraphFlights graphFlights, int op);
int main() {
    Vertex vertexes[MAX_VERTEXES];
    newVertexes(vertexes);

    GraphRoutes graphRoutes = newGraphRoutes(vertexes);
    GraphFlights graphFlights = newGraphFlights(vertexes);
    bool initial = true;

    while (mainMenu(graphRoutes, graphFlights, &initial));

    return 0;
}

bool mainMenu(GraphRoutes graphRoutes, GraphFlights graphFlights, bool *initial) {
if(*initial){
    color(5);
    printf("╔══════════════════════════════════════════════════════════════════════╗\n");
    printf("║");
    color(7);
    printf("                             Bem-vindo ao                             ");
    color(5);
    printf("║\n║");
    color(7);
    printf("                               AeroGraph                              ");
    color(5);
    printf("║\n");
    color(5);
    printf("║");
    color(8);
    printf("               Controle Inteligente de Voos e Rotas Aéreas            ");
    color(5);
    printf("║\n");
    printf("╚══════════════════════════════════════════════════════════════════════╝");
    color(7);
    (*initial) = false;
}
    int op;
    printf("\n");
    printf("\nSelecione uma opção: ");
    printf("\n1. Mostrar caminho entre 2 aeroportos");
    printf("\n2. Pesquisar voos diretos");
    printf("\n3. Viagem com menor custo (tempo e distância)");
    printf("\n4. Verificar se possível atingir todos os outros");
    printf("\n5. Verificar circuito Hamiltoniano");
    printf("\n6. Sair");
    printf("\n-> ");
    scanf("%d", &op);
    if (op == 6) return false;
    designateOp(graphRoutes, graphFlights, op);
    return true;

}

void designateOp(GraphRoutes graphRoutes, GraphFlights graphFlights, int op) {
    switch (op) {
        case 1:
            pathInGraph(graphRoutes);
            break;
        case 2:
            getDirectFlights(graphFlights);
            break;
        case 3: {
            char codOrigin[4], codTarget[4];
            getCodeFromUser("origem", codOrigin);
            getCodeFromUser("destino", codTarget);
            shortestWay(graphRoutes, codOrigin, codTarget);
            shortestPathTime(graphFlights, codOrigin, codTarget);
            break;;
        }
        case 4:
            accessToAll(graphRoutes, false);
            break;
        case 5:
            accessToAll(graphRoutes, true);
            break;
        default:
            printf("\nOpção inválida");
    }
}
