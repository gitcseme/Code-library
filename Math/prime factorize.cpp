#include <bits/stdc++.h>
using namespace std;

#define N 35000
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

vector <int> factors;
void factorize (int n) {
    for (int i = 0; (long long)primes[i] * primes[i] <= n; ++i) {
        if (n % primes[i] == 0) {
            while (n % primes[i] == 0) {
                factors.push_back(primes[i]);
                n = n / primes[i];
            }
        }
    }
    if (n > 1) factors.push_back(n);
}

int main() {
    sieve();
    int n;
    cin >> n;
    factorize(n);

    for (int x : factors) cout << x << " ";
    cout << "\n";
}
