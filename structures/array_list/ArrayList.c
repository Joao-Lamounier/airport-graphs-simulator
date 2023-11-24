#include <malloc.h>
#include "ArrayList.h"
#include "../../entities/airports/Airport.h"
#include "../vertex/Vertex.h"

ArrayList newArrayList() {
    ArrayList list = (ArrayList) malloc(sizeof(_ArrayList));
    list->size = 0;
    list->flights = NULL;

    return list;
}

void append(ArrayList list, Flight flight) {
    list->flights = (Flight *) realloc(list->flights, (list->size + 1) * sizeof(_Flight));
    list->flights[list->size] = flight;
    list->size++;

}

void newArrayLists(ArrayList lists[MAX_AIRPORTS], Vertex vertexes[MAX_VERTEXES]) {
    Flight flights[MAX_FLIGHTS];
    newFlights(flights);


    for (int i = 0; i < MAX_AIRPORTS; ++i) {
        lists[i] = newArrayList();
    }

    for (int i = 0; i < MAX_FLIGHTS; ++i) {
        int pos = designatePosition(vertexes, flights[i]->source);
        append(lists[pos], flights[i]);
    }
}
