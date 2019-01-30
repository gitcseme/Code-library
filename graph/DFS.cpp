#include <bits/stdc++.h>
#define FI freopen("inp.txt", "r", stdin);
using namespace std;

/*
6 7
1 3
2 1
2 4
3 5
3 6
4 1
5 6
*/

int E, V;
vector <int> g[100];
bool vis[100];

void dfs (int u) {
    cout << u << " ";
    vis[u] = true;

    for (int v : g[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main () {
    FI;

    cin >> V >> E;
    int u, v;
    for (int i = 1; i <= E; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
    }
    memset(vis, false, sizeof(vis));
    dfs(2);

    return 0;
}
