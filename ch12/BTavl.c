#include <stdio.h>
#include <stdlib.h>
#include "BTavl.h"

BTreeNode *MakeBTreeNode(void) {
    BTreeNode *nd = (BTreeNode *)malloc(sizeof(BTreeNode));
    nd->left = NULL;
    nd->right = NULL;
    return nd; //nd의 주소값을 반환.
}

BTData GetData (BTreeNode *bt) {
    return bt->data;
}

void SetData(BTreeNode *bt, BTData data) {
    bt->data = data;
}

BTreeNode *GetLeftSubTree(BTreeNode *bt) {
    return bt->left;
}
BTreeNode *GetRightSubTree(BTreeNode *bt) {
    return bt->right;
}

BTreeNode * RemoveLeftSubTree(BTreeNode *bt) {
    BTreeNode * delNode;

    if (bt != NULL) {
        delNode = bt->left;
        bt->left = NULL;
    }

    return delNode;
}
BTreeNode * RemoveRightSubTree(BTreeNode *bt) {
    BTreeNode * delNode;

    if (bt != NULL) {
        delNode = bt->right;
        bt->right = NULL;
    }

    return delNode;
}

void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub) {
    main->left = sub;
}
void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub) {
    main->right = sub;
}

//MakeLeft.. 와 MakeRight.. 는 만약 SubTree를 새로 넣으려는 곳에 이미 Tree(or Node)가 있다면, 해당 Tree(or Node)는 삭제하고 새로운 sub를 넣어준다.
//만약 서브 트리가 두 개 이상의 노드로 이루어져 있다면, 모든 노드를 방문하여 free 함수를 호출해야 함. 이 과정을 "순회(Traversal)"라고 한다.
//순회는 별도의 과정이 존재함.

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub) {
    if (main->left != NULL) {
        free(main->left);
    }
    
    main->left = sub;
}
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub) {
    if (main->right != NULL) {
        free(main->right);
    }

    main->right = sub;
}

void InorderTraverse(BTreeNode *bt, VisitFuncPtr action) {
    if (bt == NULL) {
        return;
    }

    InorderTraverse(bt->left, action);
    action(bt->data);
    InorderTraverse(bt->right, action);
}
void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action) {
    if (bt == NULL) {
        return;
    }

    action(bt->data);
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);
}
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action) {
    if (bt == NULL) {
        return;
    }

    PostorderTraverse(bt->left, action);
    PostorderTraverse(bt->right, action);
    action(bt->data);
}

void DeleteTree(BTreeNode *bt) { // Postorder로 사용. root node가 마지막에 소멸되어야 하기 때문이다.

    if (bt == NULL) {
        return;
    }

    DeleteTree(bt->left);
    DeleteTree(bt->right);

    free(bt);

}

