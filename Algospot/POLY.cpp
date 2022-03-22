#include <cstdio>
#include <cstring>

#define MAX 100
#define DIV 10000000

void tc();

int main() {
    int C;
    scanf(" %d\n", &C);
    for (int i = 0; i < C; i++) {
        tc();
    }
    return 0;
}

int dp[MAX + 1][MAX + 1];

int poly(int n, int lineCnt) {
    if (n - lineCnt == 0) return (dp[n][lineCnt] = 1);
    int &ret = dp[n][lineCnt];
    if (ret == -1) {
        ret = 0;
        for (int nextCnt = 1; nextCnt <= n - lineCnt; ++nextCnt) {
            int cases = lineCnt == 0 ? 1 : lineCnt + nextCnt - 1;
            cases = (cases * poly(n - lineCnt, nextCnt)) % DIV;
            ret = (ret + cases) % DIV;
        }
    }
    return ret;
}

void tc() {
    int n;
    scanf(" %d", &n);
    memset(dp, -1, sizeof(dp));
    printf("%d\n", poly(n, 0));
}