// 이 코드를 실행하려면 RealHeap.h의 typedef char HData 를 typedef char *HData 로 바꿔주어야 한다.
// 문자열을 받기 때문에, 포인터를 통해 주소에 간접적으로 접근하여야함.

#include <stdio.h>
#include <string.h>
#include "RealHeap.h"

int DataPriorityComp (char *ch1, char *ch2) {
    return strlen(ch2) - strlen(ch1);
} // 만약 (A, B) 가 비교된다면, A가 B보다 우선순위가 높으므로 ch2 - ch1값이 양수가 나온다. 아스키 코드 값으로 비교함.

int main() {

    Heap heap;
    HeapInit(&heap, DataPriorityComp);

    HInsert(&heap, 'Hello');
    HInsert(&heap, 'How are you?');
    HInsert(&heap, 'I am fine, Thank you');
    printf("%s \n", HDelete(&heap));

    HInsert(&heap, 'A');

    while(!HIsEmpty(&heap)) {
        printf("%s \n", HDelete(&heap));
    }

    return 0;

}