#include <bits/stdc++.h>
using namespace std;

const int n = 3, m = 4, INF = 1e9;
int grid[100][100] = {
    {3, 2, 1, 3},
    {1, 9, 2, 3},
    {9, 1, 5, 4}
};

vector<vector<int>> dp(n, vector<int>(m, INF));

int main(){

    dp[0][0] = grid[0][0];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j < m-1) {
                dp[i][j+1] = min(dp[i][j+1], grid[i][j+1] + dp[i][j]);
            }
            if (i < n-1) {
                dp[i+1][j] = min(dp[i+1][j], grid[i+1][j] + dp[i][j]);
            }
        }
    }

    cout << dp[n-1][m-1] << "\n\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}
