#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define INF 9999

int knapsack(int i, int sack);
int p[100];
int w[100];
int mem[100][100];
int path[100][100];

int main() {
    memset(mem, -1, sizeof(mem));
    memset(path, -1, sizeof(path));

    int num_of_products, sack_size;
    scanf("%d %d", &num_of_products, &sack_size);

    for (int i = 0; i < num_of_products; i++)
        scanf("%d %d", &p[i], &w[i]);

    int max_benifit = knapsack(num_of_products-1, sack_size);
    printf("%d\n", max_benifit);

    /* Result printing */
    int i = num_of_products-1, sack = sack_size;
    while (i >= 0 && sack >= 0) {
        if (path[i][sack] == 2) {
            printf("%d %d\n", p[i], w[i]);
            sack = sack - w[i];
        }
        --i;
    }

    return 0;
}

int knapsack(int i, int sack) {
    if (sack < 0) return -INF;
    if (i < 0) return 0;

    if (mem[i][sack] != -1) return mem[i][sack];

    int ans1 = knapsack(i-1, sack);
    int ans2 = p[i] + knapsack(i-1, sack - w[i]); // knapsack(i, sack-w[i]) for taking item i multiple times.

    if(ans1 > ans2) path[i][sack] = 1;
    else path[i][sack] = 2;

    return mem[i][sack] = max(ans1, ans2);
}
