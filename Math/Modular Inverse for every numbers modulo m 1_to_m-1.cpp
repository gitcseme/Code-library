#include <bits/stdc++.h>
using namespace std;
// find inverse [1 - n]

int main() {
    int m;
    cin >> m; // m must be prime.
    int inv[m];

    inv[1] = 1;
    for (int i = 2; i < m; ++i)
        inv[i] = (m - (m/i) * inv[m%i] % m) % m;

    for (int i = 1; i < m; ++i)
        cout << i << " " << inv[i] << "\n";

    return 0;
}
