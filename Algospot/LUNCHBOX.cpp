#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX_N 10000
using namespace std;

typedef pair<int, int> lunchbox;

void tc();

int main() {
    int C;
    scanf(" %d\n", &C);
    for (int i = 0; i < C; i++) {
        tc();
    }
    return 0;
}

void getInput(int &N, int *M, int *E) {
    scanf(" %d", &N);
    for (int i = 0; i < N; ++i) {
        scanf(" %d", M + i);
    }
    for (int i = 0; i < N; ++i) {
        scanf(" %d", E + i);
    }
}

void tc() {
    int N;
    int M[MAX_N], E[MAX_N];
    getInput(N, M, E);

    vector<lunchbox> order;
    for (int i = 0; i < N; ++i) {
        order.push_back({-E[i], i});
    }
    sort(order.begin(), order.end());

    int eatStart = 0;
    int ret = 0;
    for (int i = 0; i < N; ++i) {
        int boxNum = order[i].second;
        eatStart += M[boxNum];
        ret = max(ret, eatStart + E[boxNum]);
    }

    printf("%d\n", ret);
}