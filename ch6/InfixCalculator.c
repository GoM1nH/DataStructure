#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h"
#include "Calculate.h"

int EvalInfixExp(char exp[]) { // 계산기의 모든 과정을 통틀어서 포함해놓은 함수
    int len = strlen(exp); // 수식의 길이
    int ret; // 계산 결과를 저장할 변수
    char *expcpy = (char*)malloc(len+1); // 문자열 저장공간 마련
    strcpy(expcpy,exp);

    ConvToPost(expcpy); // 수식을 후위표기법으로 변환
    ret = CalculateExp(expcpy); // 변수 ret에 후위표기법으로 바뀐 수식의 계산 결과 저장

    free(expcpy);
    return ret; // ret 반환
}