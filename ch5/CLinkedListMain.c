#include <stdio.h>
#include <malloc.h>
#include "CLinkedList.h"

int main() {
    List list;
    int data, i, nodeNum;
    ListInit(&list);

    LInsert(&list,3);
    LInsert(&list,4);
    LInsertFront(&list,5);
    LInsert(&list,6);
    LInsertFront(&list,7);

    if (LFirst(&list, &data)) {
        printf("%d ", data);

        for (i=0 ; i<LCount(&list)-1 ; i++) { // LCount(&list) "-1" 인 이유는, 맨 첫 데이터 LFirst는 앞에서 체크 해줬으니까.
            if(LNext(&list, &data)) printf("%d ", data);
        }
    }
    printf("\n\n");

    nodeNum = LCount(&list);

    if (nodeNum != 0) {
        LFirst(&list, &data);
        if(data%2 == 0) LRemove(&list);

        for (i=0 ; i< nodeNum-1 ; i++) {
            LNext(&list, &data);
            if (data%2 == 0) LRemove(&list);
        }
    }

    if (LFirst(&list, &data)) {
        printf("%d ", data);

        for (i=0 ; i<LCount(&list)-1 ; i++) { // LCount(&list) "-1" 인 이유는, 맨 첫 데이터 LFirst는 앞에서 체크 해줬으니까.
            if(LNext(&list, &data)) printf("%d ", data);
        }
    }
    printf("\n");
}