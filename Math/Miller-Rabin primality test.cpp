#include <bits/stdc++.h>
using namespace std;

int bigmod(int a, int b, int M) {
    if (b == 0)
        return 1 % M;
    int x = bigmod(a, b/2, M);
    x = (x * x) % M;
    if (b & 1) x = (x * a) % M;
    return x;
}

bool miillerTest(int d, int n) {
	int a = 2 + rand() % (n - 4); // random a.

	int x = bigmod(a, d, n);
	if (x == 1 || x == n-1) return true; // prime

	// iterate r times. r as 2^r
	while (d != n-1) {
		x = (x * x) % n;
		d *= 2;

		if (x == 1)	 return false;
		if (x == n-1) return true;
	}
	return false; 	// composite
}

bool isPrime(int n, int k) {
	if (n <= 1 || n == 4) return false;
	if (n <= 3) return true;

	// Find r such that n - 1 = 2^r * d for some r > 0
	int d = n - 1;
	while (d % 2 == 0) d /= 2;

	// Iterate  k times.
	for (int i = 0; i < k; i++) if (miillerTest(d, n) == false) {
        return false;
	}
	return true;
}

int main() {
	int k = 4; // Number of iterations

	for (int n = 1; n < 100; n++)
        if (isPrime(n, k))
            cout << n << " ";

	return 0;
}
