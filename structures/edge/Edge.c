#include <malloc.h>
#include <math.h>
#include "Edge.h"

double calculateDistance(int x1, int x2, int y1, int y2);

Edge newEdge(Vertex v1, Vertex v2) {
    Edge edge = (Edge) malloc(sizeof(_Edge));
    if (v1 && v2 != NULL) {
        int x1 = v1->airport->latitude;
        int y1 = v1->airport->longitude;
        int x2 = v2->airport->latitude;
        int y2 = v2->airport->longitude;
        edge->distance = calculateDistance(x1, x2, y1, y2);
    } else edge->distance = -1;
    return edge;
}

double calculateDistance(int x1, int x2, int y1, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}