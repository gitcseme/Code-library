#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define all(ar) ar.begin(), ar.end()
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define FOR(v) for(int i : v) {cout << i << " ";} puts("");
#define CIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

string S;
int mem[1000][1000];
map<pair<int, int>, bool> Calculated;

bool IsPalindrome(int i, int j) {
    if (Calculated.count({i, j}))
        return Calculated[{i, j}];

    int a = i, b = j;
    while (i <= j) {
        if (S[i] != S[j]) {
            return Calculated[{a, b}] = false;
        }
        ++i, --j;
    }

    cout << "palindrome: " << a << ", " << b << "\n";
    return Calculated[{a, b}] = true;
}

/**
 * Theme: Set partition to every possible index and check.
*/

int solve(int i, int j) {
    if (i >= j || IsPalindrome(i, j))
        return 0;

    if (mem[i][j] != -1) return mem[i][j];

    int mini = 100000;
    for (int k = i; k < j; ++k) {
        int temp = solve(i, k) + solve(k+1, j) + 1;
        mini = min(mini, temp);
    }
    return mem[i][j] = mini;
}

int main() {
    memset(mem, -1, sizeof(mem));
    S = "abacada";

    int ans = solve(0, S.length()-1);
    cout << "Minimum partitions: " << ans << "\n";

    return 0;
}
