#include <cstdio>
#include <cstring>
#define MAX 100
#define max(a, b) ((a) > (b) ? (a) : (b))

void tc();

int n;
int triangle[MAX][MAX];
int dp[MAX][MAX];
int count[MAX][MAX];

int getCount(int y, int x) {
    if (y == n-1)
        return 1;
    int &ret = count[y][x];
    if (ret == -1) {
        ret = 0;
        if (dp[y+1][x] >= dp[y+1][x+1])
            ret += getCount(y+1, x);
        if (dp[y+1][x] <= dp[y+1][x+1])
            ret += getCount(y+1, x+1);
    }
    return ret;
}

int getTriangle(int y, int x) {
    if (y == n)
        return 0;
    int &ret = dp[y][x];
    if (ret == -1) {
        ret = triangle[y][x] + max(getTriangle(y + 1, x), getTriangle(y + 1, x + 1));
    }
    return ret;
}

int main() {
    int C;
    scanf(" %d\n", &C);
    for (int i = 0; i < C; i++) {
        tc();
    }
    return 0;
}

void tc() {
    scanf(" %d", &n);

    memset(triangle, 0, sizeof(triangle));
    memset(count, -1, sizeof(count));
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            scanf(" %d", &triangle[i][j]);
        }
    }
    getTriangle(0, 0);
    printf("%d\n", getCount(0, 0));
}