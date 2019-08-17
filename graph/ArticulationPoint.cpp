#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;
/*
6 7
0 1
0 2
1 2
2 3
3 4
3 5
4 5
*/
const int mx = 1000;
vector<int> adj[mx];
int d[mx], low[mx], timer = 0;

set<int> AP;

void DFS(int u, int p)
{
    low[u] = d[u] = timer++;
    int childCount = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (d[v] != -1) { // Back edge
            low[u] = min(low[u], d[v]);
        }
        else {
            DFS(v, u);
            low[u] = min(low[u], low[v]); // Take update
            if (low[v] >= d[u] && p != -1) {
                AP.insert(u);
            }
            ++childCount;
        }
    }
    if (p == -1 && childCount > 1) {
        AP.insert(u);
    }
}

int main() {
    FI;
    memset(d, -1, sizeof(d));
    int n, e, u, v;

    cin >> n >> e;
    for (int i = 0; i < e; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int u = 0; u < n; ++u) {
        if (d[u] == -1) {
            DFS(u, -1);
        }
    }

    // Print bridges
    for (int p : AP) {
        cout << p << "\n";
    }

    return 0;
}
