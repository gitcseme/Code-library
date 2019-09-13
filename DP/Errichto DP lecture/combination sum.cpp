#include <bits/stdc++.h>
using namespace std;

// how many ways can we make N using given numbers.

int main() {
    int N = 4;
    vector<int> nums = {1, 2, 3};
    vector<int> dp(N+1, 0);

    dp[0] = 1;
    for (int i = 0; i < N; ++i) {
        for (int x : nums) {
            if (i + x <= N)
                dp[i+x] += dp[i];
        }
    }

    printf("ways to make %d = %d\n", N, dp[N]);
    for(int i = 0; i <=N; ++i) printf("%d ", dp[i]);


    return 0;
}
