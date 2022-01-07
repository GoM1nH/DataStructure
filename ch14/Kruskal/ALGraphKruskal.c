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

    PQueueInit(&(pq->pqueue), PQWeightComp); // 우선순위 큐 초기화
}

int PQWeightComp(Edge d1, Edge d2) {
    return d1.weight - d2.weight; // for 내림차순으로 간선 정보 꺼내기
}

void GraphDestroy(ALGraph *pg) { 
    if (pg->adjList != NULL) {
        free(pg->adjList);
    }

    if (pg->visitInfo != NULL) {
        free(pg->visitInfo);
    }
}
void AddEdge(ALGraph *pg, int fromV, int toV, int weight) {
    
    Edge edge = {fromV, toV, weight}; // 간선의 가중치 정보를 담을 멤버다.

    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);
    pg->numE += 1;

    PEnqueue(&(pg->pqueue), edge); // 간선의 가중치 정보를 우선순위 큐에 저장해준다.
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

void ConKruskalMST(ALGraph *pg) { // New

    Edge recvEdge[20]; // 복원할 간선의 정보 저장
    Edge edge;
    int eidx = 0;
    int i;

    // MST 형성시까지 아래의 while문을 반복한다.
    while(pg->numE+1 > pg->numV) {// 간선 개수 + 1 = 정점 개수 일 때까지
    
        edge = PDequeue(&(pg->pqueue)); // 가중치가 제일 높은 간선의 정보를 꺼낸다.
        RemoveEdge(pg, edge.v1, edge.v2); // v1과 v2에 연결된 간선(위에서 꺼내진 간선)을 삭제한다

        if(!IsConnvertex(pg, edge.v1, edge.v2)) { // 간선을 삭제한 뒤에도, v1과 v2이 연결되어있는지 확인한다.
            RecoverEdge(pg, edge.v1, edge.v2, edge.weight); // 만약 경로가 없다면, 삭제된 간선을 다시 삽입
            recvEdge[eidx++] = edge; // 복원한 간선의 정보를 별도 저장.
            // 한번 검토가 이뤄진 간선은 재검토하지 않기에, 복원된 간선을 큐에 다시 넣지 않는다.
        }
    }

    for(i=0 ; i<eidx ; i++) { // 우선순위 큐에서 삭제된 간선의 정보를 회복한다. (원상복구)
        PEnqueue(&(pg->pqueue), recvEdge[i]);
    }
}

void ShowGraphEdgeWeightInfo(ALGraph *pg) { // 간선의 가중치 정보 출력
    PQueue copyPQ = pg->pqueue;
    Edge edge;

    while(!PQIsEmpty(&copyPQ)) {
        edge = PDqueue(&copyPQ);
        printf("(%c-%c), w:%d \n", edge.v1+65, edge.v2+65, edge.weight);
    }
}