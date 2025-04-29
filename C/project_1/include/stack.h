#include <stdbool.h>

#ifndef STACK_H
#define STACK_H 

typedef struct NodeStack {
    void* data; 
    struct NodeStack* next; 
} NodeStack;


typedef struct {
    NodeStack* top;
    int size;
} Stack; 

Stack* CreateStack(int capacity);
void Push(Stack* stack, void* value);
NodeStack* Pop(Stack* stack);
NodeStack* Peek(Stack* stack);
bool IsEmptyStack(Stack* stack);

#endif