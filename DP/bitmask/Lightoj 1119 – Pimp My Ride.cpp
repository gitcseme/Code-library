#include <bits/stdc++.h>
#define INF 1<<28
using namespace std;
bool check (int mask, int pos) { return (bool)(mask & (1 << pos)); }
int on (int mask, int pos) { return mask = mask | (1 << pos); }
int w[20][20], dp[(1 << 15) + 5], n;

int call (int mask) {
    if (mask == (1 << n)-1) return 0;
    if (dp[mask] != -1) return dp[mask];

    int ans = INF;
    for (int i = 0; i < n; ++i) {
        if (check(mask, i) == 0)
        {
            int price = w[i][i];
            for (int j = 0; j < n; ++j) {
                if (i != j && check(mask, j) != 0) {
                    price += w[i][j];
                }
            }
            int ret = price + call(on(mask, i)); // take it.
            ans = min (ans, ret);
        }
    }
    return dp[mask] = ans;
}

int main () {
    freopen("inp.txt", "r", stdin);

    int t, cse = 0;
    cin >> t;
    while (t--) {
        memset(dp, -1, sizeof(dp));
        cin >> n;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> w[i][j];
            }
        }
        int v = call(0);
        cout << "Case " << ++cse << ": " << v << "\n";
    }

    return 0;
}
