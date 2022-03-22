#include <cstdio>
#include <vector>
#include <string>
#define MAX 5
#define INF MAX + MAX

using namespace std;

class Pos {
public:
    int y, x;
    Pos() {
        this->y = -1;
        this->x = -1;
    }
    Pos(int y, int x) {
        this->y = y;
        this->x = x;
    }
};

template<typename T>
class Node {
public:
    T data;
    Node *left;
    Node *right;
    Node() {
        this->data = T();
        this->left = this->right = NULL;
    }
    Node(T data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

template<typename T>
class Queue {
    Node<T> *head;
    Node<T> *tail;
    int cnt;
public:
    Queue() {
        this->cnt = 0;
        Node<T> *head = new Node<T>();
        Node<T> *tail = new Node<T>();
        this->head = head;
        this->tail = tail;
        this->head->right = this->tail;
        this->tail->left = this->head;
    }

    void insert(T x) {
        Node<T> *newNode = new Node<T>(Node<T>(x));
        this->tail->left->right = newNode;
        newNode->left = this->tail->left;
        newNode->right = this->tail;
        this->tail->left = newNode;
        this->cnt += 1;
    }

    T top() {
        if (!this->isEmpty()) {
            return this->head->right->data;
        }
        return NULL;
    }

    T pop() {
        if (!this->isEmpty()) {
            Node<T> *toPop = this->head->right;
            this->head->right->right->left = this->head;
            this->head->right = this->head->right->right;
            T toReturn = toPop->data;
            this->cnt -= 1;
            delete toPop;
            return toReturn;
        }
        return T();
    }

    bool isEmpty() {
        return this->cnt == 0;
    }
};

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

bool bfs(vector<string> &place, Pos p) {
    Queue<Pos> willVisit;
    int dist[MAX][MAX];
    willVisit.insert(p);
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            dist[i][j] = INF;
        }
    }
    dist[p.y][p.x] = 0;

    while (!willVisit.isEmpty()) {
        Pos nowVisit = willVisit.pop();
        int ny = nowVisit.y;
        int nx = nowVisit.x;

        for (int i = 0; i < 4; ++i) {
            int adjY = ny + dy[i];
            int adjX = nx + dx[i];
            if (0 <= adjY and adjY < MAX and 0 <= adjX and adjX < MAX) {
                if (place[adjY][adjX] != 'X') {
                    if (dist[adjY][adjX] == INF) {
                        dist[adjY][adjX] = dist[ny][nx] + 1;
                        if (place[adjY][adjX] == 'P' and dist[adjY][adjX] <= 2)
                            return false;
                        willVisit.insert({adjY, adjX});
                    }
                }
            }
        }
    }
    return true;
}

bool isSafe(vector<string> &place) {
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            if (place[i][j] == 'P') {
                if (!bfs(place, {i, j}))
                    return false;
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (auto place: places) {
        answer.push_back(isSafe(place));
    }

    return answer;
}

int main() {
    Queue<int> myQueue;
    myQueue.insert(1);
    myQueue.insert(2);
    myQueue.insert(3);
    myQueue.insert(4);
    for (int i = 0; i < 4; ++i) {
        printf("%d ", myQueue.pop());
    }

    return 0;
}