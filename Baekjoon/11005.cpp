#include <string>
#include <iostream>

using namespace std;

int main() {
    int N, B;
    string answer;
    string converted;

    scanf(" %d %d", &N, &B);

    while (N > 0) {
        int remain = N % B;
        N = N / B;
        if (remain < 10) {
            converted.push_back(remain + '0');
        }
        else {
            converted.push_back(remain - 10 + 'A');
        }
    }

    for (int i = converted.size() - 1; i >= 0; --i) {
        answer.push_back(converted[i]);
    }
    cout << answer;
    return 0;
}
