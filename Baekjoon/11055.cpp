#include <iostream>
#include <cstring>
#define MAX 1000

using namespace std;

int N, A[MAX + 1], dp[MAX + 1];


int getDp(int i) {
    int &ret = dp[i];
    if (ret == -1) {
        ret = A[i];
        int maxNext = 0;
        for (int j = i + 1; j <= N; ++j) {
            if (A[i] < A[j]) {
                maxNext = max(maxNext, getDp(j));
            }
        }
        ret += maxNext;
    }
    return ret;
}

int main() {
    scanf(" %d", &N);
    memset(dp, -1, sizeof(dp));
    A[0] = 0;
    for (int i = 1; i <= N; ++i) {
        scanf(" %d", A + i);
    }
    printf("%d", getDp(0));
    return 0;
}