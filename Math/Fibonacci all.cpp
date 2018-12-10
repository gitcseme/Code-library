#include <bits/stdc++.h>
using namespace std;

int n;

/* Fibonacci series using recursion
int F(int n) {
    if (n <= 1)
        return n;
    return F(n-1) + F(n-2);
}
*/

/* Using dynamic programming
int F(int n) {
    int f[n+2];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; ++i)
        f[i] = f[i-1] + f[i-2];

    return f[n];
}
*/

void multiply_2x1 (int I[2][2], int f[2])
{
    int x = I[0][0]*f[0] + I[0][1]*f[1];
    int y = I[1][0]*f[0] + I[1][1]*f[1];
    f[0] = x;
    f[1] = y;
}

void multiply_2x2 (int F[2][2], int M[2][2])
{
  int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
  int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
  int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
  int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

/* Matrix Exponentiation O(n)    |  F(n) = I^(n-1) * F
int F(int n) {
    int I[2][2] = {
            {1, 1},
            {1, 0}
        };
    int f[2] = {1,
                0};
    for (int i = 0; i < n-1; ++i)
        multiply_2x1(I, f);

    return f[0];
}
*/

/* Using Matrix exponentiation in O(log(n))
   Goal : raise the power of I^n in log(n) time by fast exponentiation  */
int M[2][2] = {
        {1, 1},
        {1, 0}
    };

void power(int I[2][2], int x) {
    if (x <= 1)
        return;

    power(I, x/2);
    multiply_2x2(I, I);

    if (x%2 == 1)
        multiply_2x2(I, M);
}

int F(int n) {
    int I[2][2] = {
            {1, 1},
            {1, 0}
        };
    int f[2] = {1, 0};

    power(I, n-1);        // raise I^(n-1)
    multiply_2x1(I, f);   // I^(n-1) * f

    return f[0];
}


int main () {
    n = 7;
    printf("%d", F(n));

    return 0;
}
