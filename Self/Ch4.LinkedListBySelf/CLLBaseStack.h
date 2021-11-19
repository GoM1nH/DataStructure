#ifndef __C_L_L_BASE_STACK_H__
#define __C_L_L_BASE_STACK_H__

#include "CLinkedList.h"

#define TRUE    1;
#define FALSE   0;

typedef int Data;

typedef struct __cllStack {
    List *plist;
} CListStack; // 연결 리스트를 기반으로 한 스택을 구현한 구조체

typedef CListStack Stack;

void StackInit(Stack *pstack); 
int SIsEmpty(Stack *pstack); 

void SPush(Stack *pstack, Data data); 
Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);

#endif