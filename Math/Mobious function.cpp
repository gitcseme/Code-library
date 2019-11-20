#include <bits/stdc++.h>
using namespace std;

#define N 111100
bool mark[N];
int mu[N];

void Eratosthenes() {
    for (int i = 1; i <= N; ++i) mu[i] = 1;

    for (int i = 2; i <= N; ++i) {
        if (!mark[i]) {
            mu[i] = -mu[i];
            for (int j = 2; i * j <= N; ++j) {
                mark[i*j] = true;
                if (j % i == 0) {
                    mu[i * j] = 0; // not Square free.
                }
                else {
                    mu[i * j] = -mu[i * j];
                }
            }
        }
    }
}

int main() {
    Eratosthenes();

    for (int i = 1; i <= 50; ++i)
        cout << i << " " << mu[i] << "\n";

}
