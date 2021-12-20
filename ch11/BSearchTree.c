#include <stdio.h>

#include "BT11.h"
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

BTreeNode *BSTSearch(BTreeNode *bst, BSTData target) { // 트리 안에서 target이 저장된 노드 탐색
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

BTreeNode *BSTRemove(BTreeNode ** pRoot, BSTData atrget) {
    BTreeNode *pVRoot = MakeBTreeNode(); // 가상 루트 노드
    BTreeNode *pNode = pVRoot;
    BTreeNode *cNode = *pRoot;
    BTreeNode *dNode;

    // 루트 노드를 pVRoot가 가리키는 노드의 우측 자식 노드가 되게 함.
    ChangeRightSubTree(pVRoot, *pRoot);

    while(cNode != NULL && GetData(cNode) != target) { // 삭제 대상 노드 탐색
        pNode = cNode;
        
        if (target < GetData(cNode)) {
            cNode = GetLeftSubTree(cNode);
        } else {
            cNode = GetRightSubTree(cNode);
        }
    } // while문 탈출시, pNode에는 삭제할 노드의 부모 노드가, cNode엔 삭제 대상이 저장된다.

    if (cNode == NULL) { // 삭제 대상이 없다면
        return NULL;
    }

    dNode = cNode;

    // 1st case : 삭제 대상이 단말 노드다.
    if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) {
        if(GetLeftSubTree(pNode) == dNode) {
            RemoveLeftSubTree(pNode);
        } else {
            RemoveRightSubTree(pNode);
        }
    }

    // 2nd case : 삭제 대상이 하나의 자식 노드를 갖는다.

    else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) {
        
        BTreeNode * dcNode; // 삭제 대상의 자식 노드

        if (GetLeftSubTree(dNode) != NULL) { // 삭제할 대상의 왼쪽에 자식노드가 있다면
            dcNode = GetLeftSubTree(dNode);
        } else {
            dcNode = GetRightSubTree(dNode);
        }

        if (GetLeftSubTree(pNode) == dNode) { // "삭제할 대상의 부모 노드"의 왼쪽 노드가 삭제할 대상이라면
            ChangeLeftSubTree(pNode, dcNode); // pNode의 왼쪽 서브트리에 dcNode를 이어준다.
        } else {
            ChangeRightSubTree(pNode, dcNode);
        }
    }

    // 3rd case : 삭제 대상이 두 개의 자식노드를 갖는다.
    else {
        BTreeNode * mNode = GetRightSubTree(dNode); // 대체 노드
        BTreeNode * mpNode = dNode;
        int delData;

        // 삭제 대상(dNode)의 대체 노드(mNode) 검색
        while (GetLeftSubTree(mNode) != NULL) {
            mpNode = mNode;
            mNode = GetLeftSubTree(mNode);
        }

        // 대체 노드(mNode)에 저장된 값을 삭제할 노드에 대입
        delData = GetData(mNode); // 백업
        SetData(dNode, GetData(mNode));

        // 대체 노드의 부모 노드와 자식 노드를 연결
        if (GetLeftSubTree(mpNode) == mNode) { // 만약 대체 노드(mNode)가 삭제 대상의 왼쪽에 있다면
            ChangeLeftSubTree(mpNode, GetRightSubTree(mNode)); // 대체할 노드의 자식 노드를 부모 노드의 왼쪽에 연결
        } else {
            ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
        }

        dNode = mNode; // 대체 노드를 삭제 노드 위치에 집어넣고
        SetData(dNode, delData); // 백업데이터(delData)를 복원한다.
    }


    // 만약 삭제된 노드가 루트노드라면
    if(GetRightSubTree(pVRoot) != *pRoot) {
        *pRoot = GetRightSubTree(pVRoot);
    }

    free(pVRoot);
    return dNode;
}

void ShowIntData(int data) {
    printf("%d ", data);
}

void BSTShowALL(BTreeNode * bst) {
    InorderTraverse(bst, ShowIntData);
}