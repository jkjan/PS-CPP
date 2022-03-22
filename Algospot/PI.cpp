#include <cstdio>
#include <cstring>
#include <climits>

#define MAX 10000
#define maxx(a, b) (a > b ? b : a)
#define max(a, b, c) maxx(maxx(a, b), c)

int dp[MAX + 3];
int arr[MAX + 3];
void tc();
int getDifficulty(int, int);

int main() {
    int C;
    scanf(" %d\n", &C);
    for (int i = 0; i < C; i++) {
        tc();
    }
    return 0;
}

void tc() {
    int i = 3;
    char s[MAX];
    scanf(" %s", s);
    int len = strlen(s);
    for (; i < len + 3; ++i) {
        arr[i] = s[i-3] - '0';
    }

    dp[3] = dp[4] = 100001;
    for (int j = 5; j < i; ++j) {
        dp[j] = max(dp[j-3] + getDifficulty(j-2, j),
                    dp[j-4] + getDifficulty(j-3, j),
                    dp[j-5] + getDifficulty(j-4, j));
    }
    printf("%d\n", dp[i-1]);
}

int getDifficulty(int s, int e) {
    if (s < 3)
        return INT_MAX;

    int r1 = arr[s + 1] - arr[s];
    int r2 = arr[s + 2] - arr[s + 1];
    int difficulty;
    if (r1 == r2 and r1 == 0)
        difficulty = 1;
    else if (r1 == r2 and (r1 == -1 or r1 == 1))
        difficulty = 2;
    else if (r1 == -r2)
        difficulty = 4;
    else if (r1 == r2)
        difficulty = 5;
    else
        return 10;

    int r = r2;
    if (difficulty == 4)
        r *= -1;

    for (int i = s + 2; i < e; ++i) {
        int newR = arr[i + 1] - arr[i];
        if (newR != r)
            return 10;
        if (difficulty == 4)
            r *= -1;
    }

    return difficulty;
}