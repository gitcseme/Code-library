#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    string a, b;
    cin >> a >> b;
    a.insert(a.begin(), '$');
    b.insert(b.begin(), '@');
    m = a.size();
    n = b.size();

    int dp[105][105];
    for (int i = 0; i <= 100; ++i) dp[0][i] = dp[i][0] = 0;

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << "LCS : " << dp[m-1][n-1] << "\n";

    //path
    int r = m-1, c = n-1;
    while (r > 0 && c > 0) {
        if (a[r] == b[c]) {
            cout << a[r] << " ";
            --r, --c;
        }
        else if (dp[r-1][c] >= dp[r][c-1]) --r;
        else --c;
    }


    return 0;
}
