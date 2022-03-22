#include <cstdio>
#define DIV 1000000007
#define MAX 100

void tc();

int main() {
    int C;
    scanf(" %d\n", &C);
    for (int i = 0; i < C; i++) {
        tc();
    }
    return 0;
}

void tc() {
    int n;
    scanf(" %d", &n);
    int dp[MAX + 1];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
        dp[i] = (dp[i-1] + dp[i-2]) % DIV;
    }
    printf("%d\n", dp[n]);
}