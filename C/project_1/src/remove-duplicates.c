#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/stack.h"


void ProcessDuplicate() {

    char* text = malloc(sizeof(char) * 100); 

    text = "abbaca";

    printf("result: %s\n", removeDuplicates(text));

}

char* removeDuplicates(char* s) {
    Stack* stackResponse = CreateStack(1);
    Stack* stackDuplicate = CreateStack(1);
    
    for (int i = 0; i < strlen(s); i++)
    {
        if (Peek(stackResponse) == s[i]) {
            Pop(stackResponse);
            Push(stackDuplicate, s[i]);
        }
        else {
            Push(stackResponse, s[i]);
        }
    }
    char* response = malloc(sizeof(char) * stackResponse->size + 1);

    int index = 0; 

    while (stackResponse->size >= 1 && stackResponse->top->next != NULL) {
        response[index] = Pop(stackResponse); 
        index++;
    }

    return response;
}
