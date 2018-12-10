#include <bits/stdc++.h>
using namespace std;

#define N 1000000
vector<int> primes;
bool mark[N];

void Eratosthenes() {
    for(int i = 3; i * i <= N; i += 2)
        if (!mark[i])
            for (int j = i * i; j <= N; j += 2*i)
                mark[j] = true;

    primes.push_back(2);
    for (int i = 3; i <= N; i += 2)
        if (!mark[i])
            primes.push_back(i);
}

int main() {
    Eratosthenes();

    for (int i = 0; i <= 100; ++i)
        cout << primes[i] << "\n";

    return 0;
}
