#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, mxInd, ans = 0;
    cin >> n;
    int arr[n], dp[n], path[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    path[0] = -1; dp[0] = 1;

    for (int i = 1; i < n; i++) {
        dp[i] = 1; path[i] = -1;

        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                if (1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                    path[i] = j;
                }
            }
        }

        if (dp[i] > ans) {
            ans = dp[i];
            mxInd = i;
        }
    }

    // path print ans.
    cout << ans << "\n";
    for (int i = mxInd; i != -1; i = path[i])
        cout << arr[i] << " ";

    return 0;
}
