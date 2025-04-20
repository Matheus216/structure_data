#include <stdio.h>
#include <stdlib.h>
#include "../include/queue.h"


Queue* CreateQueue(int quantity) {
    Queue* queue = malloc(sizeof(Queue)); 
    queue->capacity = quantity; 
    queue->size = 0;
    queue->data = malloc(sizeof(int) * quantity);
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

void Enqueue(Queue* queue, int value) {
    if (queue == NULL) {
        printf("Invalid List \n");
        exit(1);
    }

    if (queue->size == queue->capacity) {
        int newSize = queue->size + 1; 
        queue->capacity = queue->capacity * 2 + 1; 
        int* newData = malloc(sizeof(int) * queue->capacity);

        for (int i = 0; i < queue->size; i++)
        {
            newData[i % queue->capacity] = queue->data[i];
        }
        
        free(queue->data); 
        queue->data = newData; 
        queue->front = 0;
        queue->rear = queue->size;
    }

    queue->data[queue->rear] = value; 
    queue->rear = queue->rear + 1 % queue->capacity;
    queue->size++; 
}

void Dequeue(Queue* queue) {
    if (queue == NULL || queue->size == 0) {
        printf("Fila inválida. \n");
        return; 
    }

    int result = queue->data[queue->front];
    queue->front =  queue->front+1 % queue->capacity;

    queue->size--;

    printf("dequeue item: %d\n ", result);
}