#include <iostream>
#include <cstring>

using namespace std;

long long mem[500][500] = {0};
long long get_nCr(int n, int r);

int main() {
    int n, r;
    scanf("%d %d", &n, &r);
    long long res = get_nCr(n, r);
    printf("%lld", res);

    return 0;
}

long long get_nCr(int n, int r) {
    if (r == 1) return n;
    if (n == r) return 1;

    if (mem[n][r] != 0) return mem[n][r];

    long long ret = get_nCr(n-1, r) + get_nCr(n-1, r-1);

    mem[n][r] = ret;
    return ret;
}
