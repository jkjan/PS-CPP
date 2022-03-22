#include <iostream>
#include <cstring>
#define MAX 500

using namespace std;

int M, N;
int dp[MAX][MAX];
int map[MAX][MAX];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int dfs(int y, int x) {
    if (y == M-1 and x == N-1) {
        return 1;
    }

    if (dp[y][x] == -1) {
        dp[y][x] = 0;
        for (int i = 0; i < 4; ++i) {
            int adjY = y + dy[i];
            int adjX = x + dx[i];
            if (0 <= adjY and adjY < M and 0 <= adjX and adjX < N) {
                if (map[adjY][adjX] < map[y][x]) {
                    dp[y][x] += dfs(adjY, adjX);
                }
            }
        }
    }
    return dp[y][x];
}

int main() {
    scanf(" %d %d", &M, &N);
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf(" %d", &map[i][j]);
        }
    }
    memset(dp, -1, sizeof(dp));
    int answer = dfs(0, 0);
    printf("%d", answer);
    return 0;
}