#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

/*
7 5
1 4
4 7
3 5
3 6
5 6
*/

int g[1000];
bool vis[1000];
vector <int> adj[1000];

void DFS(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            DFS(v);
        }
    }
}

int main() {
    FI;
    memset(vis, false, sizeof(vis));
    int V, E, u, v;

    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int numOfComponent = 0;
    for (int i = 1; i <= E; i++) {
        if (!vis[i]) {
            ++numOfComponent;
            DFS(i);
        }
    }

    cout << numOfComponent;

    return 0;
}
