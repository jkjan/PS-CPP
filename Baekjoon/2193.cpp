#include <iostream>
#define MAX 90

using namespace std;

int main() {
    int N;
    scanf(" %d", &N);
    long long dp[MAX + 1][2];
    dp[1][0] = 0;
    dp[1][1] = 1;
    for (int i = 2; i <= N; ++i) {
        dp[i][1] = dp[i-1][0];
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
    }
    printf("%lld", dp[N][1] + dp[N][0]);
    return 0;
}