#include <stdio.h>

#ifndef HUFFMAN_H
#define HUFFMAN_H

typedef struct Node {
    unsigned char caracter;
    int frequency; 
    struct Node *left, *right, *next;
} Node; 

typedef struct ListNode {
    Node *root; 
    int tam;
} ListNode;

void hoffman();

#endif

