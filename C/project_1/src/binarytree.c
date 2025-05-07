#include <stdio.h>
#include <stdlib.h>

#include "../include/binarytree.h"

binarytree* createBinaryTree(int input) {
    binarytree* tree = malloc(sizeof(binarytree));
    if (tree != NULL) {
        tree->left = NULL;
        tree->right = NULL;
        tree->value = input; 
        tree->height = 0;
    }
    return tree;
}

void printtab(int quantity) {
    for (int i = 0; i < quantity; i++)
    {
        printf("-"); 
    }
}

void print_inorder_transversal(binarytree* tree) {
    if (tree == NULL) return;
    print_inorder_transversal(tree->left); 
    printf("data: %d\n", tree->value);
    print_inorder_transversal(tree->right);
}

void print_preorder_transversal(binarytree* tree) {
    if (tree == NULL) return;
    printf("data: %d\n", tree->value);
    print_preorder_transversal(tree->left); 
    print_preorder_transversal(tree->right);
}

void print_postorder_transversal(binarytree* tree) {
    if (tree == NULL) return;
    print_postorder_transversal(tree->left); 
    print_postorder_transversal(tree->right);
    printf("data: %d\n", tree->value);
}

void print_binarytree(binarytree* tree, int level) {
    if (tree == NULL) {
        printf("--<empty>--\n\n");
        return;
    }
    
    print_inorder_transversal(tree);
    printf("\n-----------------<end inorder transversal>--------------\n\n");
    
    print_preorder_transversal(tree);
    printf("\n-----------------<end preorder transversal>--------------\n\n");
    
    print_postorder_transversal(tree);
    printf("\n-----------------<end postorder transversal>--------------\n\n");
}

binarytree* insert_left(binarytree* root, int input) {
    root->left = createBinaryTree(input);
    return root->left;
}

binarytree* insert_right(binarytree* root, int input) {
    root->right = createBinaryTree(input);
    return root->right;
}

short height(binarytree* tree) {
    return (tree == NULL) ? -1 : tree->height; 
}

int max(int compare, int compareTo) {
    return (compare > compareTo) ? compare : compareTo; 
}

short factorBalance(binarytree* tree) {
    return (tree == NULL) ? 0 : height(tree->left) - height(tree->right);  
}

binarytree* rotationLeft(binarytree* tree) {
    binarytree *response, *child;

    response = tree->right;
    child = response->left;

    response->left = tree; 
    tree->right = child; 

    tree->height = max(height(tree->left), height(tree->right)) + 1; 
    response->height = max(height(response->left),  height(response->right)) + 1; 
    
    return response; 
}

binarytree* rotationRight(binarytree  *tree) {
    binarytree *response, *child; 

    response = tree->left; 
    child = response->right; 
    
    printf("redirecionando elemento: %d para direta\n", tree->value);
    response->right = tree; 
    tree->left = child; 
    
    if (child != NULL)
        printf("redirecionando elemento filho: %d para a esqueda do elemento: %d\n", child->value, tree->value);

    tree->height = max(height(tree->left), height(tree->right)) + 1; 
    response->height = max(height(response->left), height(response->right)) + 1; 

    return response;
}

binarytree* rotationRightLeft(binarytree *tree) {
    tree->right = rotationRight(tree->right);
    return rotationLeft(tree);
}

binarytree* rotationLeftRight(binarytree *tree) {
    tree->left = rotationLeft(tree->left); 
    return rotationRight(tree);
}

binarytree* balance(binarytree *root) {
    short fb =  factorBalance(root);

    if (fb > 1 && factorBalance(root->left) < 0)
        return rotationLeftRight(root);

    else if (fb < -1 && factorBalance(root->right) > 0)
        return rotationRightLeft(root);
    
    else if (fb > 1 && factorBalance(root->left) >= 0) 
        return rotationRight(root); 
    
    else if (fb < -1 && factorBalance(root->right) >= 0)
        return rotationLeft(root);
    else
        return root;
}

binarytree* insert_binary_balanced(binarytree* root, int input) {
    if (root == NULL) {
        return createBinaryTree(input);
    }
    else {
        if (input < root->value) {
            root->left = insert_binary_balanced(root->left, input);
        }
        else {
            root->right = insert_binary_balanced(root->right, input);
        }
    }

    root->height = max(height(root->left), height(root->right)) + 1; 

    root = balance(root);

    return root;
}

binarytree* delete_binary(binarytree *root, int input) {
    if (root == NULL) return root; 

    if (root->value == input) {
        if (root->left != NULL  && root->right != NULL) {
            binarytree *aux = root->left; 
            
            while(aux->right != NULL)
                aux = aux->right; 
            
            root->value = aux->value; 
            root->left = delete_binary(root->left, input); 

            return root;
        }
        else {
            binarytree *aux = root->left != NULL ? root->left : root->right;
            free(root);
            return aux; 
        }

    } else {
        if (input < root->value) {
            root->left = delete_binary(root->left, input); 
        }
        else {
            root->right = delete_binary(root->right, input); 
        }
    }

    root->height = max(height(root->left), height(root->right)) + 1; 

    root = balance(root); 

    return root; 
}
