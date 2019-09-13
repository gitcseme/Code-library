#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 8;
    vector<int> a = {-2, -3, 4, -1, -2, 1, 5, -3};
    vector<int> dp(8);

    dp[0] = a[0];
    for (int i = 1; i < n; ++i)
        dp[i] = max(a[i], dp[i-1] + a[i]);

    int ans = *max_element(dp.begin(), dp.end());
    cout << "Max sub-array sum: " << ans << "\n\n";

    return 0;
}
