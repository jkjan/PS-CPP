#include <iostream>
#include <queue>
#define MAX 100

using namespace std;

int N;
char grid[MAX][MAX + 1];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int getCluster(bool);

int main() {
    scanf(" %d", &N);
    for (int i = 0; i < N; ++i) {
        scanf(" %s", grid[i]);
    }
    int answer1 = getCluster(false);
    int answer2 = getCluster(true);
    printf("%d %d", answer1, answer2);
    return 0;
}

void bfs(int sy, int sx, bool visited[][MAX], bool blind) {
    queue<pair<int, int>> willVisit;
    willVisit.push({sy, sx});
    char first = grid[sy][sx];
    while (!willVisit.empty()) {
        auto nowVisit = willVisit.front();
        willVisit.pop();
        int ny = nowVisit.first;
        int nx = nowVisit.second;
        for (int i = 0; i < 4; ++i) {
            int adjY = ny + dy[i];
            int adjX = nx + dx[i];
            if (0 <= adjY and adjY < N and 0 <= adjX and adjX < N) {
                if (!visited[adjY][adjX]) {
                    bool canGo;
                    if (!blind) {
                        canGo = grid[adjY][adjX] == first;
                    }
                    else {
                        canGo = grid[adjY][adjX] == first;
                        canGo |= (grid[adjY][adjX] == 'G' and first == 'R');
                        canGo |= (grid[adjY][adjX] == 'R' and first == 'G');
                    }
                    if (canGo) {
                        visited[adjY][adjX] = true;
                        willVisit.push({adjY, adjX});
                    }
                }
            }
        }
    }
}

int getCluster(bool blind) {
    bool visited[MAX][MAX] = {0, };
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!visited[i][j]) {
                cnt += 1;
                visited[i][j] = true;
                bfs(i, j, visited, blind);
            }
        }
    }
    return cnt;
}