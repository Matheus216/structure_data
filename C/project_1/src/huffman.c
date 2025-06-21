#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "../include/huffman.h"

#define TAM 256

void initializerTable(unsigned int frequencyTable[]) {
    for(int i = 0;i<TAM;i++)
        frequencyTable[i] = 0;
}

void fillFrequencyTable(unsigned int frequencyTable[], unsigned char inputText[]) {
    int index = 0; 
    while (inputText[index] != '\0'){
        frequencyTable[inputText[index]]++; 
        index++; 
    }
}

void printFrequencyTable(unsigned int frequencyTable[]) {
    for (int i =0; i<TAM;i++) 
        if (frequencyTable[i] > 0)
            printf("Valor: %d no indice: %d char: %c \n", frequencyTable[i], i, i);
}

void createListNode(ListNode *list) {
    list->root = NULL;
    list->tam = 0;
}

void insertListNode(Node *item, ListNode *list) {
    if (list->root) {
        if (item->frequency < list->root->frequency) {
            item->next = list->root;
            list->root = item; 
            list->tam++;
            return;
        }
        Node *aux = list->root;
        while (aux->next && aux->next->frequency <= item->frequency)
            aux = aux->next;
        item->next = aux->next;
        aux->next = item; 
        list->tam++;
        return;
    }
    list->root = item;
    list->tam++;
}

void fillListNode(unsigned int frequencyTable[], ListNode *list) {
    for (int i = 0; i< TAM; i++) {
        if (frequencyTable[i] > 0) {
            Node *node = malloc(sizeof(Node));
            if (!node) {
                printf("um problema ocorreu ao alocar memória. \n");
                return;
            }
            node->caracter = i;
            node->frequency = frequencyTable[i];
            node->next = NULL;
            node->left = NULL;
            node->right = NULL;
            insertListNode(node, list);
        }
    }
}

void printListNode(ListNode *list) {
    Node *aux =  list->root;
    printf("\nLista ordenada tamanho: %d\n", list->tam);
    for (int i = 0; i<list->tam;i++){
        printf("%d caracter: %c Frequencia: %d\n", i, aux->caracter, aux->frequency);
        aux = aux->next;
    }
}

// -- montar arvore de huffman
Node* removeItemList(ListNode *list) {
    Node* aux;
    if (list->root) {
        aux = list->root;
        list->root = aux->next;
        aux->next = NULL;
        list->tam--;
    }
    return aux;
}

Node* createHoffmanTree(ListNode *list) {
    if (list->root) {
            Node *first, *second, *response; 
            while (list->tam > 1) {

                first = removeItemList(list);
                second = removeItemList(list);

                response = malloc(sizeof(Node));
                response->frequency = first->frequency + second->frequency;
                response->caracter = '+';
                response->left = first;
                response->right = second;
                insertListNode(response, list);
            }
    }
    return list->root;
}

void printHoffmanTree(Node *node, int level) {
    if (node) {
        printHoffmanTree(node->left, level+1); 
        if(!node->left && !node->right)
            printf("Frequency: %d Caracter: %c\n", node->frequency, node->caracter);
        printHoffmanTree(node->right, level + 1);    
    }
} 

int getHeightHuffman(Node *root) { 
    if (!root) return -1;
    int esq, dir;
    esq = getHeightHuffman(root->left) + 1;
    dir = getHeightHuffman(root->right) + 1;
    return esq > dir ? esq : dir; 
}

char** allocDicionary(int cols) {
    char **dic = malloc(sizeof(char*) * TAM); 
    for (int i=0; i<TAM; i++) {
        dic[i] = calloc(cols,sizeof(char*)); 
    }
    return dic; 
}

void addDicionary(Node *root, char **dic, char *binaryText, int cols) {

    if (root->left || root->right) {
        char esq[cols], rig[cols]; 

        strcpy(esq, binaryText);
        strcpy(rig, binaryText);

        strcat(esq, "0");
        strcat(rig, "1");

        addDicionary(root->left, dic, esq, cols); 
        addDicionary(root->right, dic, rig, cols);
    }   
    strcpy(dic[root->caracter], binaryText);
}

void printDicionary(char **dic) {
    printf("\nDictionary: \n");
    for (int i=0;i<TAM;i++)
        if (strlen(dic[i]) > 0)
            printf("%3d - %s\n", i, dic[i]);
}

int calcLen(unsigned char *text, char **dic) {
    if(!text) {
        printf("invalid text in calcLen function");
        return 0;   
    } 

    int index = 0, tam = 0; 
    while(text[index] != '\0'){
        tam += strlen(dic[text[index]]); 
        index++;
    }
    return tam + 1; 
}

char* coding( 
    unsigned char *text, 
    char **dic
) {
    if (!text) {
        printf("text invalid in coding function");
        return "error";
    }
    int i = 0, tam = calcLen(text, dic);
    char *response = calloc(tam, sizeof(char)); 
    printf("\nCoding:\n");
    while (text[i] != '\0') {
        strcat(response, dic[text[i]]); 
        i++;
    }
    printf("\n");

    return response;
}

char* decode(unsigned char *textCoding, Node *node) {
    
    printf("\nDecoding:\n");
    int index = 0;
    char tempStr[2];
    tempStr[1] = '\0';
    int count = strlen(textCoding);

    char *response = calloc(count, sizeof(char));
    Node *temp = node;
    while (textCoding[index] != '\0') {
        if (textCoding[index] == '0')
            temp = temp->left;
        else
            temp = temp->right;

        if (!temp->left && !temp->right) {
            tempStr[0] = temp->caracter;
            strcat(response, tempStr);
            temp = node;
        }
        index++;
    }
    return response;
}

void compact(unsigned char input[]) {
    FILE *file = fopen("compacted.mm", "wb"); 
    if (!file) return; 

    int index = 0, j = 7; 
    unsigned char mascara, byte = 0; 

    while (input[index] != '\0') {
        mascara = 1;
        if (input[index] == '1') {
            mascara = mascara << j; 
            byte = byte | mascara; 
        }
        j--; 
        if (j < 0) {
            fwrite(&byte, sizeof(unsigned char), 1, file);
            j = 7;
            byte = 0; 
        }
        index++; 
    }

    if (j != 7) 
        fwrite(&byte, sizeof(unsigned char), 1, file);

    fclose(file);
}

unsigned int isBitOne(unsigned char input, int count) {
    unsigned char mask = (1 << count); 
    return input & mask; 
}

void descompact(Node *root) {
    FILE *file = fopen("compacted.mm", "rb"); 

    if (!file) {
        printf("\n Erro ao ler arquivo para descompactar\n");
        return;
    }

    unsigned char byte; 
    Node *aux = root; 

    while (fread(&byte, sizeof(unsigned char), 1, file)) {
        for (int i = 7; i >= 0; i--) {
            if (isBitOne(byte, i)) 
                aux = aux->right;    
            else 
                aux = aux->left;

            if (aux->left == NULL && aux->right == NULL) {
                printf("%c", aux->caracter); 
                aux = root;
            }
        }
    }
    fclose(file);
    printf("\nFinalizado processo do arquivo\n");
}

int countFile() {
    FILE *file = fopen("input.txt", "r");
    int len = 0; 

    if (!file) {
        printf("\nError to open file input.txt\n");
        return len;
    }

    while (getc(file) > 0) 
        len++;
    
    fclose(file);
        
    return len; 
}

void readFile(unsigned char *text) {
    if (!text) {
        printf("\ninválid text input\n");
        return;
    }
    
    FILE *file = fopen("input.txt", "r"); 
    char letter; 
    int i = 0;
    
    if (!file) {
        printf("\nError to open file input.txt\n");
        return;
    }
    
    while (!feof(file)) {
        letter = fgetc(file);
        if (letter >= 0) 
            text[i++] = letter;
        
    }
    fclose(file); 
}

void hoffman() {
    unsigned int frequencyTable[TAM]; 
    char **dic; 
    int count = countFile();
    printf("\nQuantidade = %d\n", count);
    unsigned char *textToCompact = calloc(count + 2, sizeof(char));
    
    readFile(textToCompact);

    printf("\nContent: %s\n", textToCompact);
    
    setlocale(LC_ALL, "Portuguese");

    ListNode root;

    //Part 1 tabela de frequencia
    initializerTable(frequencyTable);
    fillFrequencyTable(frequencyTable, textToCompact);
    printFrequencyTable(frequencyTable);
    
    //Part 2 montar tabela
    createListNode(&root);
    fillListNode(frequencyTable, &root);
    printListNode(&root);

    //Part 3 montar arvore
    Node *tree = createHoffmanTree(&root);
    printf("\n*** Arvore de Huffman ***\n");
    printHoffmanTree(tree, 0); 

    //Part 4 montar dicionario
    int cols = getHeightHuffman(tree);
    dic = allocDicionary(cols); 
    addDicionary(tree, dic, "", cols);
    printDicionary(dic);

    //parte 5 coding 
    char *codingText = coding(textToCompact, dic);

    //parte 6 decode
    char *responseDecode = decode(codingText, tree);

    //parte 7 compact text file
    compact(codingText); 

    // part 8 descompact file
    descompact(tree);

    free(textToCompact); 
    free(codingText); 
    free(responseDecode);
}
