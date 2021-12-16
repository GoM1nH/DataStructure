#include <stdio.h>

#include "BinaryTree.h"
#include "BSearchTree.h"

void BSTMakeAndInit(BTreeNode **pRoot) {
    *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode *bst) {
    return GetData(bst);
}

void BSTInsert (BTreeNode **pRoot, BSTData data) { // 새 Node를 삽입하는 과정

    BTreeNode *pNode = NULL; // 부모노드
    BTreeNode *cNode = *pRoot; // 현재노드. 루트노드부터 내려간다
    BTreeNode *nNode = NULL; // 새로운 노드

    while (cNode != NULL) {
        if (data == GetData(cNode)) { // 중복 피한다. 키의 고유성 지키기 위해.
            return;
        }

        pNode = cNode; // 부모노드는 현재노드로.

        if (GetData(cNode) > data) { // 현재노드가 새 Node의 데이터보다 크다면
            cNode = GetLeftSubTree(cNode); // 현재노드의 위치를 부모노드의 왼쪽으로 내린다
        } else { // 현재노드가 새 Node의 데이터보다 작다면
            cNode = GetRightSubTree(cNode); // 현재노드의 위치를 부모노드의 오른쪽으로 내린다
        }
    } // 반복문을 탈출하면, 새 노드가 추가될 부모노드(pNode)가 정해질것이다.

    // pNode의 자식 노드로 추가할 새 노드 nNode 추가

    nNode = MakeBTreeNode(); // 새 노드 생성
    SetData(nNode, data); // 새 노드에 data 삽입

    if (pNode != NULL) { // 새 노드가 루트노드가 아니라면
        if (data < GetData(pNode)) {
            MakeLeftSubTree(pNode, nNode);
        } else {
            MakeRightSubTree(pNode, nNode);
        }
    } else { // 새 노드가 루트노드라면
        *pRoot = nNode;
    }
}

BTreeNode *BSTSearch(BTreeNode *bst, BSTData target) {
    BTreeNode *cNode = bst;
    BSTData cd; // current data

    while (cNode != NULL) {
        cd = GetData(cNode); // cd에 현재 노드의 데이터 넣음.

        if (target == cd) {
            return cNode;
        } else if (target < cd) {
            cNode = GetLeftSubTree(cNode);
        } else {
            cNode = GetRightSubTree(cNode);
        }
    }

    return NULL; // 탐색 대상이 없다
}
