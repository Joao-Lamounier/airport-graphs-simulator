#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue *createQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    if (!queue) {
        perror("Falha ao criar a fila");
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Função para enfileirar um elemento
void enqueue(Queue *queue, int data) {
    QueueNode *newNode = (QueueNode *) malloc(sizeof(QueueNode));
    if (!newNode) {
        perror("Falha ao enfileirar elemento");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Função para desenfileirar um elemento
int dequeue(Queue *queue) {
    if (queue->front == NULL) {
        fprintf(stderr, "Fila vazia\n");
        exit(EXIT_FAILURE);
    }

    QueueNode *temp = queue->front;
    int data = temp->data;

    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    return data;
}

// Função para verificar se a fila está vazia
bool isEmpty(Queue *queue) {
    return queue->front == NULL;
}

