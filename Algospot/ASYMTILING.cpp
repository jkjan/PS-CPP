#include <cstdio>
#define MAX 100
#define DIV 1000000007

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
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i) {
        dp[i] = (dp[i-1] + dp[i-2]) % DIV;
    }

    int answer;
    if (n % 2 == 0) {
        printf("%d %d\n", n, dp[n]);
        printf("%d %d\n", (n-2)/2, dp[(n-2)/2]);
        printf("%d %d\n", n/2, dp[n/2]);

        answer = dp[n] - dp[(n-2)/2] - dp[n/2];
    }
    else {
        answer = dp[n] - dp[(n-1)/2];
    }
    answer %= DIV;
    printf("%d\n", answer);
}