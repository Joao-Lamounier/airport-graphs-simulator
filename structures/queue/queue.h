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

Queue *createQueue();

void enqueue(Queue *queue, int data);

int dequeue(Queue *queue);

bool isEmpty(Queue *queue);

#define AIRPORT_GRAPHS_SIMULATOR_FIFO_H
#endif //AIRPORT_GRAPHS_SIMULATOR_FIFO_H
