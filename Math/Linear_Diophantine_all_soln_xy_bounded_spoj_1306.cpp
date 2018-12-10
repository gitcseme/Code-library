#include <bits/stdc++.h>
typedef long long Long;
using namespace std;

Long extEuclid(Long a, Long b, Long &x0, Long &y0) {
    if (b == 0) {
        x0 = 1; y0 = 0;
        return a;
    }
    Long x1, y1;
    Long d = extEuclid(b, a%b, x1, y1);
    x0 = y1;
    y0 = x1 - (a/b)*y1;
    return d;
}

Long find_all_solutions(Long a, Long b, Long c, Long x1, Long x2, Long y1, Long y2) {
    Long x0, y0, g;
    g = extEuclid(a, b, x0, y0);
    if (!a && !b) {
        if (c) return 0;
        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }
    else if (!a) {
        if (c % b) return 0;
        if (c/b >= y1 && c/b <= y2) return (x2 - x1 + 1);
        return 0;
    }
    else if (!b) {
        if (c % a) return 0;
        if (c/a >= x1 && c/a <= x2) return (y2 - y1 + 1);
        return 0;
    }
    else {
        if (c % g) return 0;
        x0 *= c/g; y0 *= c/g;

        double tx1 = (x1 - x0) * (double)g/b;
        double tx2 = (x2 - x0) * (double)g/b;
        if (tx1 > tx2) swap(tx1, tx2);
        tx1 = (Long) ceil(tx1);
        tx2 = (Long) floor(tx2);

        double ty1 = (y0 - y1) * (double)g/a;
        double ty2 = (y0 - y2) * (double)g/a;
        if (ty1 > ty2) swap(ty1, ty2);
        ty1 = (Long) ceil(ty1);
        ty2 = (Long) floor(ty2);

        Long t1 = max(tx1, ty1);
        Long t2 = min(tx2, ty2);
        return max(0LL, t2 - t1 + 1);
    }
}

int main () {
    //freopen("zzz.txt", "r", stdin);
    int T, a, b, c, x1, x2, y1, y2, cse = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &x1, &x2, &y1, &y2);
        printf("Case %d: %lld\n", ++cse, find_all_solutions(a, b, -c, x1, x2, y1, y2));
    }

    return 0;
}
