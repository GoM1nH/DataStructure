#include <stdio.h>

int ISearch(int arr[], int first, int last, int target) {
    
    int mid;

    if (arr[first] > target || arr[last] < target) { // 탐색대상이 존재하지 않으면, 탐색대상의 값은 탐색범위의 값을 넘어감
        return -1;
    }

    mid = ((double)(target-arr[first]) / (arr[last]-arr[first]) * (last - first)) + first;
    // high은 배열의 마지막 값 idx, low는 배열의 처음 값 idx, s는 target data의 idx
    // mid의 값은 A : Q = arr[high] - arr[low] : arr[s] - arr[low] 에 기반함.

    if (arr[mid] == target) {
        return mid;
    } else if (target < arr[mid]) {
        return ISearch(arr, first, mid-1, target);
    } else {
        return ISearch(arr, mid+1, last, target);
    }

}

int main() {

    int arr[] = {1, 3, 5, 7, 9};
    int idx;

    idx = ISearch(arr, 0, sizeof(arr)/sizeof(int)-1, 7);

    if (idx == -1) {
        printf ("Search Fail\n");
    } else {
        printf("Target IDX : %d\n", idx);
    }

}