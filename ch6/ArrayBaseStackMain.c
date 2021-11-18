#include <stdio.h>
#include "ArrayBaseStack.h"

int main () {
    Stack stack;
    StackInit(&stack);

    SPush(&stack, 1);
    SPush(&stack, 32);
    SPush(&stack, 782);

    while (!SIsEmpty(&stack)) {
        printf("%d ", SPop(&stack));
    } // 데이터를 꺼내면서 확인한다.

    return 0;
}