#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b==0 ? a : gcd(b, a%b);
}

int lcm(int a, int b) {
    return (a*b) / gcd(a, b);
}

int main() {
    int a = 1, b = 200;
    cout << gcd(a, b) << "\n";
    //cout << lcm(a, b);

    return 0;
}
