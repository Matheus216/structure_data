#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../include/binarytree.h"

binarytree* createBinaryTree(int input) {
    binarytree* tree = malloc(sizeof(binarytree));
    if (tree) {
        tree->left = NULL;
        tree->right = NULL;
        tree->value = input; 
        tree->height = 0;
    }
    return tree;
}

void printtab(short quantity) {
    for (short i = 0; i < quantity; i++)
    {
        printf("-"); 
    }
}

void print_inorder_transversal(binarytree* tree, short level) {
    if (!tree) return;
    print_inorder_transversal(tree->left, level+1); 
    printtab(level);
    printf("data: %d\n", tree->value);
    print_inorder_transversal(tree->right, level+1);
}

void print_preorder_transversal(binarytree* tree, short level) {
    if (!tree) return;
    printtab(level++);
    printf("data: %d\n level: %d\n", tree->value, level+1);
    print_preorder_transversal(tree->left, level+1); 
    print_preorder_transversal(tree->right, level+1);
}

void print_postorder_transversal(binarytree* tree, short level) {
    if (!tree) return;
    print_postorder_transversal(tree->left, level+1); 
    print_postorder_transversal(tree->right, level+1);
    printtab(level);
    printf("data: %d\n", tree->value);
}

void print_tree(binarytree *tree, int level) {
    int i;
    if (tree == NULL) return;
    print_tree(tree->right, level+1); 
    printf("\n\n");

    for (i = 0; i < level; i++)
        printf("\t");

    printf("%d", tree->value);
    print_tree(tree->left, level+1); 
}

void print_binarytree(binarytree* tree, short level) {
    if (!tree) {
        printf("--<empty>--\n\n");
        return;
    }
    
    print_inorder_transversal(tree, level);
    printf("\n-----------------<end inorder transversal>--------------\n\n");
    
    level = 1; 
    print_preorder_transversal(tree, level);
    printf("\n-----------------<end preorder transversal>--------------\n\n");
    
    level = 1;
    print_postorder_transversal(tree, level);
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

short getHeight(binarytree* tree) {
    return (tree == NULL) ? -1 : tree->height; 
}

int max(int compare, int compareTo) {
    return (compare > compareTo) ? compare : compareTo; 
}

short factorBalance(binarytree* tree) {
    return (tree == NULL) ? 0 : getHeight(tree->left) - getHeight(tree->right);  
}

binarytree* rotationLeft(binarytree* tree) {
    binarytree *response, *child;

    response = tree->right;
    child = response->left;

    response->left = tree; 
    tree->right = child; 

    tree->height = max(getHeight(tree->left), getHeight(tree->right)) + 1; 
    response->height = max(getHeight(response->left),  getHeight(response->right)) + 1; 
    
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

    tree->height = max(getHeight(tree->left), getHeight(tree->right)) + 1; 
    response->height = max(getHeight(response->left), getHeight(response->right)) + 1; 

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
        else if (input > root->value) {
            root->right = insert_binary_balanced(root->right, input);
        }
        else {
            printf("**Elemento não pode ser igual a um que já existe. e: %d\n", input);
        }
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1; 

    root = balance(root);

    return root;
}

binarytree* delete_binary_balanced(binarytree *root, int input) {
    if (!root || !root->value) return root; 

    if (root->value == input) {
        if (root->left != NULL  && root->right != NULL) {
            binarytree *aux = root->left; 
            
            while(aux->right != NULL)
                aux = aux->right; 
            
            root->value = aux->value; 
            root->left = delete_binary_balanced(root->left, input); 

            return root;
        }
        else {
            binarytree *aux = root->left != NULL ? root->left : root->right;
            free(root);
            return aux; 
        }

    } else {
        if (input < root->value) {
            root->left = delete_binary_balanced(root->left, input); 
        }
        else {
            root->right = delete_binary_balanced(root->right, input); 
        }
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1; 

    root = balance(root); 

    return root; 
}

void insert_without_return(binarytree **root, int input) {
    if (!*root) {
        *root = malloc(sizeof(binarytree));
        (*root)->value = input; // () necessário para reconhecer somente o root como ponteiro
        (*root)->left = NULL; // () necessário para reconhecer somente o root como ponteiro
        (*root)->right = NULL; // () necessário para reconhecer somente o root como ponteiro
        return;
    }
    if (input < (*root)->value)  
        insert_without_return(&((*root)->left), input); // passando o endereço de memória do elemento left
    else
        insert_without_return(&((*root)->right), input);
}

bool setValue(binarytree **aux, int input) {
    if (!*aux) {
        *aux = createBinaryTree(input);
        return true; 
    }
    return false;
}

void insertWithoutRecursion(binarytree **root, int input) {
    if (!*root) {
        *root = createBinaryTree(input);
        return;
    }
    binarytree *aux = *root; 
    do {
        if (input < aux->value) {
            if (setValue(&aux->left, input)) return;
            aux = aux->left; 
        }
        else if (input > aux->value) {
            if (setValue(&aux->right, input)) return; 
            aux = aux->right;
        }
        else {
            printf("this number exist in tree.\n");
            return;
        }
    } while(aux);
}

binarytree* searchRecursive(binarytree *root, int search) { 
    if (!root) return NULL;  
    if (root->value == search) return root; 
    return (search < root->value)  
        ? searchRecursive(root->left, search) 
        : searchRecursive(root->right, search); 
}

binarytree* search(binarytree *root, int search) {
    while(root && root->value != search) 
        root = (search < root->value) ? root->left : root->right;
    return root;
}

int calcHeight(binarytree *root) {
    if (root) {
        int esq = calcHeight(root->left);
        int right = calcHeight(root->right);
        return (esq > right) ? esq + 1 : right + 1;
    }
    return -1;
} 

int calcHeightNotRecursive(binarytree *root) {
    int height = -1; 
    int heightRight = -1; 
    binarytree *right = root; 
    while(root) {
        height++;  
        root = root->left; 
    }
    while(right) { 
        heightRight++; 
        right = right->right;
    }
    return height > heightRight ? height : heightRight; 
}

int calcNode(binarytree *root) { 
    return (root) ? (calcNode(root->left) + calcNode(root->right)) + 1 : 0;
}

int calcSheet(binarytree *root) {
    if (root == NULL) return 0; 
    return (root->left == NULL && root->right == NULL) 
        ? 1 
        : calcSheet(root->left) + calcSheet(root->right);
}

binarytree* removeNodeTree(binarytree* root, int search) {
    if (root) {
        if (root->value == search) {
            if (root->left == NULL && root->right == NULL)  {
                free(root);
                return NULL;
            }
            else if (root->left == NULL || root->right == NULL) {
                binarytree *aux = root->left ? root->left : root->right;
                free(root); 
                return aux; 
            }
            binarytree *aux = root; 
            while (aux->right)
                aux = aux->right; 
            root->value = aux->value; 
            free(aux);
            return root;
        }
        if (search < root->value)
            root->left = removeNodeTree(root->left, search);
        else 
            root->right = removeNodeTree(root->right, search);
            
        return root; 
    }
    printf("Valor: %d não encontrado\n", search);
    return NULL;
}

void removeNodeTreeNotRecursive(binarytree *root, int search) { 
    if (root) {
        binarytree *right = root->right; 
        while(root && root->value != search) 
            root = root->left; 
        if (root == NULL) {
            root = right;
            while (root && root->value != search)
                root = root->right; 
        }
        if (root == NULL) { printf("Valor: %d não exite na arvore\n", search);return; }
        if (root->left == NULL && root->right == NULL) {
            free(root);
            printf("Valor: %d removido", search);
            return; 
        }
        else if (root->left && root->right == NULL) {
            return; 
        }
        return;
    }

    printf("Valor: %d não encontrado\n", search);
}
