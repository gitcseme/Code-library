#include <bits/stdc++.h>
using namespace std;

int N = 100;
int status[100/32 + 2];
vector<int> primes;

bool check(int n, int pos) { return n & (1<<pos); }
int on(int n, int pos) { return n = n | (1<<pos); }

void bitwise_sieve() {
    int sqrtN = (int)sqrt((double)N) + 1;
    for (int i = 3; i <= sqrtN; i += 2)
        if ( check(status[i/32], i%32) == 0 )
            for (int j = i*i; j <= N; j += 2*i)
                status[j/32] = on(status[j/32], j%32);

    primes.push_back(2);
    for (int i = 3; i <= N; i += 2)
        if (check(status[i/32], i%32) == 0)
            primes.push_back(i);
}

int main() {

    bitwise_sieve();

    for(int p : primes)
        cout << p << " ";

    return 0;
}
