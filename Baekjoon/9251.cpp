#include <iostream>
#include <cstring>
#define MAX 1002

using namespace std;

int dp[MAX][MAX];
int aLen, bLen;
char A[MAX], B[MAX];

int getLCS(int a, int b) {
    int &ret = dp[a][b];
    if (ret == -1) {
        ret = 1;
        int maxNext = 0;
        for (int i = a + 1; i < aLen; ++i) {
            maxNext = max(maxNext, getLCS(i, b));
        }
        for (int i = b + 1; i < bLen; ++i) {
            maxNext = max(maxNext, getLCS(a, i));
        }
        ret += maxNext;
    }
    return ret;
}

int main() {
    scanf(" %s", A);
    scanf(" %s", B);
    aLen = strlen(A);
    bLen = strlen(B);
    memset(dp, -1, sizeof(dp));
    int answer = getLCS(0, 0);
    printf("%d", answer);
    return 0;
}