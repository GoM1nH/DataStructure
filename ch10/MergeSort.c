#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea (int arr[], int left, int mid, int right) {
    int fIdx = left; // 왼쪽 영역 (left~mid) 의 첫 번째 위치 정보.
    int rIdx = mid+1 // 오른쪽 영역 (mid+1~right) 의 첫 번째 위치 정보.
    int i;

    int *sortArr = (int *)malloc(sizeof(int)*(right+1)); // 최종 결과 (정렬된 배열)을 동적할당 해준다.
    int sIdx = left; // sortArr 배열에 첫번째 요소부터 결과를 차곡차곡 정렬해야한다.

    while (fIdx <= mid && rIdx <= right) {
    // 좌 / 우측 영역의 데이터들을 비교한다.
    // 만약 좌측 영역의 데이터들을 전부 넣었으면 fIdx가 mid값을 넘어버려서 반복문 중지!!
    // 만약 우측 영역의 데이터들을 전부 넣었으면 ridx가 right값을 넘어버려서 반복문 중지!!
        if (arr[fIdx] <= arr[rIdx]) {
            sortArr[sIdx] = arr[fIdx++];
        } else {
            sortArr[sIdx] = arr[rIdx++];
        }

        sIdx++;
    }

    // 여기부터 사용하는 "남은 데이터"는 무조건 우선순위가 낮은 데이터들이 남게 된다. 그래서 크게 신경쓰지 말고 그냥 뒤에 넣자.

    if (fIdx > mid) { // If 좌측영역의 데이터들을 전부 넣었을 때, 남은 우측 데이터 넣기
        for (i=rIdx ; i<=right ; i++, sIdx++) {
            sortArr[sIdx] = arr[i];
        }
    } else { // If 우측영역의 데이터들을 전부 넣었을 때, 남은 좌측 데이터 넣기
        for (i=fIdx ; i<=mid ; i++, sIdx++) {
            sortArr[sIdx] = arr[i];
        }
    }

    for (i=left ; i <= tight ; i++) {
        arr[i] = sortArr[i];
    }

    free(sortArr);

}

void MergeSort (int arr[], int left, int right) { // left, right로 정렬의 "범위"를 지정해준다.
    
    int mid; // 배열의 중간의 index값.

    if (left<right) {
        mid = (left + right) / 2;

        MergeSort(arr, left, mid); // left ~ mid 까지를 다시 분할해준다.
        MergeSort(arr, mid+1, right); // mid 다음 위치인 mid+1 ~ right 까지를 다시 분할해준다.
        // 쭉-쭉 재귀적으로 나뉘어진다. 결과론적으론 모든 배열의 요소들이 하나씩 하나씩 다 분할될 것이다.

        MergeTwoArea(arr, left, mid, right);
        // 분할된 데이터들이 left~mid / mid+1~right 으로 나뉘어져 있으므로, 이를 결합해준다.
    }
} 