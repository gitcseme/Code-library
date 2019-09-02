#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;
int n, len;
int a[1005], b[32];

void preProcess() {
    for (int i = 0; i < n; ++i)
        b[i / len] += a[i];
}

int main() {
    FI;

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    len = (int) sqrt(n) + 1;
    preProcess();

    int l, r;
    while(cin >> l >> r) {
        int  sum = 0;
        int c_l = l / len, c_r = r / len;

        if (c_l == c_r) {
            for (int i = l; i <= r; ++i)
                sum += a[i];
        }
        else { // k-th block starts at (length * k) and ends at (length *(k+1) - 1)
            // Left partial block
            for (int i = l, block_end = len*(c_l + 1) - 1; i <= block_end; ++i)
                sum += a[i];

            // Middle complete block
            for (int i = c_l + 1; i <= c_r - 1; ++i)
                sum += b[i];

            // Right partial block
            for (int i = (len * c_r); i <= r; ++i)
                sum += a[i];
        }
        cout << sum << "\n";
    }

    return 0;
}
