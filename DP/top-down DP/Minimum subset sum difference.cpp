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
    s1 & s2. where s2 = Total - s1. So minimize (Total - s1 -s1) = Total - 2*s1.
    We can go upto Total/2 for s1.
*/

int main() {
    int n = 4;
    vector<int> a = {1, 2, 3, 7};
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
                dp[i][j] = dp[i-1][j-a[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    // select candidate(j): select the j which can be made using the array elements.
    int ans = sum;
    for(int i = n, j = 0; j <= sum/2; ++j)
        if (dp[i][j])
            ans = min(ans, (sum - 2*j));

    cout << "Minimum difference: " << ans << "\n";

    return 0;
}
