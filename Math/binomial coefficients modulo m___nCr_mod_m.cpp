#include <bits/stdc++.h>
using namespace std;


int main() {
    long long m, n, r, MAXN;
    cin >> MAXN >> m >> n >> r;

    long long fact[MAXN + 5];
    long long inv[m];

    fact[0] = 1;
    for (int i = 1; i <= MAXN; ++i)
        fact[i] = fact[i-1] * i % m;

    inv[1] = 1;
    for (int i = 2; i < m; ++i)
        inv[i] = (m - (m/i) * inv[m % i] % m) % m;

    long long ans = (fact[n] * inv[fact[r]] % m * inv[fact[n-r]] % m ) % m;

    cout << ans;
}
