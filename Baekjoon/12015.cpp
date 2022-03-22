#include <iostream>
#define MAX 1000000

using namespace std;

int N, A[MAX], lis[MAX];

int lowerBound(int e, int x) {
    int s = 0;
    while (s <= e) {
        int m = (s + e) / 2;
        if (lis[m] == x)
            return m;
        else if (lis[m] > x)
            e = m - 1;
        else
            s = m + 1;
    }
    return s;
}

int main() {
    scanf(" %d", &N);

    int maxLen = -1;
    for (int i = 0; i < N; ++i) {
        scanf(" %d", A + i);
        int idx = lowerBound(maxLen, A[i]);
        lis[idx] = A[i];
        maxLen = max(maxLen, idx);
    }
    printf("%d", maxLen + 1);
    return 0;
}