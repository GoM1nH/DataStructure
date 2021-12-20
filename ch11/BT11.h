#ifndef __B_T_11_H__
#define __B_T_11_H__

typedef int BTData;
typedef struct _bTreeNode {
    BTData data;
    struct _bTreeNode *left;
    struct _bTreeNode *right;
} BTreeNode;

BTreeNode *MakeBTreeNode(void); // (이진 트리)노드 생성, 호출시 노드를 동적 할당 및 초기화한 후, 그 주소값을 반환한다.
BTData GetData (BTreeNode *bt); // 노드에 저장된 데이터를 반환
void SetData(BTreeNode *bt, BTData data); // 노드(*bt)에 데이터(data)를 저장

BTreeNode * RemoveLeftSubTree(BTreeNode *bt);
BTreeNode * RemoveRightSubTree(BTreeNode *bt);

void ChangeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void ChangeRightSubTree(BTreeNode * main, BTreeNode * sub);

BTreeNode *GetLeftSubTree(BTreeNode *bt); // bt의 왼쪽 Sub Tree의 주소 값을 반환한다
BTreeNode *GetRightSubTree(BTreeNode *bt); // bt의 오른쪽 Sub Tree의 주소 값을 반환한다

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub); // 두 번째 인자 sub로 전달된 Tree(or Node)를 첫 번째 인자 main으로 전달된 노드의 왼쪽 Sub Tree로 연결함.
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);

typedef void (VisitFuncPtr) (BTData data);

void InorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action);

void DeleteTree(BTreeNode *bt);

#endif