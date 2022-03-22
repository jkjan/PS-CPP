#include <iostream>
#define MAX 1000

using namespace std;

int N, A[MAX + 1], dp[MAX + 1];

int getDp(int i) {
    int &ret = dp[i];
    if (ret == -1) {
        ret = 1;
        for (int j = i + 1; j <= N; ++j) {
            if (A[j] < A[i]) {
                ret = max(ret, getDp(j) + 1);
            }
        }
    }
    return ret;
}

int main() {
    scanf(" %d", &N);
    A[0] = 1001;
    dp[0] = -1;
    for (int i = 1; i <= N; ++i) {
        dp[i] = -1;
        scanf(" %d", A + i);
    }
    printf("%d", getDp(0) - 1);
    return 0;
}