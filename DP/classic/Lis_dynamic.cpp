#include <iostream>
#include <cstring>

using namespace std;

int arr[1000], n;
int mem[1000][1000];
int dp(int i, int prev_idx);
int path[1000];

int main() {
    memset(mem, -1, sizeof(mem));
    memset(path, -1, sizeof(path));

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);

    int max_len = 0, mxIndex;
    for (int i = 0; i < n-1; i++) {
        int len = dp(i+1, i) + 1;
        if (len > max_len) {
            max_len = len;
            mxIndex = i;
        }
    }

    printf("%d\n\n", max_len);

    while (1) {
        printf("%d ", mxIndex);
        if (path[mxIndex] == -1) break;
        mxIndex = path[mxIndex];
    }

    return 0;
}

int dp(int i, int prev_idx) {
    if (i == n) return 0;

    if (mem[i][prev_idx] != -1)
        return mem[i][prev_idx];

    int lis1 = dp(i+1, prev_idx); // leave it.

    int lis2 = 0;
    if (arr[i] >= arr[prev_idx]) {
        lis2 = 1 + dp(i+1, i);    // take it..with condition.
    }

    if (lis1 > lis2) path[prev_idx] = i+1;
    else if (path[prev_idx] == -1 || mem[path[prev_idx]][prev_idx] < lis2)
        path[prev_idx] = i;

    return mem[i][prev_idx] = max(lis1, lis2);
}
