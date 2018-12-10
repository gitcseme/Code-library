#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<28;

bool check (int mask, int pos) { return (bool)(mask & (1 << pos)); }
int on (int mask, int pos) { return mask = mask | (1 << pos); }
//int off (int mask, int pos) { return mask = mask & ~(1 << pos); }
int N, gst[30], mem[(1<<20) + 5], minimum = INF;

int countDamage(int mask) {
    int dmg = 0;
    for (int i = 0; i < N; ++i) if (!check(mask, i)) dmg += gst[i];
    return dmg;
}

int dp (int mask) {
    if (countDamage(mask) == 0)
        return 0;

    if (mem[mask] != -1) return mem[mask];

    int ans = INF;
    for (int i = 0; i < N; ++i) {
        bool valid = false;
        for (int j = 0; j < 3; ++j)
            if ((mask & (1<<((i+j)%N))) == 0)
                valid = true;

        if (!valid) continue;

        int tmp_mask = mask;
        for (int j = 0; j < 3; ++j)
            tmp_mask = tmp_mask | (1 << ((i+j)%N));

        ans = min (ans, dp(tmp_mask) + countDamage(tmp_mask) );
    }
    return mem[mask] = ans;
}

int main () {
    freopen("inp.txt", "r", stdin);
    cin >> N;
    int mask = 0;
    for (int i = 0; i < N; ++i) cin >> gst[i];

    memset(mem, -1, sizeof(mem));
    cout << dp(mask) << "\n";

    return 0;
}
