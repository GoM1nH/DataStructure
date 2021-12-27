#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table2.h"

int MyHashFunc(int k) {
    return k % 100;
}

int main() {
    Tabule myTbl;
    Person *np;
    Person *sp;
    Person *rp;

    TBLInit(&myTbl, MyHashFunc);

    // 데이터 추가
    np = MakePersonData(900254, "Lee", "Seoul");
    TBLInsert(&myTbl, GetSSN(np), np);

    // 데이터 탐색
    sp = TBLSearch(&myTbl, 900254);
    if (sp != NULL) {
        ShowPerInfo(sp);
    }

    // 데이터 삭제
    rp = TBLDelete(&myTbl, 900254);
    if (rp != NULL) {
        free(rp);
    }

    return 0;
}