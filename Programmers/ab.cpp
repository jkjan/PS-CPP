#include <string>
#include <vector>

using namespace std;

int compress(string &s, int n) {
    int i = 0;
    int end = s.size();
    int compressedLen = 0;

    while (i < end) {
        string standard = s.substr(i, n);
        int tokenCnt = 1;
        int j = 1;
        while (i + n * (j + 1) <= end && standard == s.substr(i + n * j, n)) {
            tokenCnt += 1;
            j += 1;
        }
        if (tokenCnt > 1) {
            compressedLen += (to_string(tokenCnt).size() + n);
            i = i + j * n;
        }
        else {
            compressedLen += standard.size();
            i = i + n;
        }
    }
    return compressedLen;
}

int solution (string s) {
    int minLen = s.size();
    int end = s.size() / 2;
    for (int i = 1; i <= end; ++i) {
        int compressedLen = compress(s, i);
        minLen = minLen < compressedLen ? minLen : compressedLen;
    }
    return minLen;
}

int main() {
    string s = "abcabcabcabcdededededede";
    printf("%d", solution(s));
    return 0;
}