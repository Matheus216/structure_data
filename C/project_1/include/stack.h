#include <stdbool.h>

#ifndef STACK_H
#define STACK_H 

typedef struct NodeStack {
    int data; 
    struct NodeStack* next; 
} NodeStack;


typedef struct {
    NodeStack* top;
    int size;
} Stack; 

Stack* CreateStack(int capacity);
void Push(Stack* stack, int value);
int Pop(Stack* stack);
int Peek(Stack* stack);
bool IsEmptyStack(Stack* stack);

#endif