#include <stdio.h>
#include <stdlib.h>

#include "../include/binarytree.h"

binarytree* createBinaryTree(int input) {
    binarytree* tree = malloc(sizeof(binarytree));
    if (tree != NULL) {
        tree->left = NULL;
        tree->right = NULL;
        tree->value = input; 
    }
    return tree;
}

void printtab(int quantity) {
    for (int i = 0; i < quantity; i++)
    {
        printf("-"); 
    }
}

void print_binarytree(binarytree* tree, int level) {
    if (tree == NULL) {
        printf("--<empty>--\n\n");
        return;
    }
    printtab(level);
    printf("value: %d \n\n", tree->value); 
    
    printf("left \n");
    print_binarytree(tree->left, level+1); 

    printf("right \n");
    print_binarytree(tree->right, level+1);
}

