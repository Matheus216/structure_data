#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../include/stack.h"


Stack* CreateStack(int capacity) {
    Stack* stack = malloc(sizeof(Stack));

    stack->data = malloc(sizeof(int) * capacity);
    stack->size = 0; 
    stack->capacity = capacity;

    return stack; 
}

void Push(Stack* stack, int value) {
    if (stack == NULL) {
        printf("Inválida \n"); 
        return;
    }

    if (stack->size == stack->capacity) { 
        stack->capacity = stack->capacity * 2 + 1;
        stack->data = realloc(stack->data, sizeof(int) * stack->capacity);
        if (stack->data == NULL) {
            printf("Erro to realocate memory \n");
        } 
    }

    stack->data[stack->size] = value;
    stack->size++;

    printf("Allocated: %d \n", value);
}

int Peek(Stack* stack) {
    if (stack == NULL || stack->size == 0 ) {
        printf("Vazia"); 
        return -1; 
    }
    int last = stack->data[stack->size -1]; 
    printf("Peek: %d \n", last);
    return last;
}

int Pop(Stack* stack) {
    if (stack == NULL || stack->size == 0 ) {
        printf("Vazia"); 
        return -1; 
    }

    int result = stack->data[stack->size - 1]; 

    stack->size--;

    printf("Pop: %d \n", result);
    return result;
}

bool IsEmptyStack(Stack* stack) {
    if (stack == NULL || stack->size == 0)
    {
        return true;
    }
    return false;
}