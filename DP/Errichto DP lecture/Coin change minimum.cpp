#include <bits/stdc++.h>
using namespace std;

// Basic is combination sum
/*
dp[0] = 1;
for i = 1 ... N
    for x in nums
        dp[i] += dp[i-x];
*/

const int INF = 99999;

int main() {
    int N = 11;
    vector<int> nums = {1, 2, 5};
    vector<int> dp(N+1, INF);

    dp[0] = 0;
    for (int i = 1; i <= N; ++i) {
        for (int x : nums) {
            if (i - x >= 0) {
                dp[i] = min(dp[i], dp[i-x] + 1);
            }
        }
    }
    printf("%d\n", dp[N]);

    return 0;
}
