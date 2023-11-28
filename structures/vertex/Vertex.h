#ifndef AIRPORT_GRAPHS_SIMULATOR_VERTEX_H
#define AIRPORT_GRAPHS_SIMULATOR_VERTEX_H

#include "../../entities/airports/Airport.h"

#define MAX_VERTEXES 23

typedef struct _Vertex {
    Airport airport;
} _Vertex;

typedef _Vertex *Vertex;

/**
 * Cria um novo vértice associado a um aeroporto.
 *
 * @param airport Aeroporto associado ao vértice.
 * @return Novo vértice alocado dinamicamente.
 */
Vertex newVertex(Airport airport);

/**
 * Inicializa e preenche um array de vértices com base em um array de aeroportos.
 *
 * @param vertexes Array de vértices a ser inicializado e preenchido.
 */
void newVertexes(Vertex vertexes[MAX_VERTEXES]);

/**
 * Seleciona os índices de dois vértices em um array de vértices com base em seus códigos.
 *
 * @param vertexes Array de vértices.
 * @param v1 Código do primeiro vértice.
 * @param v2 Código do segundo vértice.
 * @return Array de inteiros contendo os índices dos vértices [v1, v2].
 */
int *selectVertices(Vertex vertexes[MAX_VERTEXES], char v1[4], char v2[4]);

/**
 * Designa a posição de um vértice com base no código do aeroporto em um array de vértices.
 *
 * @param vertexes Array de vértices.
 * @param cod Código do aeroporto.
 * @return Índice do vértice no array ou -1 se não for encontrado.
 */
int designatePosition(Vertex vertexes[MAX_VERTEXES], char cod[4]);

#endif //AIRPORT_GRAPHS_SIMULATOR_VERTEX_H
