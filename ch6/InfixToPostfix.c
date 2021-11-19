#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "InfixToPostfix.h"
#include "ListBaseStack.h"

int GetOpPrec(char op) {
      switch(op) {
          case '*':
          case '/': return 4;
          case '+':
          case '-': return 3;
          case '(': return 1;
      }
      // return 뒤에 있는 값의 set 기준은, 그냥 우선순위가 높을수록 숫자가 크면 된다.
      // )가 GetOpPrec에서 return 값이 아예 존재하지 않는 이유는, ) 는 소괄호의 끝에 관한 메시지만 전달해주고 사라지기 때문이다.

      return -1; // 위 case들의 연산자에 속하지 않아있으면 -1 반환.
}

int WhoPrecOp(char op1, char op2) {
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);

    if (op1Prec > op2Prec) return 1; // op1이 op2보다 연산순위가 높을 때
    else if (op1Prec < op2Prec) return -1; // op1이 op2보다 연산순위가 낮을 때
    else return 0; // 또이또이
}

void ConvToPost(char exp[]) {

    Stack stack; //교재에서 접시같은 존재라 생각하자.
    int expLen = strlen(expLen); // 입력받은 수식의 길이 기억
    char *convExp = (char *)malloc(expLen+1); 

    int i, idx=0;
    char tok, pop0p;

    memset(convExp, 0, sizeof(char)*expLen+1); // 할당된 배열을 0으로 초기화한다.

    // void * memset(void *ptr, int val, size_t len) , ptr로 전달된 주소의 메모리부터 len 바이트를 val의 값으로 채운다. ctype.h에 있다.
    StackInit(&stack);

    for (i=0 ; i<expLen ; i++) {
        tok = exp[i]; // exp로 전달된 수식들을 한문자씩, tok에 저장한다
        if(isdigit(tok)) { // tok이 숫자라면,
        // int isdigit(int ch) , ch로 전달된 문자의 내용이 10진수라면 1을 반환한다. string.h.에 있다.
            convExp[idx++] = tok;            
        } else { // tok이 숫자가 아니라면,

            switch(tok) { // 연산자가 변수 tok에 저장되면, 이를 스택으로 옮기거나 or convExp로 바로 옮기기위한 문장임.
                case '(' : 
                SPush(&stack, tok);
                break;
                
                case ')' :
                while(1) {
                    pop0p = SPop(&stack);
                    if (pop0p == '(') break;
                    convExp[idx++] = pop0p;
                }
                break;
                
                case '+': case '-':
                case '*': case '/':
                while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0) {
                    // stack이 비었고 && stack에 들어가있는 연산자의 우선 순위가 tok보다 높거나 같으면
                    convExp[idx++] = SPop(&stack); // 후위 표기법으로 표현한 exp 배열에 연산자를 저장한다.
                }
                
                SPush(&stack, tok);
                break;
            }
        }
    }

    while (!SIsEmpty(&stack)) {
        convExp[idx++] = SPop(&stack);
    }

    strcpy(exp, convExp); // exp에 convExp, 즉 후위 표기법으로 표기된 수식을 저장한다
    free(convExp);
}