#include <stdbool.h>
#include <stdio.h>
#include <float.h>
#include <limits.h>
#include "PathGraphList.h"
#include "../../structures/graph_list/GraphList.h"
#include "../airports_service/AirportsServices.h"
#include "../../structures/graph_matrix/GraphMatrix.h"

void getDirectFlights(GraphFlights graph) {
    char code[4];
    getCodeFromUser("Origem", code);
    int position = designatePosition(graph->vertexes, code);

    bool directed = false;

    for (int i = 0; i < graph->lists[position]->size; ++i) {
        if (graph->lists[position]->flights[i]->stops == 0) {
            if (!directed) {
                printf("\n✈️ Voos Diretos de %s", code);
            }
            directed = true;
            printf("\n");
            graph->lists[position]->flights[i]->toString(graph->lists[position]->flights[i]);
        }
    }

    if (!directed) {
        printf("\n😔 Não há voos diretos partindo de: %s", code);
    }
}

void initialize(GraphRoutes graph, double distances[], int predecessors[]) {
    for (int i = 0; i < MAX_VERTEXES; i++) {
        distances[i] = DBL_MAX;
        predecessors[i] = -1;
    }
}

double extractMin(const double distances[], const bool visited[], int n) {
    double min = DBL_MAX, min_index;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && distances[v] < min) {
            min = distances[v];
            min_index = v;
        }
    }

    return min_index;
}

void relax(GraphRoutes graph, int u, int v, double distances[], int predecessors[]) {
    if (distances[v] > distances[u] + graph->distances[u][v]->distance) {
        distances[v] = distances[u] + graph->distances[u][v]->distance;
        predecessors[v] = u;
    }
}

void dijkstra(GraphRoutes graph) {
    double distances[MAX_VERTEXES];
    int predecessors[MAX_VERTEXES];
    bool visited[MAX_VERTEXES];

    int n = MAX_VERTEXES;

    char codOrigin[4], codTarget[4];
    getCodeFromUser("origem", codOrigin);
    getCodeFromUser("destino", codTarget);

    int origin = designatePosition(graph->vertexes, codOrigin);
    int target = designatePosition(graph->vertexes, codTarget);

    initialize(graph, distances, predecessors);

    distances[origin] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = (int) extractMin(distances, visited, n);

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph->distances[u][v]->distance != -1) {
                relax(graph, u, v, distances, predecessors);
            }
        }
    }

    printf("✈️ Menor caminho de %s para %s: %.2f\n", codOrigin, codTarget, distances[target]);

    printf("Caminho: ");
    int current = target;
    bool first = true;
    int next = 0;
    while (current != -1) {
        int copy = predecessors[current];
        if (first) {
            printf("🛫");
            first = false;
        } else if (copy == -1) {
            printf(" 🛬");
        } else if (current != target) {
            printf(" ➡️ ");
        }
        printf("%s ", graph->vertexes[current]->airport->code);
        current = predecessors[current];
    }

}