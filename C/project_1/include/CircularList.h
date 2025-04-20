#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* data; 
} CircularList;

void Init(CircularList* head); 
void Include(CircularList* head, int value); 
Node* Search(CircularList* head, int search);
void Remove(CircularList* head, int value); 
void PrintCircularList(CircularList* head); 
int IsEmpty(CircularList* head);

#endif 
