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
    string a = "abcdgh";
    string b = "abedfhr";
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

    cout << "LCS: " << dp[n][m] << "\n\n";

    // print the LCS
    int i = n, j = m;
    string lcs = "";

    while (true) {
        if (i == 0 && j == 0) break;
        if (a[i-1] == b[j-1]) {
            lcs += a[i-1];
            --i;
            --j;
        }
        else if (dp[i-1][j] > dp[i][j-1]) --i;
        else --j;
    }

    reverse(lcs.begin(), lcs.end());
    cout << lcs << "\n";

    return 0;
}
