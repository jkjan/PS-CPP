#include <cstdio>
#include <cstring>

#define FOR(a, b) for(int i = a; i < b; i++)

void tc();
bool isPossible(int, int);

int n;
int board[100][100];
int dp[100][100];

int main() {
    int C;
    scanf(" %d", &C);
    FOR(0, C) {
        tc();
    }
    return 0;
}

void tc() {
    scanf(" %d", &n);
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf(" %d", &board[i][j]);
        }
    }

    printf("%s\n", isPossible(0, 0) ? "YES" : "NO");
}

bool isPossible(int y, int x) {
    if (!(0 <= y and y < n and 0 <= x and x < n)) {
        return false;
    }
    else if (y == n - 1 and x == n - 1) {
        return true;
    }
    else if (dp[y][x] != -1) {
        return dp[y][x];
    }
    return dp[y][x] = isPossible(y + board[y][x], x) || isPossible(y, x + board[y][x]);
}