#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right; 
} Node;


Node* CreateNode(int value) {
    Node* node = malloc(sizeof(Node));
    node->value = value; 
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* InsertTree(Node* tree, int value) {
    if (tree == NULL) {
        return CreateNode(value);
    }

    if (value < tree->value)
        tree->left = InsertTree(tree->left, value);
    else 
        tree->right = InsertTree(tree ->right, value); 

    return tree;
}

void PrintTree(Node* tree) {
    if (tree == NULL) return;

    PrintTree(tree->left);
    printf("value: %d \n", tree->value);
    PrintTree(tree->right);
}


typedef struct QueueNode {
    int value; 
    struct QueueNode* next; 
} QueueNode; 

typedef struct {
    QueueNode* front; 
    QueueNode* rear;
} Queue;


Queue* CreateQueue() {
    Queue* newQueue = malloc(sizeof(Queue));
    newQueue->front = newQueue->rear = NULL; 

    return newQueue;
}

void Enqueue(Queue* q, int input) {
    QueueNode* newQueue = malloc(sizeof(QueueNode));
    newQueue->value = input;
    newQueue->next = NULL;

    if (q->rear == NULL) {
         q->front = q->rear = newQueue;
    } 
    else {
        q->rear->next = newQueue;
        q->rear = newQueue;
    }

    printf("Enfileirado: %d \n", input); 
}

int Desenqueue(Queue* q) {
    if (q->front == NULL) {
        printf("List vazia \n");
        return -1; 
    }
    
    QueueNode* temp = q->front; 
    int result = temp->value;
    
    q->front = q->front->next; 

    if (q->front == NULL)
        q->rear = NULL; 
    
    free(temp);

    printf("desenfileirado: %d\n", result); 

    return result;
}

typedef struct Stack {
    int val; 
    struct Stack* next;
} Stack;

Stack* CreateStack(int val) {
    Stack* stack = malloc(sizeof(Stack)); 
    if (stack == NULL)
        return NULL; 
    
    stack->val = val;
    stack->next = NULL;
    return stack; 
}

void Push(Stack** stack, int input) {
    Stack* currence = *stack;

    if (currence == NULL) {
        *stack = CreateStack(input);
        printf("Include in the stack %d \n", input);
        return;
    }

    while (currence->next != NULL){
        currence = currence->next; 
    }

    currence->next = CreateStack(input);
    printf("Include in the stack %d \n", input);
}

int Pop(Stack** stack) {
    Stack* prev = NULL;
    Stack* currence = *stack;

    if (currence == NULL) {
        printf("Pilha está vazia");
        return -1;
    }

    int result = currence->val; 

    if (currence->next == NULL) {
        printf("remove in the stack %d \n", result);
        *stack = NULL;
        free(currence);
        return result;
    }
    
    while (currence->next != NULL) {
        prev = currence;
        currence = currence->next; 
    }

    result = currence->val; 
    
    prev->next = NULL;

    free(currence);

    printf("remove in the stack %d \n", result);


    return result;
}

int Peek(Stack* stack) {
    Stack* currence = stack; 

    if (currence == NULL) {
        printf("A pilha está vazia");
        return -1; 
    }

    while (currence->next != NULL) {
        currence = currence->next; 
    }

    return currence->val;
}


int main() {
 
    printf("initializer project..\n\n");

    Stack* stack = NULL;

    Push(&stack, 1); 
    Push(&stack, 2); 
    Push(&stack, 3); 
    Push(&stack, 4); 
    Push(&stack, 5); 
    Push(&stack, 6); 
    Push(&stack, 7);
 

    while (stack != NULL) {
        Peek(stack);
        Pop(&stack);
    }
   
    return 0; 
}


