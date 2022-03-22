// https://algospot.com/judge/problem/read/FESTIVAL

#include <iostream>
#include <algorithm>

using namespace std;

void tc();

int main() {
    int T;
    scanf(" %d", &T);

    for (int i = 0; i < T; ++i) {
        tc();
    }

    return 0;
}

void tc() {
    int N, L;
    scanf(" %d %d", &N, &L);

    int costs[1000];

    for (int i = 0; i < N; ++i) {
        scanf(" %d", costs + i);
    }

    double min_avg = 101;

    for (int i = 0; i <= N - L; ++i) {
        int j = 0;
        double now_sum = 0;
        while (i + j < N) {
            now_sum += costs[i + j];
            if (j + 1 >= L) {
                min_avg = min(min_avg, now_sum / (j + 1));
            }
            j++;
        }
    }

    printf("%.12f\n", min_avg);
}