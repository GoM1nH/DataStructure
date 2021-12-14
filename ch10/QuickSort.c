#include <stdio.h>

void Swap(int arr[]. int idx1, int idx2) { // 그냥 Swap함수

    int temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;

}

int Partition(int arr[], int left, int right) {

    int pivot = arr[left]; // pivot은 가장 왼쪽의 data
    int low = left+1; // low는 pivot을 제외한 가장 왼쪽의 data
    int high = right; // high은 pivot을 제외한 가장 오른쪽의 data

    while (high >= low) { // high과 low가 교차되기 전까진 반복
        
        while (arr[low] <= pivot && low <= right) { // low의 데이터가 pivot보다 우선순위가 낮은 데이터를 만날 때 까지
            low++; // low를 우측으로 하나씩 옮긴다
        }

        while (arr[high] >= pivot && high >= (left+1)) { // high의 데이터가 pivot보다 우선순위가 높은 데이터를 만날 때 까지.
        // left + 1은 pivot을 제외시키기 위해.
            high--; // high를 좌측으로 하나씩 옮긴다
        }

        if (low <= high) { // 만약 low와 high이 교차되지 않은 상태에서 위의 두 while문을 탈출하게된다면
            Swap(arr, low, high); // low와 high을 서로 swap
        }
    }

    Swap(arr, left, high); // pivot과 high이 가리키는 대상 교환
    return high; // 옮겨진 pivot의 위치정보 반환
}

void QuickSort(int arr[], int left, int right) {
    if (left <= right) {
        int pivot = Partition(arr, left, right);

        QuickSort(arr, left, pivot-1); // 재귀적 표현. pivot의 좌측 영역 정렬
        QuickSort(arr, pivot+1, right); // 재귀적 표현. pivot의 우측 영역 정렬
    }
}

int main() {

    int arr[7] = {3, 2, 4, 1, 7, 6, 5};
    
    int len = sizeof(arr) / sizeof(int);
    int i;

    QuickSort(arr, 0, len-1);

    for (i=0 ; i<len ; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}