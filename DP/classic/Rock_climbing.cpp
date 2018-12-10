#include <iostream>
#include <cstring>
using namespace std;

int r, c;
int mem[10][10];
int matrix[][10] = {
    {-1, 2, 5},
    {4, -2, 3},
    {1, 2, 10}
};

bool is_valid(int i, int j) {
    if (i>=r || j>=c || j<0)
        return false;
    return true;
}

int dp(int i, int j) {
    if (!is_valid(i, j)) return 0;

    if (mem[i][j] != -1) return mem[i][j];

    int v1 = matrix[i][j] + dp(i+1, j);
    int v2 = matrix[i][j] + dp(i+1, j-1);
    int v3 = matrix[i][j] + dp(i+1, j+1);

    return mem[i][j] = max(v1, max(v2, v3));
}

int main() {
    r = c = 3;
    memset(mem, -1, sizeof(mem));
    printf("%d\n", dp(0, 0));
    return 0;
}
