#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "files/ReadFile.h"
#include "entities/airports/Airport.h"
#include "entities/routes/Route.h"
#include "entities/flights/Flight.h"
#include "structures/vertex/Vertex.h"
#include "structures/graph_matrix/GraphMatrix.h"


int main() {

    Vertex vertexes[MAX_VERTEXES];
    newVertexes(vertexes);
    GraphRoutes graphRoutes = newGraph(vertexes);
    graphRoutes->toString(graphRoutes);

//    Vertex vertexes[23];
//    newVertexes(vertexes);
//
//    for (int i = 0; i < 23; ++i) {
//        printf("\n===========================\n");
//        vertexes[i]->airport->toString(vertexes[i]->airport);
//    }

//    Route routes[34];
//    newRoutes(routes);
//    for (int i = 0; i < 34; ++i){
//        routes[i]->toString(routes[i]);
//        printf("\n");
//    }
//
//    Flight flights[723];
//    newFlights(flights);
//
//    for (int i = 0; i < 723; ++i) {
//        flights[i]->toString(flights[i]);
//        printf("\n");
//    }

    return 0;
}
