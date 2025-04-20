#include <stdbool.h>

#ifndef STACK_H
#define STACK_H 

typedef struct {
    int* data;
    int size;
    int capacity;
} Stack; 


Stack* CreateStack(int capacity);
void Push(Stack* stack, int value);
int Pop(Stack* stack);
int Peek(Stack* stack);
bool IsEmptyStack(Stack* stack);

#endif