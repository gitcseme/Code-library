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
 * Theme: Set bracket(k) to every possible index and check.
*/

vector<int> a;

int mem[1000][1000];

int solve(int i, int j) {
    if (i >= j) return 0;

    if (mem[i][j] != -1) return mem[i][j];

    int mini = INT_MAX;
    for (int k = i; k < j; ++k) {
        int temp = solve(i, k) + solve(k+1, j) + (a[i-1] * a[k] * a[j]);
        mini = min(mini, temp);
    }
    return mem[i][j] = mini;
}

int main() {
    memset(mem, -1, sizeof(mem));

    a = {40, 20, 30, 10, 30};

    int ans = solve(1, a.size()-1);
    cout << "Minimum cost: " << ans << "\n";

    return 0;
}
