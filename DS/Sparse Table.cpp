#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000, MAXK = 25;
int st[MAXN][MAXK + 1];
vector<int> a;

void build(int N, int K) {
    for (int i = 0; i < N; ++i)
        st[i][0] = a[i]; // F = (a[i])

    for (int j = 1; j <= K; ++j)
        for (int i = 0; i + (1 << j) <= N; ++i)
            st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]); // F = min. [2^j = 2^(j-1) U 2^(j-1)]
}

int find_range_min(int L, int R) {
    int j = log2(R - L + 1);
    return min(st[L][j], st[R - (1 << j) + 1][j]); // overlapping ranges
}

int find_range_sum(int L, int R) {
    int sum = 0;
    for (int j = log2(R - L + 1); j >= 0; --j) {
        if ((1 << j) <= R - L + 1) {
            sum += st[L][j];
            L += (1 << j);
        }
    }
    return sum;
}

int main() {
    int N = 7;
    int K = floor(log2(N)) + 1;
    a = {4, 6, 1, 5, 7, 3, -1};
    build(N, K);

    // Query
    int L = 1, R = 5;
    int ans = find_range_min(L, R);
    cout << ans << "\n";

    return 0;
}
