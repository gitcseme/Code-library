#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(int i : v) {cout << i << " ";} puts("");
#define CIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

/*
    worst case SCS = a + b. removing the common (lcs) we get SCS = (a + b - lcs)
*/

int main() {
    string a = "AGGTAB";
    string b = "GXTXAYB";
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

    vector<char> scs;
    int i = n, j = m;
    while(i != 0 && j != 0) {
        if (a[i-1] == b[j-1]) {
            scs.push_back(a[i-1]);
            --i;
            --j;
        }
        else if (dp[i][j-1] >= dp[i-1][j]) {
            scs.push_back(b[j-1]);
            --j;
        }
        else {
            scs.push_back(a[i-1]);
            --i;
        }
    }
    // Remaining string a or b.
    while (i != 0) scs.push_back(a[i-1]), --i;
    while (j != 0) scs.push_back(b[j-1]), --j;

    cout << "SCS-length: " << (n + m - dp[n][m]) << "\n\n";

    for (int i = scs.size() - 1; i >= 0; --i)
        cout << scs[i];
    cout << "\n";

    return 0;
}
