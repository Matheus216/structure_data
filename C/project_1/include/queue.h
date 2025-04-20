#ifndef QUEUE_H
#define QUEUE_H

typedef struct { 
    int* data; 
    int size;
    int capacity;
    int front;
    int rear;
} Queue;


Queue* CreateQueue(int quantity);
void Enqueue(Queue* queue, int value);
void Dequeue(Queue* queue); 
void Print(Queue* queue); 
int SearchQueue(Queue* queue, int search);

#endif 