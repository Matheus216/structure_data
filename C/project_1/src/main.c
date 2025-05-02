#include <stdio.h>
#include <stdlib.h>


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


int main() {
    /*
    printf("Circular linked list ------------------");
    CircularList list; 

    Init(&list);

    Include(&list, 12);
    Include(&list, 22);
    Include(&list, 442);
    Include(&list, 33);
    Include(&list, 45);

    Node* node = Search(&list, 22);
    printf("Valor encontrado: %d \n", node->val);

    PrintCircularList(&list);

    Remove(&list, 12);
    Remove(&list, 45);
    Remove(&list, 442);
    Remove(&list, 22);
    Remove(&list, 33);
    
    printf("End Circular Linked List------------------\n");

    printf("Queue ------------------\n\n");

    Queue* queue = CreateQueue(1); 

    Enqueue(queue, 1);
    Enqueue(queue, 2);
    Enqueue(queue, 3);
    Enqueue(queue, 4);

    Dequeue(queue);
    Dequeue(queue);
    Dequeue(queue);
    Dequeue(queue);

    printf("End Queue ---------------------\n");


    printf("--------------- Stack ----------------\n");

    MyStack* myStack = myStackCreate();

    myStackPush(myStack, 1);
    myStackPush(myStack, 2);
    myStackPush(myStack, 3);
    myStackPush(myStack, 4);
    myStackPush(myStack, 5);
    myStackPush(myStack, 6);

    myStackTop(myStack);

    myStackPop(myStack);
    myStackPop(myStack);
    myStackPop(myStack);
    myStackPop(myStack);
    myStackPop(myStack);
    
    myStackEmpty(myStack);
    
    myStackPop(myStack);
    
    myStackEmpty(myStack);

    myStackFree(myStack);

    printf("--------------- End Stack ------------\n");*/

    
    //ProcessDuplicate();

    int input[] = {2,7,11,15}; 
    int response = SearchInsert(input,11); 
    printf("%d\n", response);
    
    response = SearchInsert(input,15); 
    printf("%d\n", response);
    

    return 1;
}
