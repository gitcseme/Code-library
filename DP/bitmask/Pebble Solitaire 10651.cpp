#include <bits/stdc++.h>
using namespace std;

int minimum, dp[1 << 15];

bool check (int mask, int pos) { return (bool)(mask & (1 << pos)); }
int on (int mask, int pos) { return mask = mask | (1 << pos); }

int countPabble(int mask) {
    int cnt = 0;
    for (int i = 0; i < 12; ++i)
        if (check(mask, i))
            ++cnt;
    return cnt;
}

bool rCheck(int mask, int i) {
    if (check(mask, i-1) == 1 && check(mask, i-2) == 0)
        return true;
    return false;
}

bool lCheck(int mask, int i) {
    if (check(mask, i+1) == 1 && check(mask, i+2) == 0)
        return true;
    return false;
}

bool noMoveLeft(int mask) {
    for (int i = 0; i < 12; ++i) {
        if (check(mask, i) == 1)
        {
            if (i > 1 && rCheck(mask, i)) return true;
            if (i < 10 && lCheck(mask, i)) return true;
        }
    }
    return false;
}

int call(int mask) {
    if (!noMoveLeft(mask)) {
        return countPabble(mask);
    }
    if (dp[mask] != -1) return dp[mask];

    int ans = 12; //INF
    for (int i = 0; i < 12; ++i)
    {
        if (check(mask, i) == 1)
        {
            if (i < 10 && check(mask, i+1) == 1 && check(mask, i+2) == 0) { // left move
                int msk = mask & ~(1 << i);
                msk = msk & ~(1 <<(i+1));
                msk = on(msk, i+2);
                ans = min(ans, call(msk));
            }
            if (i > 1 && check(mask, i-1) == 1 && check(mask, i-2) == 0) { // right move
                int msk = mask & ~(1 << i);
                msk = msk & ~(1 << i-1);
                msk = on(msk, i-2);
                ans = min (ans, call(msk));
            }
        }
        minimum = min(minimum, ans);
    }
    return dp[mask] = minimum;
}

int main() {
    freopen("inp.txt", "r", stdin);
    int t, mask; string s;
    cin >> t;
    while (t--) {
        memset(dp, -1, sizeof(dp));
        minimum = 50, mask = 0;
        cin >> s;
        for (int i = 0; i < 12; ++i) if (s[i] == 'o') mask = on(mask, i);

        int solve = call(mask);
        cout << solve << "\n";
    }

    return 0;
}
