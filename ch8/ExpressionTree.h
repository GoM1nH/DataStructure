#ifndef __EXPRESSION_TREE_H__
#define __EXPRESSION_TREE_H__

#include "BinaryTree.h"

BTreeNode *MakeExpTree(char exp[]); // 수식트리 구성, 후위 문자열의 수식을 문자열로 받는다
int EvaluateExpTree(BTreeNode *bt); // 수식트리 계산

void ShowPrefix(BTreeNode *bt);
void ShowInfix(BTreeNode *bt);
void ShowPostfix(BTreeNode *bt);

#endif