#include <bits/stdc++.h>
using namespace std;

long long ncr[1002][1002];
int MAXN = 1000;

void get_nCr() {
    ncr[0][0] = 1;
    for (int i = 1; i <= MAXN; ++i) {
        for (int j = 0; j <= MAXN; ++j) {
            if (j > i) ncr[i][j] = 0;
            else if (j == i || j == 0) ncr[i][j] = 1;
            else ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
        }
    }
}

int main() {
    get_nCr();

    //test
    int n, r;
    while (cin >> n >> r) {
        cout << ncr[n][r] << "\n";
    }
}
