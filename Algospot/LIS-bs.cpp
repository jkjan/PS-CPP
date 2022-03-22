#include <cstdio>
#include <cstring>

#define MAX 500

int N;
int arr[MAX];
int lis[MAX];

void tc();
int lowerBound(int, int);

int main() {
    int C;
    scanf(" %d", &C);
    for (int i = 0; i < C; ++i) {
        tc();
    }
    return 0;
}

void tc() {
    scanf(" %d", &N);
    for (int i = 0; i < N; ++i) {
        scanf(" %d", arr + i);
    }
    memset(lis, 0, sizeof(lis));

    int maxLen = -1;
    for (int i = 0; i < N; ++i) {
        int idx = lowerBound(maxLen, arr[i]);
        lis[idx] = arr[i];
        if (maxLen < idx)
            maxLen = idx;
    }
    printf("%d\n", maxLen + 1);
}

int lowerBound(int e, int x) {
    int s = 0;
    while (s <= e) {
        int m = (s + e) / 2;
        if (lis[m] < x) {
            s = m + 1;
        }
        else if (lis[m] == x) {
            return m;
        }
        else {
            e = m - 1;
        }
    }
    return s;
}