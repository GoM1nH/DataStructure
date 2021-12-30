#include <stdio.h>
#include <stdlib.h>
#include "ALGraph.h"
#include "DLinkedList.h"

void GraphInit(ALGraph *pg, int nv) {
    
    // 정점의 수에 해당하는 길이의 List 배열 생성
    pg->adjList = (List *) malloc(sizeof(List)*nv); // 여기에, 간선 정보가 저장될것임. 누가 누구랑 연결되어있나. 그런거.
    
    pg->numV = nv; // 정점의 수를 인자 nv로 결정
    pg->numE = 0; // 아직 만들어진 선은 없어

    for (int i=0 ; i<nv ; i++) {
        ListInit(&(pg->adjList[i]));
    }
}

void GraphDestroy(ALGraph *pg) { 
    if (pg->adjList != NULL) {
        free(pg->adjList);
    }
}
void AddEdge(ALGraph *ph, int fromV, int toV) {
    
    // fromV의 연결 리스트에 toV의 정보를 추가.
    // 만약 fromV가 B, toV가 D라면, adjList[B]에 D가 연결되어있다는걸 알리기 위해 D를 LInsert 해주는 것이다.
    LInsert(&(pg->adjList[fromV]), toV);

    LInsert(&(pg->adjList[toV]), fromV);
    pg->numE += 1;
}

void ShowGraphEdgeInfo(ALGraph *pg) {
    
    int vx;

    for(int i=0; i<pg->numV ; i++) {
        printf("Vertex connected to %c", i + 65);

        if(LFirst(&(pg->adjList[i]), &vx)) {
            printf("%c ", vx + 65);
        
            while(LNext(&(pg->adjList[i]), &vx)) {
                printf("%c ", vx+65);
            }
        }

        printf("\n");
    }
}