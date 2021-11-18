#ifndef __ARRAY_BASE_STACK_H__
#define __ARRAY_BASE_STACK_H__

#define TRUE        1
#define FALSE       0
#define STACK_LEN   100

typedef int Data;

typedef struct __arrayStack { // Stack을 의미하는 구조체
    Data stackArr[STACK_LEN]; // 스택 배열의 크기
    int topIndex; // 안에 들어있는 데이터가 총 몇개인지를 의미함
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack *pstack); // 스택 초기화, 연결리스트에서 ListInit 과 같은 역할
int SIsEmpty(Stack *pstack); // 스택이 비었는지 확인함. 비었으면 TRUE, 아니면 FALSE

void SPush(Stack *pstack, Data data); // 스택에 데이터를 집어 넣음
Data SPop(Stack *pstack); // 스택에서 데이터를 제거함.
Data SPeek(Stack *pstack); // 스택에서 데이터를 빼서 확인만함. 지우지는 않음.

#endif