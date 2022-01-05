// 연결리스트의 헤더 / 소스파일은 DFS 폴더의 파일과 똑같으므로 생략하겠다.
#ifndef __AL_GRAPH_BFS_H__
#define __AL_GRAPH_BFS_H__

#include "DLinkedList.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual {
    int numV;
    int numE;
    List *adjList;
    int *visitInfo;
} ALGraph;

void GraphInit(ALGraph *pg, int nv);

void GraphDestroy(ALGraph *pg);

void AddEdge(ALGraph *ph, int fromV, int toV);

void ShowGraphEdgeInfo(ALGraph *pg);

void BFShowGraphVertex(ALGraph *pg, int startV);

#endif