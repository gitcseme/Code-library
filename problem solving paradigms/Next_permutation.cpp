#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

// n <= 11

int main() {
    vector<int> v = {1, 5, 3, 2, 4};
    sort(v.begin(), v.end());

    int c = 0;
    do {
        ++c;
        for (int i = 0; i < 5; i++)
            cout << v[i] << " ";
        cout << "\n";
    } while(next_permutation(v.begin(), v.end()));

    return 0;
}

