#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "ListBaseStack.h"

void StackInit(Stack *pstack) {
    pstack->head = NULL;
}
int SIsEmpty(Stack *pstack) {
    if (pstack->head == NULL) {
        return TRUE;
    } else return FALSE;
}

void SPush(Stack *pstack, Data data) {
    
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    pstack->head = newNode;
}

Data SPop(Stack *pstack) {
    
    Data rdata;
    Node *rnode;

    if (SIsEmpty(pstack)) {
        printf("ERROR\n");
        exit(-1);
    }

    rnode = pstack->head;
    rdata = pstack->head->data;

    pstack->head = pstack->head->next; // 연결 리스트의 before처럼 생각해주자! head가 옮겨가니까 before가 아니고 next다.
    free(rnode);
    return rdata;
}

Data SPeek(Stack *pstack) {

    if(SIsEmpty(pstack)) {
        printf("ERROR!\n");
        exit(-1);
    }

    return pstack->head->data;
}