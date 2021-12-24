#include <stdio.h>

typedef struct _empInfo {
    int empNum; // 직원의 고유번호. 즉, Table의 Key
    int age; // 직원의 나이. 즉, Table의 Value
} EmpInfo;

int GetHashValye(int empNum) {
    return empNum % 100;
} // 여덟 자리의 수로 이뤄진 직원의 고유번호를 두자리 수로 변경할 수 있다.

int main() {
    EmpInfo empInfoArr[100]; // 100명의 피고용인 데이터를 저장한다.

    EmpInfo emp1 = {20120003, 42};
    EmpInfo emp2 = {20130074, 33};
    EmpInfo emp3 = {20160019, 27};

    EmpInfo r1, r2, r3;

    // Key인 empNum을 인덱스 값으로 이용해서 저장.
    // 24번 행의 경우, empInfoArr[3]에 emp1의 data가 저장된다.
    // 만약 직원수가 100명이 넘어 103번째 직원이 들어오면, "충돌(collision)"이 생긴다. 
    empInfoArr[GetHashValue(emp1.empNum)] = emp1;
    empInfoArr[GetHashValue(emp2.empNum)] = emp2;
    empInfoArr[GetHashValue(emp3.empNum)] = emp3;

    r1 = empInfoArr[GetHashValue(20120003)];

    printf("Emp Num : %d, Age : %d \n", r1.empNum, r1.age);

    return 0;
}