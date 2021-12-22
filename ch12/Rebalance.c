#include <stdio.h>
#include "BTavl.h"

int GetHeight(BTreeNode *bst) { // for 트리 높이 Check.
    int leftH;
    int rightH;

    if (bst == NULL) {
        return 0;
    }

    leftH = GetHeight(GetLeftSubTree(bst));
    rightH = GetHeight(GetRightSubTree(bst));

    if (leftH > rightH) {
        return leftH + 1;
    } else {
        return rightH + 1;
    }
}

int GetHeightDiff(BTreeNode *bst) {
    int lsh; // Left Subtree Height.
    int rsh;

    if (bst == NULL) {
        return 0;
    }

    lsh = GetHeight(GetLeftSubTree(bst));
    rsh = GetHeight(GetRightSubTree(bst));
    return lsh - rsh // 균형인수 계산결과 반환함
}

BTreeNode * LLturn(BTreeNode *bst) {

    BTreeNode *pNode;
    BTreeNode *cNode;

    pNode = bst;
    cNode = GetLeftSubTree(pNode);

    ChangeLeftSubTree(pNode, GetRightSubTree(cNode)); // cNode의 오른쪽 자식 노드를 pNode의 왼쪽 자식 노드로 붙임
    ChangeRightSubTree(cNode, pNode); // cNode의 오른쪽 자식 노드가 pNode가 됨

    return cNode; // 회전으로 인해 변경된 루트노드의 주소 값을 반환한다.
}

BTreeNode * RRturn(BTreeNode *bst) {

    BTreeNode *pNode;
    BTreeNode *cNode;

    pNode = bst;
    cNode = GetRightSubTree(pNode);

    ChangeRightSubTree(pNode, GetLeftSubTree(cNode)); // cNode의 왼쪽 자식 노드를 pNode의 오른쪽 자식 노드로 붙임
    ChangeLeftSubTree(cNode, pNode); // cNode의 왼쪽 자식 노드가 pNode가 됨

    return cNode; // 회전으로 인해 변경된 루트노드의 주소 값을 반환한다.
}

BTreeNode *LRturn(BTreeNode *bst) {

    BTreeNode *pNode;
    BTreeNode *cNode;

    pNode = bst;
    cNode = GetLeftSubTree(bst);

    ChangeLeftSubTree(pNode, RRturn(cNode));
    return LLturn(pNode); // LR회전의 결과로 바뀐 루트 노드의 주소값을 반환함
}

BTreeNode *LRturn(BTreeNode *bst) {

    BTreeNode *pNode;
    BTreeNode *cNode;

    pNode = bst;
    cNode = GetRightSubTree(bst);

    ChangeRightSubTree(pNode, LLturn(cNode));
    return RRturn(pNode); // LR회전의 결과로 바뀐 루트 노드의 주소값을 반환함
}

BTreeNode *Rebalance(BTreeNode ** pRoot) {
    
    int hDiff = GetRightSubTree(*pRoot);

    // 균형 인수가 +2 이상일 때, 즉 LL / LR 불균형 상태일 때
    if (hDiff > 1) {
        if(GetHeightDiff(GetLeftSubTree(*pRoot)) > 0) { // LL
            *pRoot = LLturn(*pRoot);
        } else { // LR
            *pRoot = LRturn(*pRoot);
        }
    }

    // 균형 인수가 -2 이하일 때, 즉 RR / RL 불균형 상태일 때
    if (hDiff < -1) {
        if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0) { // RR
            *pRoot = RRturn(*pRoot);
        } else { // RL
            *pRoot = RLturn(*pRoot);
        }
    }

}