#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CircularQueue.h"
#include "ALGraphDFS.h"
#include "DLinkedList.h"

int WhoIsPrecede(int data1, int data2) {
    if (data1 > data2) {
        return 0;
    } else {
        return 1;
    }
}

void GraphInit(ALGraph *pg, int nv) {
    
    pg->adjList = (List *) malloc(sizeof(List)*nv);
    
    pg->numV = nv;
    pg->numE = 0;

    for (int i=0 ; i<nv ; i++) {
        ListInit(&(pg->adjList[i]));
    }

    pg->visitInfo = (int *)malloc(sizeof(int) * pg->numV); 
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void GraphDestroy(ALGraph *pg) { 
    if (pg->adjList != NULL) {
        free(pg->adjList);
    }

    if (pg->visitInfo != NULL) {
        free(pg->visitInfo);
    }
}
void AddEdge(ALGraph *ph, int fromV, int toV) {
    
    LInsert(&(pg->adjList[fromV]), toV);

    LInsert(&(pg->adjList[toV]), fromV);
    pg->numE += 1;
}

void ShowGraphEdgeInfo(ALGraph *pg) {
    
    int vx;

    for(int i=0; i<pg->numV ; i++) {
        printf("Vertex connected to %c : ", i + 65);

        if(LFirst(&(pg->adjList[i]), &vx)) {
            printf("%c ", vx + 65);
        
            while(LNext(&(pg->adjList[i]), &vx)) {
                printf("%c ", vx+65);
            }
        }

        printf("\n");
    }
}

void DFShowGraphVertex(ALGraph *pg, int startV) { // 그래프의 정점 정보를 출력한다. (DFS 기반)
    
    Queue queue;
    int visitV = startV;
    int nextV;

    QueueInit(&queue);
    VisitVertex(pg, visitV); // 시작 정점을 방문

    // 아래 while문에서 모든 정점의 방문이 이뤄진다.
    while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) { // visitV에 담긴 정점과 연결된 정점의 방문을 시도한다.
        
        // visitV와 연결된 정점의 정보가 nextV에 담긴 상태에서 이하를 진행.
        // 위의 LFirst 함수 호출 -> visitV에 연결된 정점 하나 get -> 이 정점의 정보를 nextV에 저장

        // nextV에 담긴 정점의 정보로 방문 시도!
        if (VisitVertex(pg, nextV) == TRUE) {
            Enqueue(&queue, nextV);
        }

        while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
            if(VisitVertex(pg, nextV) == TRUE) {
                Enqueue(&queue, nextV);
            }
        }

        if (QIsEmpty(&queue) == TRUE) {
            break;
        } else {
            visitV = Dequeue(&queue);
        }
    }
    
    memset(pg->visitInfo, 0, sizeof(int) * pg->nextV);
}

int VisitVertex(ALGraph *pg, int visitV) { // 정점의 방문을 목적으로 정의된 함수

    if (pg->visitInfo[visitV] == 0) {
        pg->visitInfo[visitV] == 1; // 방문함을 1, 방문안함을 0으로 생각하자
        printf("%c ", visitV + 65); // 방문한 정점의 이름을 출력한다.
        return TRUE; // 방문 성공
    }

    return FALSE; // 방문 실패
}