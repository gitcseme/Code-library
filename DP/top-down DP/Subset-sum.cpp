#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(int i : v) {cout << i << " ";} puts("");
#define CIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

// base:- Knapsack

int n, sum;
vector<int> a;
int mem[1000][1000];
int cnt = 0;

int dp(int i, int sum) {
    if (sum == 0) {
        ++cnt;
        return 1;
    }
    if (i == 0) return 0;

    if (mem[i][sum] != -1) {
        if (mem[i][sum]) ++cnt;
        return mem[i][sum];
    }

    if (a[i-1] <= sum) {
        int x = dp(i-1, sum-a[i-1]);
        int y = dp(i-1, sum);
        mem[i][sum] = x || y;
    }
    else
        mem[i][sum] = dp(i-1, sum);

    return mem[i][sum];
}

int main() {
    memset(mem, -1, sizeof(mem));
    n = 6;
    sum = 11;
    a = {1, 2, 3, 7, 8, 10};

    dp(n, sum);
    cout << cnt << " times\n";

    // Top-down
    int DP[n+1][sum+1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= sum; ++j) {
            if (i == 0) DP[i][j] = 0;
            if (j == 0) DP[i][j] = 1;
            if (i == 0 || j == 0) continue;

            if (a[i-1] <= j)
                DP[i][j] = DP[i-1][j-a[i-1]] + DP[i-1][j];
            else
                DP[i][j] = DP[i-1][j];
        }
    }

    cout << DP[n][sum] << " times\n";

    return 0;
}
