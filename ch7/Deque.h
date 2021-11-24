#ifndef __DEQUE_H__ 
#define __DEQUE_H__

#define TRUE    1
#define FALSE   0

typedef int Data;

typedef struct _node { // deque은 양방향 연결 리스트 기반으로 구현함.
    Data data;
    struct _node *next;
    struct _node *prev;
} Node;

typedef struct _dlDeque { // 처음과 끝 모두를 활용할거기에 head, tail 둘 다 삽입
    Node *head;
    Node *tail;
} DLDeque;

typedef DLDeque Deque;

void DequeInit(Deque *pdeq);
int DQIsEmpty(Deque *pdeq);

void DQAddFirst(Deque *pdeq, Data data); // 덱의 머리부분에 데이터 삽입
void DQAddLast(Deque *pdeq, Data data); // 덱의 꼬리부분에 데이터 삽입

Data DQRemoveFirst(Deque *pdeq); // 덱의 머리부분 데이터 뽑아냄
Data DQRemoveLast(Deque *pdeq); // 덱의 꼬리부분 데이터 뽑아냄

Data DQGetFirst(Deque *pdeq); // 덱의 머리부분 Peek
Data DQGetLast(Deque *pdeq); // 덱의 꼬리부분 Peek

#endif