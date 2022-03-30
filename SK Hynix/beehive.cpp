#include <iostream>
#define MAX_N 100

using namespace std;

int main() {
    int n;
    int arr[MAX_N][MAX_N] = {0, };
    scanf(" %d", &n);
    if (n % 2 == 0) {
        printf("n은 홀수여야 합니다.");
        return 0;
    }

    int k = n;
    int y = 0;
    int x = k / 2;
    int num = 1;

    while (k > 1) {
        for (int i = 0; i < (k - 1) / 2; ++i) {
            arr[y][x] = num++;
            y += 1; x += 1;
        }
        for (int i = 0; i < (k - 1) / 2; ++i) {
            arr[y][x] = num++;
            y += 1; x -= 1;
        }
        for (int i = 0; i < (k - 1) / 2; ++i) {
            arr[y][x] = num++;
            y += 0; x -= 1;
        }
        for (int i = 0; i < k - 1; ++i) {
            arr[y][x] = num++;
            y -= 1; x += 0;
        }
        for (int i = 0; i < (k - 1) / 2 - 1; ++i) {
            arr[y][x] = num++;
            y += 0; x += 1;
        }
        arr[y][x] = num++;
        k -= 2;
        y += 1; x += 1;
    }
    arr[y][x] = num;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    y = 0;
    x = n / 2;
    int half = (n + 1) / 2;
    for (; y < half; y++) {
        for (int j = x; j >= 0; j--) {
            printf("%d ", arr[y][j]);
        }
        x += 1;
    }
    x -= 2;
    for (; y < n; y++) {
        for (int j = x; j >= 0; j--) {
            printf("%d ", arr[y][j]);
        }
        x -= 1;
    }

    return 0;
}