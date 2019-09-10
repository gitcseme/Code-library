#include <bits/stdc++.h>
using namespace std;

const int n = 4;
int mem[n];

int dp(int i) {
    if (i == n || i == n-1) return 1;
    if (mem[i] != -1) return mem[i];

    int ans1 = dp(i+1);
    int ans2 = dp(i+2);

    return mem[i] = ans1 + ans2;
}

int main() {
    memset(mem, -1, sizeof(mem));
    int ans = dp(0);

    cout << ans << "\n";

    return 0;
}
