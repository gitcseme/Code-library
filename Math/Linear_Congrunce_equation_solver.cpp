#include <bits/stdc++.h>
using namespace std;

int egcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x1, y1;
    int d = egcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;

    return d;
}

int main() {
    int a, b, M, x, y;
    cin >> a >> b >> M;
    int d = egcd(a, M, x, y); // will give inverse of a as value of x. and gcd(a, M)
    int sol_x = x * (b/d); // IF d|b then solution exists. else not.
    sol_x = (sol_x%M + M) % M; // negative value safety.
    cout << sol_x;

    return 0;
}

/* here '=' is congruence
 * ax = b (mod M)  <= =>  7x = 2 (mod 31)
 * 1. find inverse of 7
 * 2. multiply both-side by that. with mod 31 ====> Done :D
 *
 * solve gives x [congruence to] 18 (mod 31)
 * x = 18 + 31k ( k = 0,1,2,... ) gives positive solution.
 *
 * short ===> for only one answer :- [taking k = 0]
 * x = x* * (b/d)     [ d = gcd (a, M) ]
*/
