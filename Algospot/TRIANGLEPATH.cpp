#include <cstdio>
#include <cstring>
#define MAX 100
#define max(a, b) (a > b ? a : b)

void tc();

int main() {
    int C;
    scanf(" %d", &C);
    for (int i = 0; i < C; ++i) {
        tc();
    }
}

void tc() {
    int n;
    scanf(" %d", &n);
    int triangle[MAX + 1][MAX + 1];
    int dp[MAX + 1][MAX + 1];
    memset(triangle, 0, sizeof(triangle));
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            scanf(" %d", &triangle[i][j]);
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
        }
    }

    int total = 0;
    for (int i = 1; i <= n; ++i) {
        if (total < dp[n][i])
            total = dp[n][i];
    }

    printf("%d\n", total);
}