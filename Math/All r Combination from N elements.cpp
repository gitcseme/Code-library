#include <bits/stdc++.h>
using namespace std;

char c[5];

void backtrack (int i, string ans) {

    if (ans.size() == 2) {
        cout << ans << "\n";
        return;
    }
    if (i == 3) return;

    backtrack(i+1, ans);
    ans += c[i];
    backtrack(i+1, ans);
    ans.erase(ans.size()-1);
}

int main () {

    c[0] = 'a'; c[1] = 'b'; c[2] = 'c';
    backtrack(0, "");

    return 0;
}
