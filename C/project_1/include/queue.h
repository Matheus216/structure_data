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
int Dequeue(Queue* queue); 
int Print(Queue* queue); 
int SearchQueue(Queue* queue, int search);

#endif 