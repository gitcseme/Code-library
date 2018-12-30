#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

/*
N no. of edge weight
- ----------- ------
6 9
1 5 4
1 4 1
1 2 2
2 4 3
2 3 3
2 6 7
3 6 8
3 4 5
4 5 9

*/

int parent[1000], renk[1000];

int find_parent(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_parent(parent[v]); // with path compression
}

void make_set(int v) {
    parent[v] = v;
    renk[v] = 0;
}

void union_sets(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a != b) {
        if (renk[a] < renk[b])
            swap(a, b);
        parent[b] = a;
        if (renk[a] == renk[b])
            renk[a]++;
    }
}

struct Edge {
    int u, v, weight;
    Edge(int uu, int vv, int ww) {
        u = uu;
        v = vv;
        weight = ww;
    }
    bool operator <(Edge &other) {
        return weight < other.weight;
    }
};

vector <Edge> edges, result;

int main() {
    FI;
    int n, connectons, u, v, w, tot_cost = 0;
    cin >> n >> connectons;

    for (int i = 1; i <= n; ++i) make_set(i);

    for (int i = 0; i < connectons; ++i) {
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (find_parent(e.u) != find_parent(e.v)) { // they are not in same component.
            tot_cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }

    // Output
    cout << "MST cost is " << tot_cost << "\n";
    for (Edge e : result)
        cout << e.u << " " << e.v << " " << e.weight << "\n";

    return 0;
}
