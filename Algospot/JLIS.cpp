#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>

#define MAX 100 + 1
using namespace std;
typedef long long ll;

int n, m;
ll A[MAX], B[MAX];
int dp[MAX][MAX];
void tc();
int JLIS(int, int);

int main() {
    int C;
    scanf(" %d", &C);
    for (int i = 0; i < C; i++) {
        tc();
    }
    return 0;
}

void tc() {
    scanf(" %d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf(" %lld", A + i);
    }
    for (int i = 1; i <= m; ++i) {
        scanf(" %lld", B + i);
    }
    memset(dp, -1, sizeof(dp));
    A[0] = B[0] = LLONG_MIN;
    printf("%d\n", JLIS(0, 0) - 2);
}

int JLIS(int aStart, int bStart) {
    int& ret = dp[aStart][bStart];
    if (ret == -1) {
        ret = 2;
        ll x = max(A[aStart], B[bStart]);
        for (int i = aStart + 1; i <= n; ++i) {
            if (x < A[i])
                ret = max(ret, JLIS(i, bStart) + 1);
        }
        for (int i = bStart + 1; i <= m; ++i) {
            if (x < B[i])
                ret = max(ret, JLIS(aStart, i) + 1);
        }
    }
    return ret;
}