#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE  1;
#define FALSE 1;

typedef int LData;

typedef struct _node {
    LData data;
    struct _node *next;
} Node;

typedef struct _linkedlist {

    Node *head;
    Node *before;
    Node *cur;
    int numOfData;
    int (* comp) (int d1, int d2);

} LinkedList;

typedef LinkedList List;

void FInsert(List *plist, LData data);
void SInsert(List *plist, LData data);

void ListInit(List *plist);
void LInsert(List *plist, LData data);

int LFirst(List *plist, LData *pdata);
int LNext(List *plist, LData *pdata);

LData LRemove(List *plist);
LData LCount(List *plist);

int SetSortRule(List *plist, (* comp)(int d1, int d2));

#endif