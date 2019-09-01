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
        for (int i = l; i <= r; ) {
            if (i%len == 0 && i + len - 1 <= r) {
                sum += b[i / len]; // Complete block.
                i += len;
            }
            else { // left or right incomplete block.
                sum += a[i];
                ++i;
            }
        }
        cout << sum << "\n";
    }

    return 0;
}
