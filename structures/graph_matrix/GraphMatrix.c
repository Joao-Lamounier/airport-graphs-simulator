#include <malloc.h>
#include "GraphMatrix.h"
#include "../../entities/routes/Route.h"

void setDefaultEdges(GraphRoutes graphRoutes);

GraphRoutes newGraphRoutes(Vertex vertexes[23]) {
    GraphRoutes graph = (_Graph *) malloc(sizeof(_Graph));

    Route routes[MAX_ROUTES];
    newRoutes(routes);


    for (int i = 0; i < MAX_VERTEXES; ++i) {
        graph->vertexes[i] = vertexes[i];
    }

    int *position;
    for (int i = 0; i < MAX_ROUTES; ++i) {
        position = selectVertices(vertexes, routes[i]->source, routes[i]->target);
        graph->distances[position[0]][position[1]] = newEdge(vertexes[position[0]], vertexes[position[1]]);
        graph->distances[position[1]][position[0]] = newEdge(vertexes[position[0]], vertexes[position[1]]);
    }
    setDefaultEdges(graph);

    graph->toString = printRoutes;

    return graph;
}

void setDefaultEdges(GraphRoutes graphRoutes) {
    for (int i = 0; i < MAX_VERTEXES; ++i) {
        for (int j = 0; j < MAX_VERTEXES; ++j) {
            if (graphRoutes->distances[i][j] == NULL) {
                graphRoutes->distances[i][j] = newEdge(NULL, NULL);
                graphRoutes->distances[j][i] = newEdge(NULL, NULL);
            }
        }
    }
}

void printRoutes(GraphRoutes graph) {

    for (int i = 0; i < MAX_VERTEXES; ++i) {
        for (int j = i + 1; j < MAX_VERTEXES; ++j) {
            if (graph->distances[i][j]->distance != -1) {
                printf("\n🛫 Aeroporto: %s", graph->vertexes[i]->airport->code);
                printf("\n🛬 Aeroporto: %s", graph->vertexes[j]->airport->code);
                printf("\n🛣️ Distância: %.2f ", graph->distances[i][j]->distance);
                printf("\n");
            }
        }
    }
}



