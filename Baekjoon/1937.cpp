#include <iostream>
#include <cstring>
#define MAX 500

using namespace std;

int n;
int woods[MAX][MAX];
int dp[MAX][MAX];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int getDp(int y, int x) {
    int &ret = dp[y][x];
    if (ret == -1) {
        ret = 1;
        for (int i = 0; i < 4; ++i) {
            int adjY = y + dy[i];
            int adjX = x + dx[i];
            if (0 <= adjY and adjY < n and 0 <= adjX and adjX < n) {
                if (woods[y][x] < woods[adjY][adjX]) {
                    ret = max(ret, getDp(adjY, adjX) + 1);
                }
            }
        }
    }
    return ret;
}

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf(" %d", &woods[i][j]);
        }
    }
    int maxWood = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            maxWood = max(maxWood, getDp(i, j));
        }
    }
    printf("%d", maxWood);
    return 0;
}