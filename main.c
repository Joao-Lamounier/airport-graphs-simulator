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

void mainMenu(int op);

int main() {
    Vertex vertexes[MAX_VERTEXES];
    newVertexes(vertexes);

    GraphRoutes graphRoutes = newGraphRoutes(vertexes);
    GraphFlights graphFlights = newGraphFlights(vertexes);
//
//    graphRoutes->toString(graphRoutes);
//   graphFlights->toString(graphFlights);
//5.1
//    pathInGraph(graphRoutes);
//5.2
//    getDirectFlights(graphFlights);
//5.3
//    char codOrigin[4], codTarget[4];
//    getCodeFromUser("origem", codOrigin);
//    getCodeFromUser("destino", codTarget);
//    shortestWay(graphRoutes, codOrigin, codTarget);
//    shortestPathTime(graphFlights, codOrigin, codTarget);
//5.4

    return 0;
}

void mainMenu(int op) {

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

}
