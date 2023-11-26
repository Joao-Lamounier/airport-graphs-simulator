#ifndef AIRPORT_GRAPHS_SIMULATOR_PATHGRAPHSMATRIX_H
#define AIRPORT_GRAPHS_SIMULATOR_PATHGRAPHSMATRIX_H

#include <stdbool.h>
#include "../../structures/graph_matrix/GraphMatrix.h"

void pathInGraph(GraphRoutes graph);

void shortestWay(GraphRoutes graph, char *codOrigin, char *codTarget);

bool accessToAll(GraphRoutes graphRoutes);

#endif //AIRPORT_GRAPHS_SIMULATOR_PATHGRAPHSMATRIX_H
