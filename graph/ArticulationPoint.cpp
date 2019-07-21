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
int d[mx], low[mx], timer = 0, childCount;

set<int> AP;

void find_bridge(int u, int p)
{
    low[u] = d[u] = timer++;
    childCount = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (d[v] == -1) {
            ++childCount; // child which has no connection to other child is counted as a new child.
            find_bridge(v, u);
            low[u] = min(low[u], low[v]); // Take update from v
        }
        else { //Back edge encountered.
            low[u] = min(low[u], d[v]);
        }

        if (low[v] >= d[u]) {
            if (p == -1) { // root node.
                if (childCount >1)
                    AP.insert(u);
            }
            else
                AP.insert(u);
        }
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
            find_bridge(u, -1);
        }
    }

    // Print bridges
    for (int p : AP) {
        cout << p << "\n";
    }

    return 0;
}
