#include <stdio.h>
#include <stdlib.h>

#include "../include/binarytree.h"

int* twoSum(int* nums, int numsSize, int target) {
    int* response = malloc(sizeof(int) * 2); 
    int index = 1; 

    do {
        if (target == (nums[index] + nums[index - 1])) {
            response[0] = index-1; 
            response[1] = index; 
            break;
        }
        index++; 
    } while (index < numsSize);

    return response; 
}

int SearchInsert(int* nums, int target) {
    int begin = 0, end = sizeof(nums) / sizeof(nums[0]); 

    while (begin <= end) {
        int mid = (begin + end) / 2; 
        if (nums[mid] == target) return mid; 
        else if (nums[mid] < target) {
            begin = mid + 1;
        }
        else {
            end = mid -1; 
        }
    }

    return begin;
}

void LeetCodeProblem() {
    int input[] = {2,7,11,15}; 
    int response = SearchInsert(input,11); 
    printf("%d\n", response);
    
    response = SearchInsert(input,15); 
    printf("%d\n", response);
}

int main() {

    binarytree *root = NULL; 
    int option = 0, input = 0;     

    do {
        printf("\nSelect an option: \n"); 
        printf(" 0 - Exit \n");
        printf(" 1 - Include \n");
        printf(" 2 - Remove \n");
        printf(" 3 - Print pre-order\n");
        printf(" 4 - Print inorder\n"); 
        printf(" 5 - Print postorder\n");
        printf(" 6 - Print Tree\n");
        printf(" 7 - Insert without recursive way\n");
        printf(" 8 - Search Recursive\n");
        printf(" 9 - Search\n");
        printf(" 10 - Height\n");
        printf(" 11 - Calcule Nodes\n");
        printf(" 12 - Calcule Sheets\n");
        printf(" 13 - Remove node\n");
        scanf("%d", &option); 
        
        printf("------------\n\n");

        switch (option)
        {
            case 0 :
                printf("Exiting\n");
            break;
            case 1:
                printf("Including..\n");
                printf("Insira um valor:\n");
                scanf("%d", &input);
                printf("\n"); 
                root = insert_binary_balanced(root, input);
            break; 
            case 2:
                printf("Removing..\n");
                printf("Insira um valor:\n");
                scanf("%d", &input);
                root = delete_binary_balanced(root, input);
            case 3: 
                printf("Printing...\n");
                print_preorder_transversal(root, 1); 
            break;
            case 4:
                printf("Printing...\n");
                print_inorder_transversal(root, 1); 
            break;
             case 5: 
                printf("Printing...\n");
                print_postorder_transversal(root, 1);
              break;
            case 6:
                printf("Printing...\n"); 
                print_tree(root, 1); 
            break;
            case 7:
                printf("Including..\n");
                printf("Insira um valor:\n");
                scanf("%d", &input);
                printf("\n"); 
                insertWithoutRecursion(&root, input); 
            break;
            case 8: 
                printf("Searching...\n");
                printf("Insira o valor que deseja encontrar: ");
                scanf("%d", &input);
                binarytree* response = searchRecursive(root, input);
                if (response == NULL) printf("Valor não encontrado\n");
                else printf("\nValor encontrado: %d", response->value);
            break;
            case 9: 
                printf("Searching...\n");
                printf("Insira o valor que deseja encontrar: ");
                scanf("%d", &input);
                binarytree* response2 = search(root, input);
                if (response2 == NULL) printf("Valor não encontrado\n");
                else printf("\nValor encontrado: %d", response2->value);
            break;
            case 10:
                printf("calcuating height\n");
                printf("height: %d \n", calcHeightNotRecursive(root));
            break; 
            case 11:
                printf("calculating nodes\n"); 
                printf("Nodes: %d\n", calcNode(root)); 
            break; 
            case 12:
                printf("calculating sheets\n"); 
                printf("Sheets: %d\n", calcSheet(root)); 
            break;
            case 13: 
                printf("Removing...\n");
                printf("Insira o valor que deseja remover: ");
                scanf("%d", &input);
                binarytree *response3 = removeNodeTree(root, input);
                if (response3) printf("Valor: %d removido\n", input);
            break;
            default:
                printf("Insere a valid value..\n");
        }
    } while (option != 0);

    return -1; 
}


