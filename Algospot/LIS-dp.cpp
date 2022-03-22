#include <cstdio>
#include <algorithm>

#define MAX 500
using namespace std;

int arr[MAX];
int dp[MAX];
void tc();

int main() {
    int C;
    scanf(" %d", &C);
    for (int i = 0; i < C; ++i) {
        tc();
    }
    return 0;
}

void tc() {
    int N;
    scanf(" %d", &N);
    for (int i = 0; i < N; ++i) {
        scanf(" %d", arr + i);
    }

    int maxLen = 0;
    for (int i = 0; i < N; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                if (maxLen < dp[i])
                    maxLen = dp[i];
            }
        }
    }

    printf("%d\n", maxLen);
}