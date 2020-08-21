#include<bits/stdc++.h>
using namespace std;

const int maxn = 1005;
vector<int> p;
vector<int> w;
int mem[maxn][maxn];

int knapsack(int i, int sack) {
    if (i == 0 || sack == 0)
        return 0;

    if (mem[i][sack] != -1) return mem[i][sack];

    if (w[i-1] <= sack)
        mem[i][sack] = max(p[i-1] + knapsack(i-1, sack-w[i-1]), knapsack(i-1, sack));
    else
        mem[i][sack] = knapsack(i-1, sack);

    return mem[i][sack];
}

int main() {
    memset(mem, -1, sizeof(mem));

    int n = 4;
    int sack = 7;

    w = {1, 3, 4, 5};
    p = {2, 4, 5, 7};

    cout << knapsack(n, sack) << "\n";

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= sack; ++j) {
            cout << mem[i][j] << " ";
        }
        puts("");
    }
    puts("---------------------------------\n");

    // TopDown
    int dp[n+1][sack+1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= sack; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (w[i-1] <= j)
                dp[i][j] = max(p[i-1] + dp[i-1][j-w[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n][sack] << "\n";

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= sack; ++j) {
            cout << dp[i][j] << " ";
        }
        puts("");
    }

    return 0;
}
