#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector <int> edges[MAXN];
int parent[MAXN], mem[MAXN][3];

int dp (int u, int isGuard) {
    if (edges[u].size() == 0) return 0; // base and special case.

    if (mem[u][isGuard] != -1) return mem[u][isGuard];

    int sum = 0;
    for (int i = 0; i < edges[u].size(); ++i)
    {
        int v = edges[u][i];
        if (v != parent[u]) {
            parent[v] = u;
            if (isGuard == 0)
                sum += dp(v, 1);
            else
                sum += min(dp(v, 1), dp(v, 0)); // take both and min of them.
        }
    }
    return mem[u][isGuard] = sum + isGuard; // isGuard because there is guard or not in current node.
}

int main () {
    memset(mem, -1, sizeof(mem));
    int N, u, v;
    scanf("%d", &N);
    for (int i = 0; i < N-1; ++i) {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int ans = min(dp(1, 1), dp(1, 0));
    printf("%d\n", ans);

    return 0;
}
