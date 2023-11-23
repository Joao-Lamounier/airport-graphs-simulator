#include <malloc.h>
#include <string.h>
#include "Vertex.h"

Vertex newVertex(Airport airport) {
    Vertex vertex = (Vertex) malloc(sizeof(_Vertex));
    vertex->airport = airport;
    return vertex;
}

void newVertexes(Vertex vertexes[MAX_VERTEXES]) {
    Airport airports[MAX_VERTEXES];
    newAirports(airports);

    for (int i = 0; i < MAX_VERTEXES; ++i) {
        vertexes[i] = newVertex(airports[i]);
    }
}

int *selectVertices(Vertex vertexes[MAX_VERTEXES], char v1[4], char v2[4]) {
    int *position = (int *) malloc(2 * sizeof(int));

    for (int i = 0; i < MAX_VERTEXES; ++i) {
        if (strcmp(vertexes[i]->airport->code, v1) == 0) {
            position[0] = i;
        } else if (strcmp(vertexes[i]->airport->code, v2) == 0) {
            position[1] = i;
        }
    }

    return position;
}

int designatePosition(Vertex vertexes[MAX_VERTEXES], char cod[4]) {
    int position = -1;
    for (int i = 0; i < MAX_VERTEXES; ++i) {
        if (strcmp(vertexes[i]->airport->code, cod) == 0) {
            position = i;
        }
    }
    return position;
}