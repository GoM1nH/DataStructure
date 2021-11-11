#include <stdio.h>
#include <stdlib.h>

typedef struct _node { // 구조체 NODE 선언. 각각의 Node에는 저장된 데이터와 다음 노드의 주소가 저장되어있다.
    int data;
    struct _node * next;
} Node;

int main() {
    Node *head = NULL; // Node의 머리부분
    Node *tail = NULL; // Node의 꼬리부분
    Node *cur = NULL; //current, 현재

    Node *newNode = NULL;
    int readData;

    head = (Node *)malloc(sizeof(Node));
    tail = head;

    while (1) {
        printf("INPUT NATURAL NUMBER : ");
        scanf("%d", &readData); // 저장하고자 하는 데이터를 readData에 입력
        if(readData < 1) break; // 만약 1미만의 수 ex) 0 을 입력하면 입력 종료.

        newNode = (Node *)malloc(sizeof(Node)); // 새로운 노드를 메모리 동적 할당해준다
        newNode->data = readData; // 노드의 head부분 (데이터가 저장되는 부분)에 입력한 숫자를 저장해줌
        newNode->next = NULL; // 다음 노드부분은 비워둔다.

        tail->next = newNode;
         
        tail = newNode;
    }

    printf("\n");

    if(head == tail) {
        printf("NO DATA \n"); // 저장된 데이터가 없음.
    } else {
        cur = head; // 현재 참조할 위치를 맨 처음 저장된 데이터인 head부분으로 초기화
        printf("%d", cur->data);

        while (cur->next != NULL) { // 데이터 하나가 아니라 이후에도 저장되어 있을때
            cur = cur->next; // 참조할 위치를 뒤로 한번 옮겨줌
            printf("%d ", cur->data); // 뒤로 옮겨진 위치에 있는 데이터 출력
        }
    }
    printf("\n\n");

    if (head == tail) {
        return 0;
    } else {
        Node *delNode = head; //참조할 위치를 맨 처음으로 옮겨줌
        Node *delNextNode = head->next;

        while (delNextNode != NULL) { //만약 다음 Node가 있을 때
            delNode = delNextNode; // A위치에 있는 데이터를 삭제했으면, A는 삭제했으므로 뒤에 있는 B로 타겟을 변경함
            delNextNode = delNextNode->next; // 그 다음에 삭제할 데이터인 C를 미리 타겟으로 설정

            free(delNode); // B를 지움
        }
    }

}