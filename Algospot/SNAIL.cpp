#include <cstdio>
#include <cstring>
#define MAX 1000

void tc();

int main() {
    int C;
    scanf(" %d\n", &C);
    for (int i = 0; i < C; i++) {
        tc();
    }
    return 0;
}

int n, m;
double dp[2 * MAX][MAX];

double snail(int height, int day) {
    if (day == m)
        return height >= n ? 1 : 0;

    if (dp[height][day] == -1) {
        dp[height][day] = 0.75 * snail(height + 2, day + 1)
                        + 0.25 * snail(height + 1, day + 1);
    }
    return dp[height][day];
}

void tc() {
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < 2 * MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            dp[i][j] = -1;
        }
    }
    printf("%.10f\n", snail(0, 0));
}