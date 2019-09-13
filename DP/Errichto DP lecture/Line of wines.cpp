#include <bits/stdc++.h>
using namespace std;

int n;
int mem[100][100];
int path[100][100];
vector<int> wPrice;

int dp(int b, int e) {
    if (b == e)
        return n * wPrice[b];

    if (mem[b][e] != -1) return mem[b][e];

    int y = n - (e - b);
    int ans1 = dp(b + 1, e) + y * wPrice[b];
    int ans2 = dp(b, e - 1) + y * wPrice[e];

    path[b][e] = ans1 >= ans2 ? 0 : 1;

    return mem[b][e] = max(ans1, ans2);
}

int main() {
    n = 5;
    wPrice = { 2, 4, 6, 2, 5 };
    memset(mem, -1, sizeof(mem));
    int ans = dp(0, n-1);
    printf("Maximum profit: %d\n\n", ans);

    // Path printing
    int i = 0, j = n-1;
    while (i <= j) {
        if (path[i][j] == 0) {
            printf("%d ", wPrice[i]);
            ++i;
        }
        else {
            printf("%d ", wPrice[j]);
            --j;
        }
    }

    return 0;
}
