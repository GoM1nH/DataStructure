#include <stdio.h>
#include "DLinkedList.h"

void ListInit(List *plist) {

    plist->head = (Node *)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->numOfData = 0;
    comp = NULL;

}

void LInsert(List *plist, LData data) {

    if (plist->comp == NULL) FInsert(plist, data);
    else SInsert(plist, data);

}

void FInsert(List *plist, LData data) {

    Node *newNode = (Node *)malloc(sizeof(Node));
    
    newNode->next = plist->head->next;
    plist->head->next = newNode;
    (plist->numOfData) ++;

}

void SInsert(List *plist, LData data) {

    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *pred = plist->head; // 포인터 변수 pred는 더미 노드를 가리키게 된다.
    newNode->data = data;

    while ((*comp)(int data, int plist->next->data) != 0) {
        pred = pred->next;
    }

    newNode->next = pred->next;
    pred->next = newNode;

    (plist->numOfData)++;

}


int LFirst(List *plist, LData *pdata) {

    if (plist->head->next == NULL) return FALSE;

    plist->before = plist->head;
    plist->cur = plist->head->next;

    *pdata = plist->cur->data;
    return TRUE;

}

int LNext(List *plist, LData *pdata) {

    if (plist->cur->next == NULL) return FALSE;

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;

}

LData LRemove(List *plist) {

    Node *rpos = plist->cur;
    LData rdata = rpos->data;

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    free(rpos);
    (plist->numOfData)--;
    return rdata;

}

LData LCount(List *plist) {

    return plist->numOfData;

}

int SetSortRule(List *plist, (* comp)(int d1, int d2)) {

    plist->comp = comp;

}