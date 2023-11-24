#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <malloc.h>
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