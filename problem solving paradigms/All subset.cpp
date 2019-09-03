#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

// n <= 25

int main() {
    int n = 5;
    int a[n] = {1, 2, 3, 4, 5};
    cout << bitset<8>(31).to_string() << "\n\n";

    for (int subset = 0, c = pow(2, n); subset < c; ++subset) {
        for (int i = 0; i < n; ++i) {
            if ((subset & (1 << i)) != 0) {
                cout << a[i] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
