#include "../include/CircularList.h"
#include <stdio.h>
#include <stdlib.h>



void Init(CircularList* list) {

    list->data = NULL;

    Node* nill = malloc(sizeof(Node)); 

    nill->next = list->data;
    nill->previous = list->data;
    nill->val = 0; 

    list->data->next = nill;
    list->data->previous = nill; 
}

void Include(CircularList* list, int value){
    if (list == NULL) {
        printf("Lista inválida \n");
        return;
    }

    Node* newNode = malloc(sizeof(Node));

    newNode->val = value;

    if (list->data == NULL) {
        list->data = newNode; 
        newNode->next = newNode;
        return; 
    }

    Node* temp = list->data;

    while (temp->next != list->data)
    {
        temp = temp->next; 
    }

    newNode->next = list->data; 
    temp->next = newNode; 
}

void Remove(CircularList* list, int value) {
    if (list == NULL) {
        printf("Lista vazia \n");
        return;
    }

    Node* current = list->data,*prev = NULL;

    do {
        if (current->val == value) {
            if (prev == NULL) {
                if (current->next == current) {
                    list->data = NULL;
                }
                else {
                    Node* temp = list->data; 
                    while (temp->next != list->data) 
                        temp = temp->next;
                    
                    temp->next = current->next; 
                    list->data = current->next; 
                }
            }
            else {
                prev->next = current->next; 
            }
            printf("Removido: %d", current->val);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    } while (current->next != list->data);
}

Node* Search(CircularList* head, int search) {
    if (head == NULL) {
        printf("Lista inválida \n");
        return NULL;
    }

    Node* current = head->data;

    while (current->next != head->data) {
        if (current->val == search){
            return current; 
        }
        current = current->next; 
    }

    printf("Não encontrado valor procurado.\n\n\n");
    return NULL;
}

void PrintCircularList(CircularList* head) {
    if (head == NULL) {
        printf("Lista inválida \n");
        return;
    }

    Node* current = head->data; 

    while (current->next != head->data) {
        printf("Item: %d \n", current->val);
        current = current->next; 
    }
}
