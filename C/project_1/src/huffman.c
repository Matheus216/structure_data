#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "../include/huffman.h"

#define TAM 256

void initializerTable(unsigned int frequencyTable[]) {
    for(int i = 0;i<TAM;i++)
        frequencyTable[i] = 0;
}

void fillFrequencyTable(unsigned int frequencyTable[], unsigned char inputText[]) {
    int index = 0; 
    while (inputText[index] != '\0'){
        frequencyTable[inputText[index]]++; 
        index++; 
    }
}

void printFrequencyTable(unsigned int frequencyTable[]) {
    for (int i =0; i<TAM;i++) 
        if (frequencyTable[i] > 0)
            printf("Valor: %d no indice: %d char: %c \n", frequencyTable[i], i, i);
}

void createListNode(ListNode *list) {
    list->root = NULL;
    list->tam = 0;
}

void insertListNode(Node *item, ListNode *list) {
    if (list->root) {
        if (item->frequency < list->root->frequency) {
            item->next = list->root;
            list->root = item; 
            list->tam++;
            return;
        }
        Node *aux = list->root;
        while (aux->next && aux->next->frequency <= item->frequency)
            aux = aux->next;
        item->next = aux->next;
        aux->next = item; 
        list->tam++;
        return;
    }
    list->root = item;
    list->tam++;
}

void fillListNode(unsigned int frequencyTable[], ListNode *list) {
    for (int i = 0; i< TAM; i++) {
        if (frequencyTable[i] > 0) {
            Node *node = malloc(sizeof(Node));
            if (!node) {
                printf("um problema ocorreu ao alocar memória. \n");
                return;
            }
            node->caracter = i;
            node->frequency = frequencyTable[i];
            node->next = NULL;
            node->left = NULL;
            node->right = NULL;
            insertListNode(node, list);
        }
    }
}

void printListNode(ListNode *list) {
    Node *aux =  list->root;
    printf("\nLista ordenada tamanho: %d\n", list->tam);
    for (int i = 0; i<list->tam;i++){
        printf("%d caracter: %c Frequencia: %d\n", i, aux->caracter, aux->frequency);
        aux = aux->next;
    }
}

// -- montar arvore de huffman
Node* removeItemList(ListNode *list) {
    Node* aux;
    if (list->root) {
        aux = list->root;
        list->root = aux->next;
        aux->next = NULL;
        list->tam--;
    }
    return aux;
}

Node* createHoffmanTree(ListNode *list) {
    if (list->root) {
            Node *first, *second, *response; 
            while (list->tam > 1) {

                first = removeItemList(list);
                second = removeItemList(list);

                response = malloc(sizeof(Node));
                response->frequency = first->frequency + second->frequency;
                response->caracter = '+';
                response->left = first;
                response->right = second;
                insertListNode(response, list);
            }
    }
    return list->root;
}

void printHoffmanTree(Node *node, int level) {
    if (node) {
        printHoffmanTree(node->left, level+1); 
        if(!node->left && !node->right)
            printf("\nFrequency: %d Caracter: %c", node->frequency, node->caracter);
        printHoffmanTree(node->right, level + 1);    
    }
} 

void compact() {
    unsigned char textToCompact[] = "Let's learn program"; 
    unsigned int frequencyTable[TAM]; 
    
    setlocale(LC_ALL, "Portuguese");

    ListNode root;

    initializerTable(frequencyTable);
    fillFrequencyTable(frequencyTable, textToCompact);
    printFrequencyTable(frequencyTable);
    createListNode(&root);
    fillListNode(frequencyTable, &root);
    printListNode(&root);

    Node *tree = createHoffmanTree(&root);
    printf("\n*** Arvore de Huffman ***\n");
    printHoffmanTree(tree, 0); 
}
