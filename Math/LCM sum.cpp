#include <bits/stdc++.h>
using namespace std;

/* source : http://shoshikkha.com/archives/5459 */

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

vector <int> fact;
void fcatorize(int n) {
    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0) {
                n = n / p;
            }
            fact.push_back(p);
        }
    }
    if (n > 1) fact.push_back(n);
}

int main() {
    int n;
    cin >> n;
    fcatorize(n);
    fact.push_back(1), fact.push_back(n);

    int LCMSUM = 0;
    for (int d : fact) {
        LCMSUM = LCMSUM + (d * phi(d));
    }
    LCMSUM = (n * (LCMSUM + 1)) / 2;
    cout << LCMSUM << "\n";


    return 0;
}
