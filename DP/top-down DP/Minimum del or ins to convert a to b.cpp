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
    string a = "heap";
    string b = "pea";
    int n = a.length();
    int m = b.length();

    int dp[n+1][m+1];

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }

            if (a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << "LCS: " << dp[n][m] << "\n";
    cout << "Deletion: " << n - dp[n][m] << "\n";
    cout << "Insertion: " << m - dp[n][m] << "\n";

    return 0;
}
