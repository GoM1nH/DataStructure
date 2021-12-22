#ifndef __BSTAVL_H__
#define __BSTAVL_H__

#include "BTavl.h"

typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode **pRoot);

BSTData BSTGetNodeData(BTreeNode *bst);

void BSTInsert (BTreeNode **pRoot, BSTData data);

BTreeNode *BSTSearch(BTreeNode *bst, BSTData target);

BTreeNode * BSTSearch(BTreeNode *bst, BSTData target);

BTreeNode *BSTRemove(BTreeNode ** pRoot, BSTData atrget);

void BSTShowALL(BTreeNode * bst);

#endif