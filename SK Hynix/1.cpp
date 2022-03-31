#include <string>
#include <queue>
#include <set>
#include <cstring>

#define MAX_N 100
#define INF 2 * MAX_N
#define MASKED 'M'
#define UNMASKED 'N'
#define CONFIRMED 'C'

using namespace std;

typedef struct _pos {
    int y, x;
} pos;

int len;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
set<pos> infectedPeople;

int solution(vector<string>);
void bfs(vector<string>& theater, pos confirmedPerson);

int main() {
    vector<string> theater = {
            "MNMN",
            "MNMN",
            "-C-N",
            "MNMM"
    };
    solution(theater);
    return 0;
}

int solution(vector<string> theater) {
    len = theater.size();
    int answer;

    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            if (theater[i][j] == CONFIRMED) {
                pos confirmedPerson = {i, j};
                bfs(theater, confirmedPerson);
            }
        }
    }

    answer = infectedPeople.size();
    return answer;
}

bool isValid(pos p) {
    return 0 <= p.y and p.y < len and 0 <= p.x and p.x < len;
}

bool isVisited(pos p, int dist[][MAX_N]) {
    return dist[p.y][p.x] == INF;
}

pos getAdj(pos p, int n) {
    return {p.y + dy[n], p.x + dx[n]};
}

void searchNextNode(pos p, int dist[][MAX_N], queue<pos>& nodesToVisit) {
    for (int i = 0; i < 4; ++i) {
        pos adj = getAdj(p, i);

        if (isValid(adj) and
            not isVisited(adj, dist)) {
                int newDistance = dist[p.y][p.x] + 1;
                dist[adj.y][adj.x] = newDistance;
                nodesToVisit.push(adj);
            }
        }
}

void initArr(pos p, int dist[][MAX_N]) {
    memset(dist, INF, MAX_N * MAX_N);
    dist[p.y][p.x] = 0;
}

void initBFS(pos p, int arr[][MAX_N], queue<pos> &nodesToVisit) {
    initArr(p, arr);
    nodesToVisit.push(p);
}

void infect(pos p, int dist[][MAX_N], vector<string>& theater) {
    if ((theater[p.y][p.x] == MASKED and dist[p.y][p.x] <= 2) or
        (theater[p.y][p.x] == UNMASKED and dist[p.y][p.x] <= 3)) {
        infectedPeople.insert(p);
    }
}

void bfs(vector<string>& theater, pos confirmedPerson) {
    int distanceFromConfirmedPerson[MAX_N][MAX_N];
    queue<pos> nodesToVisit;

    initBFS(confirmedPerson, distanceFromConfirmedPerson, nodesToVisit);

    while (!nodesToVisit.empty()) {
        pos nowVisit = nodesToVisit.front();
        nodesToVisit.pop();
        infect(nowVisit, distanceFromConfirmedPerson, theater);
        searchNextNode(nowVisit, distanceFromConfirmedPerson, nodesToVisit);
    }
}
