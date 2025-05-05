#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct binarytree {
    int value;
    struct binarytree* right;
    struct binarytree* left; 
} binarytree;


binarytree* createBinaryTree(int input); 
void print_binarytree(binarytree* tree, int level); 

#endif 