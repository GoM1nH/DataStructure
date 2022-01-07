// 우선순위를 프로그램에서 알아서 정렬하는 기능을 구현 했을때의 코드.
// min Heap 을 기준으로 한다.

#ifndef __REAL_HEAP_H__
#define __REAL_HEAP_H__

#include "ALEdge.h"

#define TRUE    1
#define FALSE   0

#define HEAP_LEN 100

typedef Edge HData;
typedef int (*PriorityComp) (HData d1, HData d2); // 우선순위가 왼쪽이 높으면 양수, 오른쪽이 높으면 음수 

typedef struct _heap {
    PriorityComp * comp; // 함수 포인터 변수.
    int numOfData;
    HData heapArr[HEAP_LEN];
} Heap; // heap을 표현하는 구조체다.

void HeapInit(Heap *ph, PriorityComp pc);
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, HData data);
HData HDelete(Heap *ph);

#endif