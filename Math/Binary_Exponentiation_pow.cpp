#include <bits/stdc++.h>
using namespace std;

long long Loop_bin_pow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = (a * a);
        b = b>>1;
    }
    return res;
}

long long Recur_bin_pow(long long a, long long b) {
    if (b == 1)
        return a;
    long long res = Recur_bin_pow(a, b>>1);
    res = res * res;
    if (b & 1)
        res = res * a;
    return res;
}

int main () {

    long long a, b;
    cin >> a >> b;
    cout << Loop_bin_pow(a, b) << "\n";
    cout << Recur_bin_pow(a, b);

    return 0;
}
