#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct binarytree {
    int value;
    short height; 
    struct binarytree* right;
    struct binarytree* left; 
} binarytree;


binarytree* createBinaryTree(int input); 
void print_binarytree(binarytree* tree, int level); 
binarytree* insert_left(binarytree* root, int input);
binarytree* insert_right(binarytree* root, int input);
binarytree* rotationLeft(binarytree* tree);
binarytree* rotationRight(binarytree* tree);
binarytree* rotationLeftRight(binarytree *tree);
binarytree* rotationRightLeft(binarytree *tree);
#endif 