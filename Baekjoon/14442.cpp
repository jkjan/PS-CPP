#include <cstdio>
#include <queue>
#include <vector>
#define MAX 1000

using namespace std;
char field[MAX][MAX];
int visited[MAX][MAX][10];

int main() {
    int N, M, K;
    scanf(" %d %d %d", &N, &M, &K);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            scanf(" %c", field[i] + j);
        }
    }

    int dy[] = {0, 0, 1, -1};
    int dx[] = {1, -1, 0, 0};
    int dest_y = N - 1;
    int dest_x = M - 1;
    auto will_visit = queue<pair<pair<int, int>, pair<int, int>>>({{{0, 0}, {0, 1}}});

    while (!will_visit.empty()) {
        int now_y = will_visit.front().first.first;
        int now_x = will_visit.front().first.second;
        int now_broken = will_visit.front().second.first;
        int now_cnt = will_visit.front().second.second;

        will_visit.pop();

        if (now_y == dest_y and now_x == dest_x) {
            printf("%d", now_cnt);
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int adj_y = now_y + dy[i];
            int adj_x = now_x + dx[i];
            int next_broken = now_broken;

            if (not (0 <= adj_y and adj_y < N and 0 <= adj_x and adj_x < M))
                continue;
            if (visited[adj_y][adj_x][now_broken])
                continue;
            if (field[adj_y][adj_x] == '1') {
                if (now_broken >= K)
                    continue;
                else
                    next_broken += 1;
            }

            visited[adj_y][adj_x][next_broken] = true;
            will_visit.push({{adj_y,adj_x}, {next_broken, now_cnt + 1}});
        }
    }

    printf("%d", -1);
    return 0;
}
