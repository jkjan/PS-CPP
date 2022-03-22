#include <iostream>
#include <cstring>
#define MAX 100
#define DIV 1000000000

using namespace std;

int N;
int dp[MAX][10];

int getDp(int i, int prev) {
    if (not (0 <= prev and prev < 10))
        return 0;
    if (i == N - 1)
        return 1;
    int &ret = dp[i][prev];
    if (ret == -1) {
        ret = (getDp(i + 1, prev - 1) + getDp(i + 1, prev + 1)) % DIV;
    }
    return ret;
}

int main() {
    scanf(" %d", &N);
    int cnt = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= 9; ++i) {
        cnt = (cnt + getDp(0, i)) % DIV;
    }
    printf("%d", cnt);
    return 0;
}