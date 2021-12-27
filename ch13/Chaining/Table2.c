#include <stdio.h>
#include <stdlib.h>
#include "Table2.h"
#include "DLinkedList.h"

void TBLInit(Table * pt, HashFunc * f) {
    int i;

    for (i=0 ; i<MAX_TBL ; i++) {
        ListInit(&(pf->tbl[i]));
    }
    
    pf->hf = f;
}

void TBLInsert(Table * pt, Key k, Value v) {
    int hv = pt->hf(k); // hv에는 해쉬값을 저장한다. 즉, 최종적으로 Slot(k,v)가 저장될 idx값.
    Slot ns = {k, v};

    if (TBLSearch(pt, k) != NULL) { // 키 중복
        printf("Key Duplication Error\n");
        return;
    } else { // 키 중복이 아니라면
        LInsert(&(pt->tbl[hv]), ns); // Table의 해쉬값을 인덱스로 하는 위치에 ns 저장.
    }
}

Value TBLDelete(Table * pt, Key k) {
    int hv = pt->hf(k);
    Slot cSlot;

    if (LFirst(&pt->tbl[hv], &cSlot)) { // list의 첫 데이터

        if (cSlot.key == k) { // 만약 지금 slot의 key(cSlot.key)가 내가 찾는 key(k)와 같다면 
            return cSlot.val;
        } else {
            while(LNext(&(pt->tbl[hv]), &cSlot)) {
                if (cSlot.key == k) { // 만약 지금 slot의 key(cSlot.key)가 내가 찾는 key(k)와 같다면 
                    LRemove(&(pt->tbl[hv]));
                    return cSlot.val;
                }
            }
        }
    }

    return NULL;
}
Value TBLSearch(Table * pt, Key k) {
    int hv = pt->hf(k);
    Slot cSlot;

     if (LFirst(&pt->tbl[hv], &cSlot)) { // list의 첫 데이터

        if (cSlot.key == k) { // 만약 지금 slot의 key(cSlot.key)가 내가 찾는 key(k)와 같다면 
            return cSlot.val;
        } else {
            while(LNext(&(pt->tbl[hv]), &cSlot)) {
                if (cSlot.key == k) {
                    return cSlot.val;
                }
            }
        }
    }

    return NULL;

}