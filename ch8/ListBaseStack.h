#ifndef __LIST_BASE_STACK_H__
#define __LIST_BASE_STACK_H__

#define TRUE    1;
#define FALSE   0;

typedef int Data;

typedef struct __node {
    Data data;
    struct __node *next;
} Node; // 계속 보던 걔

typedef struct __listStack {
    Node *head;
} ListStack; // 연결 리스트를 기반으로 한 스택을 구현한 구조체

typedef ListStack Stack;

void StackInit(Stack *pstack); 
int SIsEmpty(Stack *pstack); 

void SPush(Stack *pstack, Data data); 
Data SPop(Stack *pstack);
Data SPeek(Stack *pstack);

#endif