#include <bits/stdc++.h>
using namespace std;

int phi(int n) {
    int ret = n;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            ret -= ret / p;
        }
    }
    if (n > 1) ret -= ret / n;
    return ret;
}

int main() {
    int n;
    cin >> n;
    cout << phi(n);

    return 0;
}
