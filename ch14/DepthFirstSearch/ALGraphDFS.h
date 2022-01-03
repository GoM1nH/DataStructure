#ifndef __AL_GRAPH_DPS__
#define __AL_GRAPH_DPS__

#include "DLinkedList.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual {
    int numV;
    int numE;
    List *adjList;
    int *visitInfo; // New. 방문 이력 남기기. 탐색이 ㅣ=진행된 정점의 정보를 담는다.
} ALGraph;

void GraphInit(ALGraph *pg, int nv);

void GraphDestroy(ALGraph *pg);

void AddEdge(ALGraph *ph, int fromV, int toV);

void ShowGraphEdgeInfo(ALGraph *pg);

void DFShowGraphVertex(ALGraph *pg, int startV); // New. 정점의 정보를 DFS 기반으로 출력한다.

#endif