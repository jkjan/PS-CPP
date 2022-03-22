#include <iostream>
#include <vector>
#include <cstring>
#define MAX 100000

using namespace std;

int dp[MAX + 1];
vector<int> graph[MAX + 1];
bool visited[MAX + 1];

int dfs(int v) {
    if (dp[v] == -1) {
        dp[v] = 1;
        for (auto adj: graph[v]) {
            if (!visited[adj]) {
                visited[adj] = true;
                dp[v] += dfs(adj);
            }
        }
    }
    return dp[v];
}

int main() {
    int N, R, Q;

    scanf(" %d %d %d", &N, &R, &Q);
    memset(dp, -1, sizeof(dp));
//    fill_n(dp, MAX + 1, -1);
//    memset(dp, -1, sizeof(dp));

    int E = N - 1;
    for (int i = 0; i < E; ++i) {
        int U, V;
        scanf(" %d %d", &U, &V);
        graph[U].push_back(V);
        graph[V].push_back(U);
    }

    visited[R] = true;
    dfs(R);
    for (int i = 0; i < Q; ++i) {
        int q;
        scanf(" %d", &q);
        printf("%d\n", dp[q]);
    }

    return 0;
}