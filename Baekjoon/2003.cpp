#include <cstdio>
#define MAX 10000

int main() {
    int A[MAX], N, M;
    scanf(" %d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf(" %d", A + i);
    }

    int s, e, partialSum, cnt;
    s = 0;
    e = 0;
    cnt = 0;
    partialSum = A[0];

    while (s < N and e < N) {
        if (partialSum == M) {
            cnt += 1;
            e += 1;
            partialSum += A[e];
        }
        else if (partialSum < M) {
            e += 1;
            partialSum += A[e];
        }
        else {
            partialSum -= A[s];
            s += 1;
        }
    }
    printf("%d", cnt);
    return 0;
}
