#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<30;

bool check (int mask, int pos) { return (bool)(mask & (1 << pos)); }
int on (int mask, int pos) { return mask = mask | (1 << pos); }
int a[20][20], h[20], mem[(1 << 16)], N;

int dp (int mask, int cnt) {
    if (cnt == N) return 0;

    if (mem[mask] != -1) return mem[mask];

    int ans = INF;

    for (int j = 0; j < N; ++j)
    {
        if (check(mask, j) == 0) {
            for (int i = 0; i <= N; ++i) {
                if (i==N || check(mask, i) == 1 && a[i][j] != 0) {
                    int gun = (i == N) ? 1 : a[i][j];

                    int tmp_msk = on(mask, j);
                    int c = (int)ceil((float)h[j] / gun);
                    ans = min(ans, c + dp(tmp_msk, cnt + 1));
                }
            }
        }
    }
    return mem[mask] = ans;
}

int main () {
    freopen("inp.txt", "r", stdin);
    int t, mask;
    cin >> t; char c;

    for (int cse = 1; cse <= t; ++cse) {
        cin >> N;
        for (int i = 0; i < N; ++i) cin >> h[i];
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> c;
                a[i][j] = (int)(c - '0');
            }
        }
        memset(mem, -1, sizeof(mem));
        mask = 0;
        printf("Case %d: %d\n", cse, dp(mask, 0));
    }

    return 0;
}
