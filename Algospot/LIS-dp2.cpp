#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAX 500 + 1
using namespace std;

int N;
int arr[MAX];
int dp[MAX];
void tc();
int lis(int);

int main() {
    int C;
    scanf(" %d", &C);
    for (int i = 0; i < C; ++i) {
        tc();
    }
    return 0;
}

void tc() {
    scanf(" %d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf(" %d", arr + i);
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", lis(0) - 1);
}

int lis(int start) {
    if (dp[start] == -1) {
        dp[start] = 1;
        for (int i = start + 1; i <= N; ++i) {
            if (arr[start] < arr[i]) {
                dp[start] = max(dp[start], lis(i) + 1);
            }
        }
    }
    return dp[start];
}