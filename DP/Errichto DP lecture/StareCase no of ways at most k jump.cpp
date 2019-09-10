#include <bits/stdc++.h>
using namespace std;

const int n = 4, k = 3;
int ans = 0;

int mem[n][k];

int dp(int i, int j) {

    if (i == n || i == n-1) {
        if (j + 1 <= k) {
            ++ans;
            return 1;
        }
        else
            return 0;
    }

    if (mem[i][j] != -1) return mem[i][j];

    if (1 + j <= k) {
        int ans1 = dp(i+1, j+1);
        int ans2 = dp(i+2, j+1);
        return mem[i][j] = ans1 + ans2;
    }
    return 0;
}

int main() {
    memset(mem, -1, sizeof(mem));

    dp(0, 0);
    cout << ans << "\n";

}
