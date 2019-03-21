#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
#define inf 1e18
using namespace std;

/* source = 1 and destination = n

5 6
1 2 2
2 5 5
2 3 4
1 4 1
4 3 3
3 5 1

*/

struct Node {
    int value;
    Node() {}
    Node(int val) {
        value = val;
    }
};

long long d[1000006];
int parent[100010];
vector <int> adj[100010];
unordered_map <int, Node> g;
map <pair<int, int>, int> edgeCost;

bool operator < (Node a, Node b) {
    return d[a.value] > d[b.value];
}

void Dijkstra(int src, int dest)
{
    priority_queue <Node> q;
    d[src] = 0;
    q.push(g[src]);

    while (!q.empty()) {
        int u = q.top().value;
        q.pop();

        for (int v : adj[u]) {
            if (d[u] + edgeCost[{u, v}] < d[v]) {
                d[v] = d[u] + edgeCost[{u, v}];
                q.push(g[v]);
                parent[v] = u;
            }
        }
    }
}

void buildPath(int n) {
    if (n != 1)
        buildPath(parent[n]);
    printf("%d ", n);
}

int main() {
    FI;

    int n, m, a, b, w;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) g[i] = Node(i);
    fill(d, d+n+5, inf);

    while(m--) {
        cin >> a >> b >> w;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edgeCost[{a, b}] = w;
        edgeCost[{b, a}] = w;
    }

    Dijkstra(1, n);

    if (d[n] != inf) {
        buildPath(n);
        puts("");
    }
    else
        puts("-1");

    return 0;
}
