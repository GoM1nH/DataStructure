#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayBaseStack.h"
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

    pg->visitInfo = (int *)malloc(sizeof(int) * pg->numV); // New. visitInfo 관련 초기화 진행
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void GraphDestroy(ALGraph *pg) { 
    if (pg->adjList != NULL) {
        free(pg->adjList);
    }

    if (pg->visitInfo != NULL) {
        free(pg->visitInfo); // New. visitInfo 관련 리소스 해제 진행
    }
}
void AddEdge(ALGraph *pg, int fromV, int toV) {
    
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

void DFShowGraphVertex(ALGraph *pg, int startV) { // 그래프의 정점 정보를 출력한다. (DFS 기반)
    
    Stack stack;
    int visitV = startV;
    int nextV;

    StackInit(&stack);
    VisitVertex(pg, visitV); // 시작 정점을 방문
    SPush(&stack, visitV); // 시작 정점의 정보를 Stack으로 이동.

    // 아래 while문에서 모든 정점의 방문이 이뤄진다.
    while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) { // visitV에 담긴 정점과 연결된 정점의 방문을 시도한다.
        
        // visitV와 연결된 정점의 정보가 nextV에 담긴 상태에서 이하를 진행.
        // 위의 LFirst 함수 호출 -> visitV에 연결된 정점 하나 get -> 이 정점의 정보를 nextV에 저장
        
        int visitFlag = FALSE;

        // nextV에 담긴 정점의 정보로 방문 시도!
        if (VisitVertex(pg, nextV) == TRUE) { // 방문에 성공했을 시.
            SPush(&stack, visitV);
            visitV = nextV;
            visitFlag = TRUE; // while문 재시작. 다른 정점의 방문을 시도한다
        }
        else
        { // 만약 방문을 실패했다면, 다른 정점을 찾는다.
            while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
                if(VisitVertex(pg, nextV) == TRUE) {
                    SPush(&stack, visitV);
                    visitV = nextV;
                    visitFlag = TRUE;
                    break;
                }
            }
        }

        if (visitFlag == FALSE) { // 만약, 추가로 방문한 정점이 없다? (정점 방문 실패)
            
            // 스택이 비면 탐색의 시작점으로 되돌아온거다.
            if(SIsEmpty(&stack) == TRUE) { // 시작점으로 되돌아왔다. (= 스택에 든게 없다)
                break;
            } else { // 시작점으로 돌아온게 아니라면
                visitV = SPop(&stack); // 되돌아가
            }
        }
    }

    memset(pg->visitInfo, 0, sizeof(int) * pg->numV); // 이후의 탐색을 위해, 탐색 정보를 초기화한다.

}

int VisitVertex(ALGraph *pg, int visitV) { // 정점의 방문을 목적으로 정의된 함수

    if (pg->visitInfo[visitV] == 0) {
        pg->visitInfo[visitV] == 1; // 방문함을 1, 방문안함을 0으로 생각하자
        printf("%c ", visitV + 65); // 방문한 정점의 이름을 출력한다.
        return TRUE; // 방문 성공
    }

    return FALSE; // 방문 실패
}