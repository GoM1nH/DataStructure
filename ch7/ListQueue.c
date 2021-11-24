#include <stdio.h>
#include <stdlib.h>
#include "ListQueue.h"

void QueueInit (Queue *pq) {
    pq->front = NULL;
    pq->rear = NULL;
}

int QIsEmpty (Queue *pq) {
    if (pq->front == NULL) {
        return TRUE;
    } else return FALSE;
}

void Enqueue (Queue *pq, Data data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;

    if (QIsEmpty(pq)) { // Queue에 첫 노드를 추가하게 된다면
        pq->front = newNode;
        pq->rear = newNode;
    } else { // 기존에 이미 추가된 노드가 있다면
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}

Data Dequeue (Queue *pq) {

    Node *delNode;
    Data retData;

    if (QIsEmpty(pq)) {
        printf("ERROR\n");
        exit(-1);
    }

    delNode = pq->front;
    retData = delNode->data;
    pq->front = pq->front->next;

    free(delNode);
    return retData;
}

Data QPeek (Queue *pq) {
    
    if (QIsEmpty(pq)) {
        printf("ERROR\n");
        exit(-1);
    }

    return pq->front->data;
}