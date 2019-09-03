#include <bits/stdc++.h>
#define FI freopen("inp.txt", "r", stdin)
using namespace std;

const int n = 5;
int a[n] = {1, 2, 3, 4, 5};
bool take[n];

void backtrack(int i) {
    if (i == n) {
        for (int i = 0; i < n; i++) {
            if (take[i])
                printf("%d ", a[i]);
        }
        printf("\n");
    }
    else {
        take[i] = true;
        backtrack(i + 1);

        take[i] = false;
        backtrack(i + 1);
    }
}

int main () {
    backtrack(0);

    return 0;
}
