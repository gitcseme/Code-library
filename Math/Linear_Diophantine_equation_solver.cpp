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
    y = x1 - (a/b)*y1;
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = ext_Euclid(abs(a), abs(b), x0, y0);
    if (c % g != 0)
        return false;
    x0 = x0 * c/g;
    y0 = y0 * c/g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int main() {
    // ax + by = c.
    int a, b, c, x, y ,g;
    cin >> a >> b >> c;
    if(find_any_solution(a, b, c, x, y, g))
        cout << x << " " << y << " " << g << "\n";
    else
        cout << "No solution\n";

    return 0;
}
