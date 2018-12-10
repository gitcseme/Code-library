#include <iostream>
#include <cstring>

using namespace std;

long long mem[1000];
long long fib(int n);
long long fibLoop(int n);

int main() { ios::sync_with_stdio(0); cin.tie(0);

    memset(mem, -1, sizeof(mem));
    int n;
    scanf("%d", &n);

    long long nthFib = fib(n);
    printf("Dynamic : %lld\n", nthFib);
    printf("\n");
    nthFib = fibLoop(n);
    printf("Loop : %lld\n", nthFib);

    return 0;
}

long long fib(int n) {
    if (n < 2)
        return n;

    if (mem[n] != -1)
        return mem[n];

    long long ret = fib(n-1) + fib(n-2);

    mem[n] = ret;
    return ret;
}

long long fibLoop(int n) {
    long long f[1000];
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
        f[i] = f[i-1] + f[i-2];

    return f[n-1];
}
