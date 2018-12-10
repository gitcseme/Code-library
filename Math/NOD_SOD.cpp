#include <bits/stdc++.h>
using namespace std;
#define N 100000
bool mark[N];
vector<int> primes;

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
    int n, d, cnt, NOD = 1, SOD = 1;
    cin >> n;
    Eratosthenes();

    d = n;
    for (int p : primes) {
        if (p * p > d) break;
        if (n % p == 0) {
            cnt = 0;
            while (n % p == 0) {
                n = n / p;
                ++cnt;
            }
            NOD = NOD * (cnt+1);
            SOD = SOD * (pow(p, cnt+1) - 1) / (p-1);
        }
    }
    if (n > 1) {
        NOD = NOD * 2;
        SOD = SOD * (round((pow(n, 2)) - 1) / (n-1));
    }
    cout << "NOD : " << NOD << "\n" << "SOD : " << SOD << "\n";

    return 0;
}
