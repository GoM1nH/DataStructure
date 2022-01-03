#include <stdio.h>
#include "ALGraphDFS.h"

int main() {
    ALGraph graph;
    GraphInit(&graph, 7); // 정점의 수가 7개인 graph 생성

    AddEdge(&graph, A, B);
    AddEdge(&graph, A, D);
    AddEdge(&graph, B, C);
    AddEdge(&graph, D, C);
    AddEdge(&graph, D, E);
    AddEdge(&graph, E, F);
    AddEdge(&graph, E, G);

    ShowGraphEdgeInfo(&graph);

    DFShowGraphVertex(&graph, A); printf("\n");
    DFShowGraphVertex(&graph, D); printf("\n");
    DFShowGraphVertex(&graph, E); printf("\n");

    GraphDestroy(&graph);
    return 0;
    
}