#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_N 100
#define MAX_W 1000
using namespace std;

void tc();

int main() {
    int C;
    scanf(" %d\n", &C);
    for (int i = 0; i < C; i++) {
        tc();
    }
    return 0;
}

int N, W;
int dp[MAX_N][MAX_W + 1];
int volume[MAX_N];
int desperate[MAX_N];

int getDp(int i, int capacity) {
    if (i >= N)
        return 0;
    int &ret = dp[i][capacity];
    if (ret == -1) {
        ret = getDp(i + 1, capacity);
        if (capacity - volume[i] >= 0)
            ret = max(ret, desperate[i] + getDp(i + 1, capacity - volume[i]));
    }
    return ret;
}

void reconstruct() {

}

void tc() {
    scanf(" %d %d", &N, &W);
    memset(dp, -1, sizeof(dp));
    char item[MAX_N][21];
    for (int i = 0; i < N; ++i) {
        scanf(" %s %d %d", item[i], volume + i, desperate + i);
    }
    int maxDesperate = getDp(0, W);
    int capacity = W;
    char backpack[MAX_N][21];
    int maxLen = 0;
    for (int i = 0; i < N - 1; ++i) {
        if (dp[i][capacity] != dp[i + 1][capacity]) {
            capacity -= volume[i];
            strcpy(backpack[maxLen++], item[i]);
        }
    }
    printf("%d %d\n", maxDesperate, maxLen);
    for (int i = 0; i < maxLen; ++i) {
        printf("%s\n", backpack[i]);
    }
}