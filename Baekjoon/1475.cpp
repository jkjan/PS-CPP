#include <iostream>
#include <cstring>

#define MAX 7

using namespace std;

int main() {
    char N[MAX + 1];
    scanf(" %s", N);
    int len = strlen(N);
    int cnt[10] = {0, };
    for (int i = 0; i < len; ++i) {
        int num = N[i] - '0';
        if (num == 9)
            num = 6;
        cnt[num] += 1;
    }
    int maxSet = 0;
    for (int i = 0; i <= 9; ++i) {
        int num = cnt[i];
        if (i == 6)
            num = (num / 2) + (num % 2);
        maxSet = max(maxSet, num);
    }
    printf("%d", maxSet);
    return 0;
}