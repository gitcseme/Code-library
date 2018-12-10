#include <iostream>
#include <cstring>

using namespace std;

int m, n;
char a[1000], b[1000], dummy[2];
int mem[1000][1000];

int dp(int i, int j) {
    if (i == m || j == n) return 0;

    if (mem[i][j] != -1) return mem[i][j];

    int ans = 0;
    if (a[i] == b[j])
        ans = 1 + dp(i+1, j+1);  // a match found.
    else {
        int ans1 = dp(i+1, j); // leave first take second.
        int ans2 = dp(i, j+1); // leave second take first.
        ans = max(ans1, ans2);
    }

    return mem[i][j] = ans;
}

string P = "";
void printPath(int i, int j) {
    if (i == m || j == n) {
        printf("LCS : %s\n", P.c_str());
        return;
    }
    if (a[i] == b[j]) {
        P += a[i];
        printPath(i+1, j+1);
    }
    else {
        if (mem[i+1][j] > mem[i][j+1]) printPath(i+1, j);
        else printPath(i, j+1);
    }
}

string S = ""; int cnt = 0;
void all_LCS(int i, int j) {
    if (i == m || j == n) {
        printf("%d : %s\n", ++cnt, S.c_str());
        return;
    }
    if (a[i] == b[j]) {
        S += a[i];
        all_LCS(i+1, j+1);
        S.erase(S.end() - 1); // Delete last character.
    }
    else {
        if (mem[i+1][j] > mem[i][j+1]) all_LCS(i+1, j);
        else if (mem[i+1][j] < mem[i][j+1]) all_LCS(i, j+1);
        else {
            all_LCS(i+1, j);
            all_LCS(i, j+1);
        }
    }
}

int main() {
    memset(mem, -1, sizeof(mem));
    scanf("%d %d", &m, &n); gets(dummy);
    gets(a);
    gets(b);

    int lcs = dp(0, 0);
    printf("Length : %d\n", lcs);
    printPath(0, 0);
    printf("\n");
    all_LCS(0, 0);

    return 0;
}
