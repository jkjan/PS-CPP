#include <cstdio>
#include <vector>
#define MAX_N 50
#define MAX_D 100
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

int d, p;
vector<int> graph[MAX_N];
double dp[MAX_D + 1][MAX_N];

double getDp(int day, int town) {
    double &ret = dp[day][town];
    if (day == 0) {
        ret = town == p;
    }
    if (ret == -1) {
        ret = 0;
        for (auto adj: graph[town]) {
            ret += getDp(day - 1, adj) / graph[adj].size();
        }
    }
    return ret;
}

void tc() {
    int n;
    scanf(" %d %d %d", &n, &d, &p);

    for (int i = 0; i < n; ++i) {
        graph[i].clear();
        for (int j = 0; j < n; ++j) {
            int b;
            scanf(" %d", &b);
            if (b == 1) {
                graph[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < MAX_D + 1; ++i) {
        for (int j = 0; j < MAX_N; ++j) {
            dp[i][j] = -1;
        }
    }

    int t;
    scanf(" %d", &t);
    for (int i = 0; i < t; ++i) {
        int q;
        scanf(" %d", &q);
        printf("%.8f ", getDp(d, q));
    }
    printf("\n");
}