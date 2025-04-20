#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/MyStack.h"

MyStack* myStackCreate() {
    MyStack* stack = malloc(sizeof(MyStack));
    stack->in = CreateQueue(1);
    stack->out = CreateQueue(1);
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    if (obj->in == NULL) {
        printf("invalid object");
        exit(1);
    }

    Enqueue(obj->in, x);

    for (int i = 0; i < obj->out->size; i++) {
        Enqueue(obj->in, Dequeue(obj->out));
    }
    
    Queue* temp = obj->out;
    obj->out = obj->in;
    obj->in = temp;

    printf("Alocated: %d\n", x);
}

int myStackPop(MyStack* obj) {
    if (obj->in == NULL || obj->out == NULL) {
        printf("invalid object");
        exit(1);
    }

    int result = Dequeue(obj->out);

    printf("pop in: %d\n", result);
    return result;
}

int myStackTop(MyStack* obj) {
    int result = Print(obj->out);
    printf("top: %d \n", result);
    return result;
}

bool myStackEmpty(MyStack* obj) {
    if (obj->out == NULL || obj->out->size <=0) {
        printf("empty\n");
        return true;
    } 
    
    printf("not empty\n");
    return false; 
}

void myStackFree(MyStack* obj) {
    free(obj);
}