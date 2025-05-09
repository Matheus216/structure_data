#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct binarytree {
    int value;
    short height; 
    struct binarytree* right, *left;
} binarytree;


binarytree* createBinaryTree(int input); 
void print_binarytree(binarytree* tree, short level); 
void print_postorder_transversal(binarytree* tree, short level);
void print_preorder_transversal(binarytree* tree, short level);
void print_inorder_transversal(binarytree* tree, short level);
void print_tree(binarytree *tree, int level);
binarytree* insert_left(binarytree* root, int input);
binarytree* insert_right(binarytree* root, int input);
binarytree* rotationLeft(binarytree* tree);
binarytree* rotationRight(binarytree* tree);
binarytree* rotationLeftRight(binarytree *tree);
binarytree* rotationRightLeft(binarytree *tree);
binarytree* insert_binary_balanced(binarytree* root, int input);
binarytree* delete_binary_balanced(binarytree *root, int input);
void insert_without_return(binarytree **root, int input);
void insertWithoutRecursion(binarytree **root, int input);
binarytree* searchRecursive(binarytree *root, int search);
binarytree* search(binarytree *root, int search);
#endif 
