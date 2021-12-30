#ifndef __AL_GRAPH__ // 무방향 그래프의 경우
#define __AL_GRAPH__

#include "DLinkedList.h"

enum {A, B, C, D, E, F, G, H, I, J}; // 정점들의 이름을 enum을 통해 상수화

typedef struct _ual {
    int numV; // 정점 개수
    int numE; // 간선 개수
    List *adjList; // 간선의 정보
} ALGraph;

void GraphInit(ALGraph *pg, int nv); // 그래프의 초기화. nv를 통해 정점의 개수를 전달받는다.

void GraphDestroy(ALGraph *pg); // 그래프의 Resource 해제. 초기화 과정에서 할당한 리소스를 반환함. 쉽게 말해 동적 할당에서 free함수의 역할을 생각하자.

void AddEdge(ALGraph *ph, int fromV, int toV); // 간선 추가.

void ShowGraphEdgeInfo(ALGraph *pg); // 간선의 정보를 출력한다.

#endif