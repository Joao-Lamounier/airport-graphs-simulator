#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <malloc.h>
#include <float.h>
#include "PathGraphsMatrix.h"
#include "../../structures/graph_matrix/GraphMatrix.h"
#include "../airports_service/AirportsServices.h"
#include "../../structures/vertex/Vertex.h"
#include "../../structures/queue/queue.h"

void bfs(GraphRoutes graph, int start, int end, int parent[]) {
    bool visited[MAX_VERTEXES] = {false};
    Queue *queue = createQueue();

    visited[start] = true;
    enqueue(queue, start);

    while (!isEmpty(queue)) {
        int current = dequeue(queue);

        for (int i = 0; i < MAX_VERTEXES; ++i) {
            if (!visited[i] && graph->distances[current][i]->distance > 0) {
                visited[i] = true;
                enqueue(queue, i);
                parent[i] = current;

                if (i == end) {
                    free(queue);
                    return;
                }
            }
        }
    }

    free(queue);
}

void printPath(GraphRoutes graph, int parent[], int start, int end, bool last) {
    if (parent[end] == -1 || start == end) {
        printf("🛫 %s", graph->vertexes[start]->airport->code);
        last = true;
    } else {
        printPath(graph, parent, start, parent[end], true);
        if (last) {
            printf(" ✈️ %s", graph->vertexes[end]->airport->code);
        } else {
            printf(" 🛬 %s", graph->vertexes[end]->airport->code);
        }
    }
}


void pathInGraph(GraphRoutes graph) {
    char codOrigin[4], codTarget[4];
    getCodeFromUser("origem", codOrigin);
    getCodeFromUser("destino", codTarget);

    int x, y;
    x = designatePosition(graph->vertexes, codOrigin);
    y = designatePosition(graph->vertexes, codTarget);

    if (x == -1 || y == -1) {
        printf("Vértices de origem ou destino não encontrados.\n");
        return;
    }

    int parent[MAX_VERTEXES];
    memset(parent, -1, sizeof(parent));

    bfs(graph, x, y, parent);

    printf("Caminho de %s para %s: ", codOrigin, codTarget);
    printPath(graph, parent, x, y, false);
    printf("\n");
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

void showsShortestPath(GraphRoutes graph, int origin, int target, const int predecessors[]) {
    int path[MAX_VERTEXES];
    int pathLength = 0;
    int current = target;
    while (current != -1) {
        path[pathLength++] = current;
        current = predecessors[current];
    }

    printf("Caminho: ");
    for (int i = pathLength - 1; i >= 0; i--) {
        if (i == pathLength - 1) {
            printf("🛫");
        } else if (i == 0) {
            printf("🛬");
        }
        printf("%s", graph->vertexes[path[i]]->airport->code);
        if (i > 0) {
            printf(" ➡️ ");
        }
    }
    printf("\n");
}


void dijkstra(GraphRoutes graph, char *codOrigin, char *codTarget) {
    double distances[MAX_VERTEXES];
    int predecessors[MAX_VERTEXES];
    bool visited[MAX_VERTEXES];

    int n = MAX_VERTEXES;

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

    printf("\n");
    printf("✈️ Menor caminho de %s para %s: %.2f\n", codOrigin, codTarget, distances[target]);
    showsShortestPath(graph, origin, target, predecessors);
}

void shortestWay(GraphRoutes graph, char *codOrigin, char *codTarget) {
    dijkstra(graph, codOrigin, codTarget);
}

void printPah(int path[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

void DFSWithPath(GraphRoutes graph, int start, bool *visited, int path[], int *pathLength) {
    visited[start] = true;
    path[(*pathLength)++] = start;

    for (int i = 0; i < MAX_VERTEXES; ++i) {
        if (graph->distances[start][i]->distance != -1 && !visited[i]) {
            DFSWithPath(graph, i, visited, path, pathLength);
        }
    }
}

void airportDependencyAnalyst(GraphRoutes graphRoutes, int origin) {
    int count;
    printf("\n");
            count = 0;
    for (int i = 0; i < MAX_VERTEXES; ++i) {
        for (int j = 0; j < MAX_VERTEXES; ++j) {
            if (i == origin) {
                count = 1;
                break;
            }
            if (graphRoutes->distances[i][j]->distance != -1) {
                count++;
            }
        }
        if (count == 1) {
            printf("🗝️%s", graphRoutes->vertexes[i]->airport->code);
        }
    }
}
bool isHamiltoniano(GraphRoutes graphRoutes, int origin, int target){
    return graphRoutes->distances[origin][target]->distance != -1;
}

bool accessToAll(GraphRoutes graphRoutes, bool verifyHamiltoniano) {
    char codOrigin[4];
    getCodeFromUser("origem", codOrigin);

    int position = designatePosition(graphRoutes->vertexes, codOrigin);

    if (position == -1) {
        printf("Código de origem inválido.\n");
        return false;
    }

    bool visited[MAX_VERTEXES];
    memset(visited, false, sizeof(visited));

    int path[MAX_VERTEXES];
    int pathLength = 0;

    DFSWithPath(graphRoutes, position, visited, path, &pathLength);


    for (int i = 0; i < MAX_VERTEXES; ++i) {
        if (!visited[i]) {
            return false;
        }
    }
    printf("Caminho percorrido: ");
    for (int i = 0; i < MAX_VERTEXES; ++i) {
        if (i == 0) {
            printf("🛫");
        } else if (i == MAX_VERTEXES - 1) {
            printf(" 🛬");
        } else printf(" ➡️ ");
        printf("%s", graphRoutes->vertexes[path[i]]->airport->code);
    }

    if(!verifyHamiltoniano){
        airportDependencyAnalyst(graphRoutes, position);
    }else{
        if(isHamiltoniano(graphRoutes, position, path[MAX_VERTEXES-1])){
            printf("\nÉ Hamiltoniano");
        } else{
            printf("\nNão é Hamiltoniano");

        }
    }

    return true;
}



