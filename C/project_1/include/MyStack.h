#include <stdbool.h>
#include "./queue.h"

#ifndef MYSTACK_H
#define MYSTACK_H

typedef struct {
    Queue* in; 
    Queue* out;
} MyStack;


MyStack* myStackCreate();
void myStackPush(MyStack* obj, int x);
int myStackPop(MyStack* obj);
int myStackTop(MyStack* obj);
bool myStackEmpty(MyStack* obj);
void myStackFree(MyStack* obj);

#endif