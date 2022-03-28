#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
typedef priority_queue<int, vector<int>, greater<int>> intQ;

void tc();

int main() {
    int C;
    scanf(" %d\n", &C);
    for (int i = 0; i < C; i++) {
        tc();
    }
    return 0;
}

void getInput(int &n, vector<int> &lengths) {
    scanf(" %d", &n);
    for (int i = 0; i < n; ++i) {
        int len;
        scanf(" %d", &len);
        lengths.push_back(len);
    }
}

void initQueue(intQ &pq, vector<int> &lengths) {
    for (auto len: lengths) {
        pq.push(len);
    }
}


void tc() {
    int n;
    vector<int> lengths;
    getInput(n, lengths);

    intQ pq;
    initQueue(pq, lengths);

    int totalCost = 0;
    while (pq.size() > 1) {
        int dest = pq.top(); pq.pop();
        int src = pq.top(); pq.pop();
        int cost = dest + src;
        pq.push(cost);
        totalCost += cost;
    }

    printf("%d\n", totalCost);
}