#ifndef AIRPORT_GRAPHS_SIMULATOR_ARRAYLIST_H
#define AIRPORT_GRAPHS_SIMULATOR_ARRAYLIST_H

#include "../../entities/flights/Flight.h"
#include "../vertex/Vertex.h"

typedef struct _ArrayList {
    int size;
    Flight *flights;
} _ArrayList;
typedef _ArrayList *ArrayList;

/**
 * Cria uma nova lista dinâmica de voos.
 *
 * @return Nova lista dinâmica de voos alocada dinamicamente.
 */
ArrayList newArrayList();

/**
 * Adiciona um voo à lista dinâmica de voos.
 *
 * @param list Lista dinâmica de voos.
 * @param flight Voo a ser adicionado.
 */
void append(ArrayList list, Flight flight);

/**
 * Inicializa e preenche um array de listas dinâmicas de voos com base em um array de vértices e um array de voos.
 *
 * @param lists Array de listas dinâmicas de voos.
 * @param vertexes Array de vértices.
 */
void newArrayLists(ArrayList lists[MAX_AIRPORTS], Vertex vertexes[MAX_VERTEXES]);

#endif //AIRPORT_GRAPHS_SIMULATOR_ARRAYLIST_H
