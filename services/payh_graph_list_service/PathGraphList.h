#include "../../structures/graph_list/GraphList.h"
#include "../../structures/graph_matrix/GraphMatrix.h"

#ifndef AIRPORT_GRAPHS_SIMULATOR_PATHGRAPHLIST_H
#define AIRPORT_GRAPHS_SIMULATOR_PATHGRAPHLIST_H
void getDirectFlights(GraphFlights graph);
void shortestPathTime(GraphFlights graphFlights, char *codOrigin, char *codTarget);
#endif //AIRPORT_GRAPHS_SIMULATOR_PATHGRAPHLIST_H
