#include <iostream>
#include <cstring>
#define MAX 1000000
#define DIV 1000000009

using namespace std;

int dp[MAX + 1];
int tc();

int main() {
    int T;
    memset(dp, -1, sizeof(dp));
    scanf(" %d", &T);
    for (int i = 0; i < T; ++i) {
        printf("%d\n", tc());
    }
    return 0;
}

int tc() {
    int n;
    scanf(" %d", &n);

    if (dp[n] != -1)
        return dp[n];

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
        dp[i] = ((dp[i-1] + dp[i-2]) % DIV + dp[i-3]) % DIV;
    }
    return dp[n];
}