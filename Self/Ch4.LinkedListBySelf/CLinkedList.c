#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h" 

void ListInit(List *plist) { // List 초기화
    plist->tail = NULL;
    plist->before = NULL;
    plist->cur = NULL;
    plist->numOfData = 0;
}

void LInsertFront(List *plist, Data data) { // List의 머리 부분에 데이터 삽입
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (plist->tail == NULL) { // 저장된 데이터가 없을 때
        plist->tail = newNode;
        newNode->next = newNode;
    } else  { // 앞서 저장된 데이터가 있을 때
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }

    (plist->numOfData)++;
}

void LInsert(List *plist, Data data) { // List의 꼬리 부분에 데이터 삽입
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (plist->tail == NULL) { // 저장된 데이터가 없을 때
        plist->tail = newNode;
        newNode->next = newNode;
    } else { // 앞서 저장된 데이터가 있을 때
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode; // 새 노드가 꼬리가 되었다.
    }

    (plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata) {
    if (plist->tail == NULL) return FALSE;

    plist->before = plist->tail;
    plist->cur = plist->tail->next;

    *pdata = plist->cur->data;
    return TRUE;
}

int LNext (List *plist, Data *pdata) { // List의 끝을 체크하는 코드가 없다. (if plist->cur->next == NULL..) 무한 반복 able.
    if (plist->tail == NULL) return FALSE; // 꼬리가 없을 때 즉, 저장된 데이터가 없을 때

    plist->before = plist->cur;
    plist->cur = plist->before->next;

    *pdata = plist->cur->data;
    return TRUE;
}

Data LRemove (List *plist) {

    Node *rpos = plist->cur;
    Data rdata = rpos->data;

    if (rpos == plist->tail) { // 만약, 삭제할 대상과 tail이 가리키는 대상이 같다
        if (plist->tail->next == plist->tail) { // 그리고 그 대상이 마지막 홀로 남은 대상이다
            plist->tail = NULL;
        } else {
            plist->tail = plist->before;
        }
    }
    
    plist->before->next = plist->cur->next; // 여기부턴 그냥 연결 리스트의 LRemove와 같음
    plist->cur = plist->before;
    
    free(rpos);
    (plist->numOfData)--;
    return rdata;

}

int LCount(List *plist) {
    return plist->numOfData;
}