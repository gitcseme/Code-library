#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

/********
7 9
1 2 2
1 3 4
1 4 6
2 5 5
3 5 1
3 6 1
4 6 1
5 7 4
6 7 3
1
*********/

struct Node {
    int value, dist;
    bool vis;
    vector <int> adj;
    Node() {}
    Node (int v) {
        value = v;
        dist = 9999999;
        vis = false;
    }
};

map <int, Node> g;
map <pair<int, int>, int> edgeCost;

bool operator < (Node a, Node b) {
    return a.dist > b.dist;
}

void Dijkstra (int src) {
    priority_queue <Node> q;
    g[src].dist = 0;
    q.push(g[src]);

    while (!q.empty()) {
        int u = q.top().value;
        q.pop();

        cout << src << " " << u << " --> " << g[u].dist << "\n";

        for (int v : g[u].adj) {
            if (g[u].dist + edgeCost[{u, v}] < g[v].dist) {
                g[v].dist = g[u].dist + edgeCost[{u, v}];
            }
            if (!g[v].vis) {
                q.push(g[v]);
                g[v].vis = true;
            }
        }
    }
}

int main() {
    FI;

    int n, relations, a, b, cost, src;
    cin >> n >> relations;
    for (int i = 1; i <= n; ++i) g[i] = Node(i);

    for (int i = 1; i <= relations; ++i)
    {
        cin >> a >> b >> cost;
        g[a].adj.push_back(b);
        edgeCost[{a, b}] = cost;
    }

    // call Dijkstra algorithm
    cin >> src;
    Dijkstra(src);

    return 0;
}
