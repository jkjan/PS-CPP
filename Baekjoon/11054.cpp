#include <iostream>
#include <cstring>
#define MAX 1000

using namespace std;

int N, A[MAX + 1], dp[2][MAX + 1];

int getDp(int inc, int i) {
    int &ret = dp[inc][i];
    if (ret == -1) {
        ret = 1;
        for (int j = i + 1; j <= N; ++j) {
            if (inc) {
                if (A[i] < A[j])
                    ret = max(ret, 1 + getDp(true, j));
                else if (A[i] > A[j])
                    ret = max(ret, 1 + getDp(false, j));
            }
            else if (A[i] > A[j])
                ret = max(ret, 1 + getDp(false, j));
        }
    }
    return ret;
}

int main() {
    scanf(" %d", &N);
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= N; ++i) {
        scanf(" %d", A + i);
    }

    A[0] = 0;
    printf("%d", getDp(true, 0) - 1);

    return 0;
}