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

bool mark[100005];
void segment_sieve(int L, int R) {
    for (int p : primes) {
        if ((long long)p * p > R) break;
        // take base just smaller or equal to L.
        int base = (L/p) * p;
        if (base < L) base += p;

        for (int j = base; j <= R; j += p)
            mark[j - L] = true;
        // when base holding a prime;  Only happens when (L < p).
        if (base == p) mark[base - L] = false;
    }
    if (L == 1) mark[0] = true;
}

int main() {
    sieve();
    int T, L, R;
    scanf("%d", &T);
    while (T--) {
        memset(mark, false, sizeof(mark));
        scanf("%d %d", &L, &R);
        segment_sieve(L, R);
        for (int i = 0; i <= (R-L); ++i)
            if(!mark[i])
                printf("%d\n", L+i);
        if(T > 0)
            puts("");
    }

    return 0;
}
