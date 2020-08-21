#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(int i : v) {cout << i << " ";} puts("");
#define CIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

int main() {
    int a[] = {1, 2, 3};
    int N = 3;
    int sum = 5;
    int dp[N+1][sum+1];
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= sum; ++j) {
            if (i == 0) dp[i][j] = 0;
            if (j == 0) dp[i][j] = 1;
            if (i == 0 || j == 0) continue;

            if (a[i-1] <= j) {
                dp[i][j] = dp[i][j-a[i-1]] + dp[i-1][j];
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[N][sum] << " ways\n";

    return 0;
}
