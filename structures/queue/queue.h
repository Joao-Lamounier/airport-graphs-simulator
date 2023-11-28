#include <stdbool.h>

#ifndef AIRPORT_GRAPHS_SIMULATOR_FIFO_H

typedef struct _QueueNode {
    int data;
    struct _QueueNode *next;
} QueueNode;

// Estrutura de fila
typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

/**
 * Cria uma nova fila.
 *
 * @return Ponteiro para a nova fila alocada dinamicamente.
 */
Queue *createQueue();

/**
 * Adiciona um elemento à fila.
 *
 * @param queue Fila à qual o elemento será adicionado.
 * @param data Dado a ser enfileirado.
 */
void enqueue(Queue *queue, int data);

/**
 * Remove e retorna o elemento do início da fila.
 *
 * @param queue Fila da qual o elemento será removido.
 * @return Dado removido da fila.
 */
int dequeue(Queue *queue);

/**
 * Verifica se a fila está vazia.
 *
 * @param queue Fila a ser verificada.
 * @return true se a fila estiver vazia, false caso contrário.
 */
bool isEmpty(Queue *queue);

#define AIRPORT_GRAPHS_SIMULATOR_FIFO_H
#endif //AIRPORT_GRAPHS_SIMULATOR_FIFO_H
