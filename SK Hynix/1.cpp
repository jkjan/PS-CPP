#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <cstring>

#define MAX_N 100
#define INF 2 * MAX_N
#define MASKED 'M'
#define UNMASKED 'N'
#define CONFIRMED 'C'
#define EMPTY '-'

using namespace std;
typedef pair<int, int> pos;

int len;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int solution(vector<string>);
void bfs(vector<string>&);

int main() {


    return 0;
}


int solution(vector<string> theater) {
    len = theater.size();

    return 0;
}

bool isValid(pos p) {
    int y = p.first; 
    int x = p.second;
    return 0 <= y and y < len and 0 <= x and x < len;
}

bool isVisited(pos p, int dist[][MAX_N]) {
    int y = p.first;
    int x = p.second;
    return dist[p.first][p.second] == INF;
}

bool isInfecting(pos p, int dist[][MAX_N], vector<string>& theater) {
    int y = p.first;
    int x = p.second;
    if (theater[y][x] == EMPTY) {
        return false;
    }
    else if (theater[y][x] == MASKED and dist[y][x] > 2) {
        return false;
    }
    else if (theater[y][x] == UNMASKED and dist[y][x] > 3) {
        return false;
    }
    return true;
}

void searchNextNode(pos p, int distanceFromConfirmedPerson[][MAX_N], queue<pos>& willVisit) {
    int y = p.first;
    int x = p.second;
    for (int i = 0; i < 4; ++i) {
        int adjY = y + dy[i];
        int adjX = x + dx[i];
        pos adj = {adjY, adjX};

        if (isValid(adj)) {
            if (not isVisited(adj, distanceFromConfirmedPerson)) {
                int newDistance = distanceFromConfirmedPerson[y][x] + 1;
                distanceFromConfirmedPerson[adjY][adjX] = newDistance;
                willVisit.push(adj);
            }
        }
    }
}

void initArr(int arr[][MAX_N], int x) {
    memset(arr, x, sizeof(arr));
}

void bfs(set<pos>& infectedPeople, vector<string>& theater, pos confirmedPerson) {
    queue<pos> willVisit;
    int distanceFromConfirmedPerson[MAX_N][MAX_N];
    memset(distanceFromConfirmedPerson, INF, sizeof(distanceFromConfirmedPerson));
    distanceFromConfirmedPerson[confirmedPerson.first][confirmedPerson.second] = 0;
    willVisit.push(confirmedPerson);

    while (!willVisit.empty()) {
        pos nowVisit = willVisit.front();

        if (isInfecting(nowVisit, distanceFromConfirmedPerson, theater)) {
            infectedPeople.insert(nowVisit);
        }

        searchNextNode(nowVisit, distanceFromConfirmedPerson, willVisit);
    }
}
