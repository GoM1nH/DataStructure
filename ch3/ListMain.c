#include <stdio.h>
#include "ArrayList.h"

int main() {

    // ArrayList인 "list"를 생성하고, 초기화하는 과정
    List list;
    int data;
    ListInit(&list);

    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33); // data save (5개)

    printf("Current Data Count : %d \n", LCount(&list)); //data 출력, ArrayList.h에 저장한 LCount 함수 응용

    if (LFirst(&list, &data)) { //첫 번째 데이터 조회
        printf("%d ", data);

        while(LNext(&list, &data)) printf("%d ", data); // 두 번째 이후 데이터 조회
    }
    
    printf("\n\n");

    if(LFirst(&list, &data)) {
        if (data == 22) LRemove(&list); // 리스트의 첫 번째 데이터가 22일시, 삭제

        while(LNext(&list, &data)) { //두 번째 이후 데이터가 22일 때 삭제
            if (data == 22) LRemove(&list);
        }
    } // List에 있는 데이터 '22' 전부 삭제

    printf("Current Data Count : %d \n", LCount(&list));

    if(LFirst(&list, &data)) {
        printf("%d ", data);

        while(LNext(&list, &data)) printf("%d ", data);
    }

    printf("\n\n");
}
