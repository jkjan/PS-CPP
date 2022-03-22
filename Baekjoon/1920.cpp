#include <cstdio>
#include <vector>
#define MAX 100000

using namespace std;


void merge(int *arr, int leftStart, int leftEnd, int rightStart, int rightEnd) {
    int start = leftStart;
    int len = rightEnd - leftStart + 1;
    int *tempArr = new int[len];
    int k = 0;
    while (leftStart <= leftEnd && rightStart <= rightEnd) {
        if (arr[leftStart] < arr[rightStart]) {
            tempArr[k++] = arr[leftStart++];
        }
        else {
            tempArr[k++] = arr[rightStart++];
        }
    }
    while (leftStart <= leftEnd)
        tempArr[k++] = arr[leftStart++];
    while (rightStart <= rightEnd)
        tempArr[k++] = arr[rightStart++];

    for (int i = 0; i < len; ++i) {
        arr[start + i] = tempArr[i];
    }
    delete[] tempArr;
}

void mergeSort(int *arr, int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        mergeSort(arr, s, m);
        mergeSort(arr, m + 1, e);
        merge(arr, s, m, m + 1, e);
    }
}

bool isIN(int *arr, int x, int s, int e) {
    while (s <= e) {
        int m = (s + e) / 2;
        if (arr[m] == x)
            return true;
        else if (arr[m] > x) {
            e = m - 1;
        }
        else {
            s = m + 1;
        }
    }
    return false;
}


int main() {
    int N, M, A[MAX];
    scanf(" %d", &N);
    for (int i = 0; i < N; ++i) {
        scanf(" %d", A + i);
    }

    mergeSort(A, 0, N-1);

    scanf(" %d", &M);
    for (int i = 0; i < M; ++i) {
        int x;
        scanf(" %d", &x);
        printf("%d\n", isIN(A, x, 0, N-1));
    }

    return 0;
}

