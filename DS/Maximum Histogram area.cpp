#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); // IO speedup.
    int t, N;
    cin >> t;
    int input[30005], x, idx;
    long long maxArea, area;

    for (int i = 1; i <= t; ++i) {
        cin >> N;
        stack<int> stk;
        maxArea = area = 0;
        for (int j = 0; j < N; ++j) cin >> input[j];

        for (idx = 0; idx < N; ++idx) {
            if (stk.empty() || input[stk.top()] <= input[idx]) {
                stk.push(idx);
            }
            else {
                while (!stk.empty() && input[stk.top()] > input[idx]) {
                    x = stk.top(); stk.pop();
                    if (stk.empty()) {
                        area = (long long) input[x] * idx;
                    }
                    else {
                        area = (long long) input[x] * (idx - stk.top() - 1);
                    }
                    maxArea = max (maxArea, area);
                }
                stk.push(idx);
            }
        }
        while (!stk.empty()) {
            x = stk.top(); stk.pop();
            if (stk.empty()) {
                area = idx * input[x];
            }
            else {
                area = (long long) input[x] * (idx - stk.top() - 1);
            }
            maxArea = max (maxArea, area);
        }

        cout << "Case " << i << ": " << maxArea << "\n";
    }

    return 0;
}
