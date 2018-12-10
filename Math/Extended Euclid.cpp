#include <bits/stdc++.h>
using namespace std;

int extEuclid(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int d = extEuclid(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;

    return d;
}

int main() {
    int a, b, x, y;
    cin >> a >> b;
    int d = extEuclid(a, b, x, y);
    cout << d << " " << x << " " << y;

    return 0;
}
