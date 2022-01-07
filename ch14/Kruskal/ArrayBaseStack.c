#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

void StackInit (Stack *pstack) {
    pstack->topIndex = -1;
} // 왜 초기화를 -1로 해주냐? : 만약 topIndex가 0이라면, 인덱스 0에 마지막 데이터 (가장 처음 넣은 데이터)가 추가되어있음을 의미함.

int SIsEmpty (Stack *pstack) {
    if (pstack -> topIndex == -1) return TRUE;
    else return FALSE;
}

void SPush(Stack *pstack, Data data) {

    pstack->topIndex += 1;
    pstack->stackArr[pstack->topIndex] = data;

}

Data SPop(Stack *pstack) {
    // Pop은 "삭제", "반환"의 의미가 함께 담겨있음. 변수에 저장된 값을 하나 감소시키기만 해도 데이터 소멸 완성.
    // topIndex 값을 근거로 데이터를 저장해서 이러한 방식으로 데이터 소멸이 가능함.

    int rIdx;

    if (SIsEmpty(pstack)) {
        printf("Stack Memory Error!\n"); // 지울 게 없는데 뭘 지우냐!
        exit(-1);
    }

    rIdx = pstack->topIndex; // 삭제할 데이터가 저장된 Index 값을 저장한다.
    pstack->topIndex -= 1;

    return pstack->stackArr[rIdx];
}

Data SPeek(Stack *pstack) {
    
    if (SIsEmpty(pstack)) {
        printf("Stack Memory Error!\n"); // 확인할 메모리도 없다!
        exit(-1);
    }

    return pstack->stackArr[pstack->topIndex];
}

