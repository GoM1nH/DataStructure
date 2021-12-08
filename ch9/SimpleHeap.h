#ifndef __SIMPLE_HEAP_H__
#define __SIMPLE_HEAP_H__

#define TRUE    1
#define FALSE   0

#define HEAP_LEN 100

typedef char HData; // 노드에 들어있는 data. 'A', 'B', 'C'와 같은 알파벳을 삽입한다고 가정한다.
typedef int Priority; // 우선순위. 값이 작을수록 우선 순위가 높은 min heap이라고 가정한다.

typedef struct _heapElem {
    Priority pr;
    HData data;
} HeapElem; // Heap에 저장될 데이터의 모델을 정의. (우선순위 고려)

typedef struct _heap {
    int numOfData;
    HeapElem heapArr[HEAP_LEN];
} Heap; // heap을 표현하는 구조체다.

void HeapInit(Heap *ph);
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, HData data, Priority pr); // 데이터 저장은  밑에서 위로 올라가며 진행된다
HData HDelete(Heap *ph); // 데이터 삭제는 위에서 밑으로 내려가며 진행된다

#endif