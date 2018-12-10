#include <bits/stdc++.h>
using namespace std;

const double e = 2.71828182845904523536;
const double pi = 3.141592654;

long long findDigits(int n)
{
	if (n < 0) return 0; // -ve doesn't have factorial.
	if (n <= 1) return 1; // base case

	// Use Kamenetsky formula to calculate the number of digits
	//f(x) =    log10( ((n/e)^n) * sqrt(2*pi*n))
	double x = (n * log10(n / e) + log10(2 * pi * n) / 2.0);

	return floor(x) + 1;
}

// Driver Code
int main()
{
	cout << findDigits(1) << endl;
	cout << findDigits(50000000) << endl;
	cout << findDigits(1000000000) << endl;
	cout << findDigits(120) << endl;
	return 0;
}
