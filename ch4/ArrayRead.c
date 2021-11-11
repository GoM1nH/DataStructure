#include <stdio.h>

int main() {

    int arr[10];
    int readCount = 0;
    int readData;
    int i;

    while (1) {
        printf("INPUT NATURAL NUMBER : ");
        scanf("%d", &readData);
        if (readData < 1) break;

        arr[readCount++] = readData;
    }

    for (i=0 ; i<readCount ; i++) {
        printf("%d ", arr[i]);
    }

}