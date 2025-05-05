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

   binarytree *tree1 = createBinaryTree(1);
   binarytree *tree2 = createBinaryTree(2);
   binarytree *tree3 = createBinaryTree(3);
   binarytree *tree4 = createBinaryTree(4);
   binarytree *tree5 = createBinaryTree(5);

    tree1->left = tree2; 
    tree1->right = tree3; 

    tree3->left = tree4;
    tree3->right = tree5;

    print_binarytree(tree1, 0);

    free(tree1);
    free(tree2);
    free(tree3);
    free(tree4);
    free(tree5);
    
    return 1;
}


