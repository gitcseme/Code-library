#include <bits/stdc++.h>
using namespace std;

int M, N, mem[2005][2005];
char A[2005], B[2005], dummy[2];

int dp (int i, int j)
{
    if (i == M && j == N) return 0;
    else if(i == M) return (N-j);
    else if(j == N) return (M-i);

    if (mem[i][j] != -1) return mem[i][j];

    int ans = 0;
    if (A[i] == B[j])
        ans = dp(i+1, j+1);
    else                 // insert      delete       replace
        ans = 1 + min ( min(dp(i, j+1), dp(i+1, j)), dp(i+1, j+1) );

    return mem[i][j] = ans;
}

int main() {
    int t;
    scanf("%d", &t); gets(dummy);

    while (t--) {
        memset(mem, -1, sizeof(mem));
        gets(A);
        gets(B);
        M = strlen(A);
        N = strlen(B);
        printf("%d\n", dp(0, 0));
    }

    return 0;
}
