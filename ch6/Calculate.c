#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "Calculate.h"

int CalculateExp(char exp[]) { // 후위표기법으로 변환된 수식 계산
    Stack stack;
    int expLen = strlen(exp);
    int i;
    char tok, op1, op2;

    StackInit(&stack);

    for(i=0 ; i<expLen ; i++) {
        tok = exp[i];
        if (isdigit(tok)) {
            SPush(&stack, tok-'0');
        } else {
            op1 = SPop(&stack);
            op2 = SPop(&stack);

            switch(tok) {
                case '+' :
                SPush(&stack, op1 + op2);
                break;
                case '-' :
                SPush(&stack, op1 - op2);
                break;
                case '*' :
                SPush(&stack, op1 * op2);
                break;
                case '/' :
                SPush(&stack, op1 / op2);
                break;
            }
        }
    }

    return SPop(&stack);
}