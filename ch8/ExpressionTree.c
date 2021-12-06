#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "BinaryTree.h"

BTreeNode *MakeExp(char exp[]) { // 후위수식을 문자열로 받아서 수식 트리 만들기
    Stack stack;
    BTreeNode *node;

    int expLen = sizeof(exp); // 수식 길이
    int i;

    StackInit(&stack); // 스택 쓰레기값 날려주고

    for (i=0 ; i<expLen ; i++) {
        node = MakeBTreeNode(); // 노드를 일단 하나 만든다
        
        if (isdigit(exp[i])) {
            SPush(node, exp[i]-'0'); // 만약 숫자라면, 노드에 숫자를 넣고 스택에 쌓아놓는다
        } else { // 만약 연산자라면, 스택에 쌓인 숫자 두개를 Right, Left Sub Tree로 놓고 그 위에 연산자를 넣는다. 그 다음 SubTree를 통째로 Stack에 쌓음
            MakeRightSubTree(node, SPop(&stack));
            MakeLeftSubTree(node, SPop(&stack));
            SetData(node, exp[i]);
        }

        SPush(&stack, node);

    }

    return SPop(&stack); // 완성된 Tree의 Root Node 주소값을 반환
}

int EvaluateExpTree(BTreeNode *bt) {
    int op1, op2;

    if (GetLeftSubTree(bt)==NULL && GetRightSubTree(bt) == NULL) { // 만약 단말노드라면
        return GetData(bt);
    }

    op1 = EvaluateExpTree(GetLeftSubTree(bt));
    op2 = EvaluateExpTree(GetRightSubTree(bt));

    switch(GetData(bt)) {
        case '+' :
            return op1 + op2;
        case '-' :
            return op1 - op2;
        case '*' :
            return op1 * op2;
        case '/' :
            return op1 / op2;
    }

    return 0;
}

void ShowNodeData(int data) { // 순회하며 각 노드 출력
    if (data>=0 && data<=9) { // 피연산자면 숫자출력
        printf("%d ", data);
    } else { // 연산자니 문자출력
        printf("%c ", data);
    }
}

void ShowPrefix(BTreeNode *bt) {
    PreorderTraverse(bt, ShowNodeData);
}

void ShowInfix(BTreeNode *bt) {
    if (bt == NULL) {
        return;
    }

    if (bt->left != NULL || bt->right != NULL) {
        printf("(");
    }

    ShowInfix(bt->left);
    ShowNodeData(bt->data);
    ShowInfix(bt->right);

    if (bt->left != NULL || bt->right != NULL) {
        printf(")");
    }
}

void ShowPostfix(BTreeNode *bt) {
    PostorderTraverse(bt, ShowNodeData);
}