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
        printf("\nSelect an option: \n 0 - Exit \n 1 - Include \n 2 - Remove \n 3 - Print pre-order\n");
        printf(" 4 - Print inorder\n 5 - Print postorder\n 6 - Print Tree\n");
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
                root = delete_binary(root, input);
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
            case 6:
                printf("Printing...\n"); 
                print_tree(root, 1); 
            break;
            
            default:
                printf("Insere a valid value..\n");
        }
    } while (option != 0);

    return -1; 
}


