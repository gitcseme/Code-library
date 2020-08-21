#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(int i : v) {cout << i << " ";} puts("");
#define CIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

/**
    Unbounded Knapsack
*/
const int maxn = 1000;
int N;
vector<int> len;;
vector<int> price;
int mem[maxn][maxn];

int dp(int i, int x) {
    if (x == 0) return 0;
    if (i == N) return 0;

    if (mem[i][x] != -1) return mem[i][x];

    int a = 0, b = 0;
    if (len[i] <= x)
        a = price[i] + dp(i, x - len[i]);

    b = dp(i + 1, x);

    return mem[i][x] = max(a, b);
}

int main() {
    memset(mem, -1, sizeof(mem));
    int Length = 8;
    N = 4;
    len =   {1, 2, 3, 4};
    price = {1, 3, 5, 6};

    cout << dp(0, Length) << "\n";


    return 0;
}
