#include <stdio.h>
#include "RealHeap.h"

int DataPriorityComp (char ch1, char ch2) {
    return ch2 - ch1;
} // 만약 (A, B) 가 비교된다면, A가 B보다 우선순위가 높으므로 ch2 - ch1값이 양수가 나온다. 아스키 코드 값으로 비교함.

int main() {

    Heap heap;
    HeapInit(&heap, DataPriorityComp);

    HInsert(&heap, 'A');
    HInsert(&heap, 'B');
    HInsert(&heap, 'C');
    printf("%c \n", HDelete(&heap));

    HInsert(&heap, 'A');

    while(!HIsEmpty(&heap)) {
        printf("%c \n", HDelete(&heap));
    }

    return 0;

}