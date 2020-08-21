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

    string a = "kabcde";
    string b = "abcfed";
    int n = a.length();
    int m = b.length();

    int dp[n+1][m+1];
    int mx_len = 0;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }

            if (a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = 0;

            mx_len = max(mx_len, dp[i][j]);
        }
    }

    cout << "LCS: " << mx_len << "\n";

    return 0;
}
