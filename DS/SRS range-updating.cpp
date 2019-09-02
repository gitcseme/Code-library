#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;
int n, len;
int a[1005], b[32] = {0};

int main() {
    FI;

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    len = (int) sqrt(n) + 1;

    int l, r, value, query, idx, range;
    cin >> range;
    while(range--) {
        cin >> l >> r >> value;
        int c_l = l / len, c_r = r / len;

        if (c_l == c_r) {
            for (int i = l; i <= r; ++i)
                a[i] += value;
        }
        else { // k-th block starts at (length * k) and ends at (length *(k+1) - 1)
            // Left partial block
            for (int i = l, block_end = len*(c_l + 1) - 1; i <= block_end; ++i)
                a[i] += value;

            // Middle complete block
            for (int i = c_l + 1; i <= c_r - 1; ++i)
                b[i] += value;

            // Right partial block
            for (int i = (len * c_r); i <= r; ++i)
                a[i] += value;
        }
    }

    // Query
    cin >> query;
    while (query--) {
        cin >> idx;
        cout << idx << " = " << (a[idx] + b[idx/len]) << "\n";
    }

    return 0;
}
