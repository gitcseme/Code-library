#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(int i : v) {cout << i << " ";} puts("");
#define CIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

vector<int> Len;
vector<int> Price;
int mem[100][100];

int dp(int i, int j) {
    if (i == 0 || j == 0) return 0;

    if (mem[i][j] != -1) return mem[i][j];

    if (Len[i-1] <= j)
        mem[i][j] = max(Price[i-1] + dp(i, j - Len[i-1]), dp(i-1, j));
    else
        mem[i][j] = dp(i-1, j);

    return mem[i][j];
}

int main() {
    memset(mem, -1, sizeof(mem));

    int RodLen = 8;
    int N = 8;
    Len =   {1, 2, 3, 4, 5, 6, 7, 8};
    Price = {1, 5, 8, 9, 10, 17, 17, 20};

    cout << "Max profit: " << dp(8, RodLen) << "\n\n";

    // Top-down
    int DP[100][100];
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= RodLen; ++j) {
            if (i == 0 || j == 0) {
                DP[i][j] = 0;
                continue;
            }
            if (Len[i-1] <= j)
                DP[i][j] = max(Price[i-1] + DP[i][j-Len[i-1]], DP[i-1][j]);
            else
                DP[i][j] = DP[i-1][j];
        }
    }
    cout << "Max profit: " << DP[N][RodLen] << "\n";

    return 0;
}
