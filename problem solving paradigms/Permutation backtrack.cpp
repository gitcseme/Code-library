#include <bits/stdc++.h>
#define FI freopen("inp.txt", "r", stdin)
using namespace std;

const int n = 3;
int a[n] = {5, 2, 3};
int p[n];
bool take[n];

void backtrack(int i) {
    if (i == n) {
        for (int j = 0; j < n; ++j)
            printf("%d ", p[j]);
        printf("\n");
    }
    else {
        for (int j = 0; j < n; ++j) {
            if (!take[j]) {
                take[j] = true;  // DO move
                p[i] = a[j];

                backtrack(i + 1);

                take[j] = false; // Undo move
            }
        }
    }
}

int main () {
    backtrack(0);

    return 0;
}
