#include <bits/stdc++.h>
using namespace std;

int ext_Euclid(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int d = ext_Euclid(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b) * y1;

    return d;
}

int main() {
    int b, M, x, y;
    cin >> b >> M;
    int d = ext_Euclid(b, M, x, y);

    if (d != 1)
        cout << "No solution!";
    else
        cout << d << " " << (x%M + M) % M;

    return 0;
}

/*
 * if b & M are co-prime then bx - yM = 1 = ext_Euclid(b, M);
 * here x is the modulo Inverse of b.
 */
