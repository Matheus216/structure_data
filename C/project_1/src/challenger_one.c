#include <stdio.h>
#include <stdlib.h>
#include "../include/stack.h"
#include "../include/challenger_one.h"


typedef struct {
    Stack* q1;
    Stack* q2;
} Temp;

void EnqueueStack(Temp* queue, int value) {
    if (queue == NULL) {
        printf("Error");
        exit(1);
    }
    Push(queue->q1, value); 
}

int DequeueStack(Temp* queue) {
    if (IsEmptyStack(queue->q2)) {
        while(!IsEmptyStack(queue->q1)) {
            Push(queue->q2, Pop(queue->q1));
        }
    }

    return Pop(queue->q2);
}

void QueueWithStack() {

    printf("Start Challenger \n");

    Temp* queue = malloc(sizeof(Temp));
    queue->q1 = CreateStack(1);
    queue->q2 = CreateStack(1);

    EnqueueStack(queue, 1);
    EnqueueStack(queue, 2);
    EnqueueStack(queue, 3);
    EnqueueStack(queue, 4);
    EnqueueStack(queue, 5);
    EnqueueStack(queue, 6);

    DequeueStack(queue);
    DequeueStack(queue);
    DequeueStack(queue);
    DequeueStack(queue);
    DequeueStack(queue);
    DequeueStack(queue);

    return;
}