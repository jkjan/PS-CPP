#include <iostream>
#include <cstring>
#define MAX 1500000

using namespace std;

int N;
int T[MAX], P[MAX], dp[MAX];

int getDp(int i) {
    if (i >= N)
        return 0;

    int &ret = dp[i];
    if (ret == -1) {
        int did = 0;
        if (i + T[i] <= N) {
            did += P[i] + getDp(i + T[i]);
        }

        int didnt = getDp(i + 1);
        dp[i] = max(did, didnt);
    }
    return ret;
}

int main() {
    scanf(" %d", &N);
    for (int i = 0; i < N; ++i) {
        scanf(" %d %d", T + i, P + i);
    }
    memset(dp, -1, sizeof(dp));
    printf("%d", getDp(0));
    return 0;
}