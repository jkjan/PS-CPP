#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#define BASE 8
#define IMPOSSIBLE -1

using namespace std;

int solution(vector<string>);

int main() {
    vector<string> input = {"a", "b", "c"};
    int answer = solution(input);
    printf("%d", answer);
    return 0;
}

void operator+=(vector<vector<int>> &a, vector<vector<int>> b) {
    for (auto element: b) {
        a.push_back(element);
    }
}

vector<vector<int>> getPermutations(vector<int>& seqNowBuilding, bool *used) {
    if (seqNowBuilding.size() == BASE) {
        return {seqNowBuilding};
    }

    vector<vector<int>> ret;
    for (int i = 0; i < BASE; ++i) {
        if (!used[i]) {
            used[i] = true;
            seqNowBuilding.push_back(i);
            ret += getPermutations(seqNowBuilding, used);
            used[i] = false;
            seqNowBuilding.pop_back();
        }
    }
    return ret;
}

vector<vector<int>> getPermutations() {
    bool used[BASE] = {0, };
    vector<int> seqNowBuilding;
    return getPermutations(seqNowBuilding, used);
}

int getNum(vector<int> &alphaToNum, string &replacedString) {
    int stringLength = replacedString.size();
    int nowDigit = stringLength;
    int originalNumber = 0;

    for (int i = 0; i < stringLength; ++i) {
        int alphaIdx = replacedString[i] - 'a';
        int originalDigit = alphaToNum[alphaIdx];
        if (i == 0 and originalDigit == 0)
            return -1;
        originalNumber += originalDigit * pow(BASE, --nowDigit);
    }

    return originalNumber;
}

bool isPossible(vector<int> &alphaToNum, vector<string> &input) {
    int numbers[4];
    for (int i = 1; i <= 3; ++i) {
        int originalNumber = getNum(alphaToNum, input[i-1]);
        if (originalNumber == IMPOSSIBLE)
            return false;
        numbers[i] = originalNumber;
    }
    return numbers[1] + numbers[2] == numbers[3];
}

int solution(vector<string> input) {
    auto permutations = getPermutations();
    int answer = 0;
    for (auto alphaToNum: permutations) {
        answer += isPossible(alphaToNum, input);
    }
    return answer;
}
