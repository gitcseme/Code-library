#include <bits/stdc++.h>
using namespace std;

#define N 1000
int status[N/64 + 2];
vector<int> primes;

bool check(int n, int pos) { return (bool)(n & (1<<pos)); }
int on(int n, int pos) { return (n | (1<<pos)); }

void sieve() {
    int sqrtN = (int)sqrt((double)N) + 1;
    for (int i = 3; i <= sqrtN; i += 2)
        if ( check(status[i/64], (i/2)%32) == 0)
            for (int j = i*i; j <= N; j += 2*i)
                status[j/64] = on(status[j/64], (j/2)%32);

    primes.push_back(2);
    for (int i = 3; i <= N; i += 2)
        if ( check(status[i/64], (i/2)%32) == 0)
            primes.push_back(i);
}


int main() {
    sieve();
    for (int p : primes)
        cout << p << " ";

    return 0;
}
