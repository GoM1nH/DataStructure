#include <stdio.h>

void BubbleSort (int arr[], int num) {

    int i, j;

    for (i=0 ; i<num-1 ; i++) {
        for (j=0 ; j<(num-i)-1 ; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void SelSort (int arr[], int num) {
    
    int i, j;
    int temp, idx;

    for (i=0 ; i<num-1 ; i++) {

        idx = i;

        for (j=i+1 ; j<num ; j++) {
            if (arr[j] < arr[idx]) {
                idx = j;
            }
        }

        temp = arr[idx];
        arr[idx]=arr[i];
        arr[i]=temp;
    }
}

void InsertsionSort(int arr[], int num) {
    int i, j;
    int insData; // 정렬 대상을 여기에 저장

    for (i=1 ; i<n ; i++) {
        insData = arr[i];

        for (j=i-1 ; j>=0 ; j--) { //정렬이 완료된 영역의 다음에 위치한 데이터가 정렬대상이기에, j=i-1임.
            if (arr[j] > insData) {
                arr[j+1] = arr[j];
            } else {
                break;
            }

            arr[j+1] = insData;
        }
    }
}