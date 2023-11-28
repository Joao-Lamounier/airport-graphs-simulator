#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
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
#include "views/menu.h"8



int main() {
    Vertex vertexes[MAX_VERTEXES];
    newVertexes(vertexes);

    GraphRoutes graphRoutes = newGraphRoutes(vertexes);
    GraphFlights graphFlights = newGraphFlights(vertexes);
    bool initial = true;

    while (mainMenu(graphRoutes, graphFlights, &initial));

    return 0;
}


