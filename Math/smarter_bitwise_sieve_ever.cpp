#include <bits/stdc++.h>
using namespace std;

#define N 1000000
#define check(n, pos) (n & (1<<pos))
#define on(n, pos) (n | (1<<pos))
int status[N/64 + 2];
vector<int> primes;

void sieve() {
    int sqrtN = (int)sqrt((double)N) + 1;
    for (int i = 3; i <= sqrtN; i += 2)
        if ( check(status[i>>6], ((i>>1) & 31)) == 0)
            for (int j = i*i; j <= N; j += 2*i)
                status[j>>6] = on(status[j>>6], ((j>>1) & 31));

    primes.push_back(2);
    for (int i = 3; i <= N; i += 2)
        if ( check(status[i>>6], ((i>>1) & 31)) == 0)
            primes.push_back(i);
}

bool isPrime(int n) {
    if (n == 2) return true;
    if (n < 2 || !(n&1)) return false;
    return check(status[n>>6], ((n>>1) & 31)) == 0;
}

int main() {
    sieve();
    cout << primes.size();
    /*
    for (int p : primes)
        cout << p << " ";
    */
    return 0;
}

