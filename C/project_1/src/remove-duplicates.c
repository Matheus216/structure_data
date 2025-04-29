#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/stack.h"


void Process() {

    char* text = malloc(sizeof(char) * 100); 

    text = "abbaca";

    printf(removeDuplicates(text));

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
    return stackResponse;
}
