#include <iostream>
#define MAX 1000000

using namespace std;

int main() {
    int N, dp[MAX + 1];
    scanf(" %d", &N);
    dp[1] = 0;
    for (int i = 2; i <= N; ++i) {
        int &next = dp[i] = N + 1;
        if (i % 3 == 0)
            next = min(next, dp[i / 3] + 1);
        if (i % 2 == 0)
            next = min(next, dp[i / 2] + 1);
        if (i > 1)
            next = min(next, dp[i - 1] + 1);
    }
    printf("%d", dp[N]);
    return 0;
}