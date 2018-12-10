#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
map<int, vector<int> > edges;
map<int, int> parent;
int mem[MAXN][3];

int dp (int u, int isGuard) {
    if (edges[u].size() == 0) return 0;

    if (mem[u][isGuard] != -1) return mem[u][isGuard];

    int ans = 0;
    for (int i = 0; i < edges[u].size(); ++i)
    {
        int v = edges[u][i];
        if (v != parent[u]) {
            parent[v] = u;
            if (isGuard == 0)
                ans += dp (v, 1);
            else
                ans += min(dp(v, 1), dp(v, 0));
        }
    }
    return mem[u][isGuard] = ans + isGuard;
}

int main () {
    freopen("inp.txt", "r", stdin);
    int N, n, v ;
    while (scanf("%d", &N) && N) {
        memset(mem, -1, sizeof(mem));

        for (int u = 1; u <= N; ++u) {
            scanf("%d", &n);
            for (int i = 0; i < n; ++i) {
                scanf("%d", &v);
                edges[u].push_back(v);
            }
        }
        int ans = max(1, min(dp(1, 1), dp(1, 0)) );
        printf("%d\n", ans);
        edges.clear();
        parent.clear();
    }

    return 0;
}
