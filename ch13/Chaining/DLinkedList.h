#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#include "Slot2.h"

#define TRUE    1
#define FALSE   0

typedef Slot LData;

typedef struct _node {
    LData data;
    struct _node *next;
} Node;

typedef struct _linkedlist {
    Node *head;
    Node *cur;
    Node *before;
    int numOfData;
    int (*comp)(LData d1, LData d2);
} LinkedList; // 연결 리스트를 생성하기 위한 구조체

typedef LinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

int LRemove(List *plist);
int LCount(List *plist)

void SetSortRule(List *plist, (*comp)(LData d1, LData d2)); //정렬 기준의 지정

#endif