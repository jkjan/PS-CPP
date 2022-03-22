#include <string>
#include <vector>
#include <algorithm>
#define MAX 100

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int parents[MAX];

int find(int x) {
    if (parents[x] == x)
        return x;
    else
        return parents[x] = find(parents[x]);
}

void _union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a < b)
        parents[b] = a;
    else
        parents[a] = b;
}

int isSame(int a, int b) {
    return find(a) == find(b);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), compare);
    for (int i = 0; i < n; i++) {
        parents[i] = i;
    }

    for (auto edge: costs) {
        if (!isSame(edge[0], edge[1])) {
            _union(edge[0], edge[1]);
            answer += edge[2];
        }
    }

    return answer;
}

int main() {
    int n = 4;
    vector<vector<int>> costs = {
            {0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}
    };
    printf("%d", solution(n, costs));
    return 0;
}