#include <stdio.h>
#include "RealHeap.h" // Heap을 사용함
// 이 코드를 컴파일하기 전, "ReapHeap.c"의 typedef char HData를 typedef int HData로 바꿔주어야 한다.

int PriComp(int n1, int n2) {
    return n2-n1;
}

void HeapSort(int arr[], int n, PriorityComp pc) {
    Heap heap;
    int i;

    HeapInit(&heap, pc);

    for (i=0 ; i<n ; i++) {
        HInsert(&heap, arr[i]);
    }

    for (i=0 ; i<n ; i++) {
        arr[i] = HDelete(&heap);
    }
}