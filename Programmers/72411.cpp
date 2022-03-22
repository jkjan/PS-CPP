#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
string s;

void dfs(string a, int i) {
    int n = s.size();
    if (i == n) {
        cout << a << endl;
    }
    for (; i < n; i++) {
        dfs(a + s[i], i + 1);
        dfs(a, i + 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (auto o: orders) {
        s = o;
        dfs("", 0);
        cout << endl;
    }
    return answer;
}

int main() {
    return 0;
}
