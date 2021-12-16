#include <stdio.h>
#include "BSearchTree.h"

int main() {
    BTreeNode *bstRoot;
    BTreeNode *sNode;

    BSTMakeAndInit(&bstRoot);

    BSTInsert(&bstRoot, 9);
    BSTInsert(&bstRoot, 1);
    BSTInsert(&bstRoot, 3);
    BSTInsert(&bstRoot, 6);
    BSTInsert(&bstRoot, 5);
    BSTInsert(&bstRoot, 4);
    BSTInsert(&bstRoot, 2);
    BSTInsert(&bstRoot, 8);

    sNode = BSTSearch(bstRoot, 6);

    if(sNode == NULL) {
        printf("fail\n");
    } else {
        printf("key : %d", BSTGetNodeData(sNode));
    }

    return 0;
}