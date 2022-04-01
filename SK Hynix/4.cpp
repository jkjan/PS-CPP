#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#define MAX_N 100

using namespace std;

int dp[MAX_N];
int commandLength;

int main() {
    return 0;
}

void getPos(vector<vector<int>> &skillIds, string &command, string &skill, int skillIdx) {
    int start = 0;
    int skillLength = skill.size();
    while (start < command.size()) {
        if (command.substr(start, skillLength) == skill) {
            skillIds[start].push_back(skillIdx);
        }
        start += 1;
    }
}

void getAllPos(vector<vector<int>> &skillIds, string &command, vector<string> &skills) {
    int skillLength = skills.size();
    for (int i = 0; i < skillLength; ++i) {
        getPos(skillIds, command, skills[i], i);
    }
}

int getMaxTotalScore(int nowIdx, vector<int> &scores, vector<vector<int>> &skillIds, vector<string> &skills) {
    if (nowIdx >= commandLength) {
        return 0;
    }
    int &ret = dp[nowIdx];
    if (ret != -1) {
        ret = 0;
        for (int i = nowIdx; i < commandLength; ++i) {
            for (auto id: skillIds[i]) {
                int nogo = getMaxTotalScore(nowIdx + 1, scores, skillIds, skills) + 1;
                int go = getMaxTotalScore(nowIdx + skills[id].size(), scores, skillIds, skills) + scores[id];
                ret = max(ret, max(go, nogo));
            }
        }
    }
    return ret;
}

int solution(string command, vector<string> skills, vector<int> scores) {
    commandLength = command.size();
    memset(dp, -1, sizeof(dp));
    vector<vector<int>> skillIdsStartingFromX(commandLength);
    getAllPos(skillIdsStartingFromX, command, skills);
    int answer = getMaxTotalScore(0, scores, skillIdsStartingFromX, skills);
    return answer;
}
