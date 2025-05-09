#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../include/stack.h"


Stack* CreateStack(int size) {
    Stack* stack = malloc(sizeof(Stack)); 
    stack->size = size; 
    stack->top = NULL; 
    return stack;
}

void Push(Stack* stack, int element) {
    NodeStack *node = malloc(sizeof(NodeStack));

    node->data = element; 

    if (stack->top == NULL) 
        node->next = node;
    else
        node->next = stack->top;

    stack->top = node;

    printf("Allocated: %d \n", element);
}

int Peek(Stack* stack) {
    if (stack == NULL || stack->size == 0 ) {
        printf("Vazia"); 
        return -1;
    }
    
    NodeStack*  last = stack->top;
    printf("Peek: %d \n", last->data);
    return last->data;
}

int Pop(Stack* stack) {
    if (stack == NULL || stack->size == 0 ) {
        printf("Vazia"); 
        return -1;
    }

    NodeStack* result = stack->top; 
    printf("Pop: %d \n", result->data);

    if (stack->size == 1) {
        stack->top = NULL; 
        return result->data;
    }
    else {
        NodeStack* temp = stack->top->next;

        while (temp != result) {
            temp = temp->next; 
        }

        temp->next = result->next;
        stack->size--;
        return result->data;
    }
}

bool IsEmptyStack(Stack* stack) {
    if (stack == NULL || stack->size == 0)
    {
        return true;
    }
    return false;
}