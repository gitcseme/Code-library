#include <bits/stdc++.h>
using namespace std;

const int mx = 3005;
int dp[mx][mx];

int main() {
    //FI;

    int m, n;
    string a, b;
    cin >> a >> b;
    a.insert(a.begin(), '$');
    b.insert(b.begin(), '@');
    m = a.size();
    n = b.size();
    for (int i = 0; i < mx; ++i) dp[0][i] = dp[i][0] = 0;

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // LCS
    int r = m-1, c = n-1;
    string lcs = "";
    while(r > 0 && c > 0) {
        if (a[r] == b[c]) {
            lcs += a[r];
            --r, --c;
        }
        else if (dp[r-1][c] > dp[r][c-1]) --r;
        else --c;
    }
    reverse(lcs.begin(), lcs.end());
    printf("%s\n", lcs.c_str());

    return 0;
}
