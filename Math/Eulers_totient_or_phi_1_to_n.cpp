#include <bits/stdc++.h>
using namespace std;

int phi[1000005];

void preCall(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!phi[i]) {
            for (int j = i; j <= n; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] = (phi[j] / i) * (i-1);
            }
        }
    }
}

int main() {
    int n; scanf("%d", &n);
    preCall(n);
    for (int i = 1; i <= n; ++i) printf("%d : %d\n", i, phi[i]);

    return 0;
}
