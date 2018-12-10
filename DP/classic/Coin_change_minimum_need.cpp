#include <iostream>
#include <cstring>
using namespace std;
#define INF 9999

int coin[50];
int dp(int i, int value);
int mem[50][1000];

int main() {
    memset(mem, -1, sizeof(mem));

    int value, num_of_coin;
    scanf("%d %d", &value, &num_of_coin);
    for (int i = 0; i < num_of_coin; i++)
        scanf("%d", &coin[i]);

    int min_need = dp(num_of_coin-1, value);

    printf("%d\n", min_need);

    return 0;
}

int dp(int i, int value) {
    if (value == 0) return 0;
    if (value < 0)  return INF;
    if (i == -1)    return INF;

    if (mem[i][value] != -1)
        return mem[i][value];

    int ans1 = dp(i-1, value);             // leave it.
    int ans2 = 1 + dp(i, value - coin[i]); // take it. have to use it repeatedly so instead of dp(i-1, value-coin[i]) we use dp(i, value-coin[i]).

    int ret = min(ans1, ans2);
    mem[i][value] = ret;

    return ret;
}
