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

/*
    Theme:
    s1 & s2. where s2 = Total - s1. diff = Total - 2*s1.
    We can go upto Total/2 for s1,s2 pair which made diff.
*/

int main() {
    int n = 4;
    int diff = 1;
    vector<int> a = {1, 1, 2, 3};
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];

    // Top-down
    int dp[n+1][sum+1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= sum; ++j) {
            if (i == 0) dp[i][j] = 0;
            if (j == 0) dp[i][j] = 1;
            if (i == 0 || j == 0) continue;

            if (a[i-1] <= j)
                dp[i][j] = dp[i-1][j-a[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    // Last row tels [4 - 3 = 1] 4 & 3 are made 3 times. hence ans = 3.
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= sum; ++j) {
            cout << dp[i][j] << " ";
        }
        puts("");
    }

    int index = -1;
    for (int i = n, j = 0; j <= sum/2; ++j) {
        if (sum - 2*j == diff) {
            index = j;
            break;
        }
    }
    if (index != -1)
        cout << dp[n][index] << " times\n";
    else
        cout << "Not found\n";

    return 0;
}
