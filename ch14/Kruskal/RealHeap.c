#include "RealHeap.h"

void HeapInit(Heap *ph, PriorityComp pc) {
    ph->numOfData = 0;
    ph->comp = pc;
}

int HIsEmpty(Heap *ph) {
    if (ph->numOfData == 0) {
        return TRUE;
    } else return FALSE;
}

int GetParantIDX(int idx) {
    return idx/2;
}

int GetLChildIDX(int idx) {
    return idx*2;
}

int GetRChildIDX(int idx) {
    return GetLChildIDX(idx)+1; // 2*idx+1
}

int GetHIChildIDX(Heap *ph, int idx) {
    if (GetLChildIDX(idx) > ph->numOfData) {
        return 0;
    } else if (GetLChildIDX(idx) == ph->numOfData) {
        return GetLChildIDX(idx);
    } else {
        if (ph->comp(ph->heapArr[GetLChildIDX(idx)], ph->heapArr[GetRChildIDX(idx)]) < 0) { // 왼쪽 자식보다 오른쪽 자식의 우선순위가 더 높을 때
            return GetRChildIDX(idx);
        } else { // 오른쪽 자식보다 왼쪽 자식의 우선순위가 더 높을 때
            return GetLChildIDX(idx);
        }
    }
}

void HInsert(Heap *ph, HData data) {

    int idx = ph->numOfData + 1;

    while(idx != 1) {

        if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0 ) {\
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)]; // 부모 노드를 한 계단 내린다.
            idx = GetParentIDX(idx); // 마지막 노드였던 것이 한 계단 올라간다.
        } else {
            break;
        }

        ph->heapArr[idx] = data;
        ph->numOfData += 1;
    }
}

HData HDelete(Heap *ph) {
    HData rdata = ph->heapArr[1];
    HData lastElem = ph->heapArr[ph->numOfData];

    int parentIdx = 1;
    int childIdx;

    while (childIdx = GetHIChildIDX(ph, parentIdx)) {
        if (ph->comp(ph->heapArr[childIdx], lastElem) <= 0) {
            break;
        }

        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }

    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;

    return rdata;
}