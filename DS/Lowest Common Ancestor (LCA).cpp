#include <bits/stdc++.h>
using namespace std;

const int nax = 1000;
vector<int> g[nax];
int L[nax];
int T[nax];
int P[nax][22]; // sparse table

void bfs(int src) {
    queue<int> q;
    q.push(src);
    L[src] = 0;
    T[src] = -1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            L[v] = 1 + L[u];
            T[v] = u;
            q.push(v);
        }
    }
}

void build_sparse_table(int N) {
    memset(P, -1, sizeof(P));
    for (int i = 0; i < N; ++i) P[i][0] = T[i]; // base case. 2^0th parent

    // Build table with DP
    for (int j = 1; (1 << j) < N; ++j)
        for (int i = 0; i < N; ++i)
            if (P[i][j-1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
}

int lca(int a, int b) {
    if (L[a] < L[b]) swap(a, b);
    int log = floor(log2(L[a])) + 1;

    // pull L[a] = L[b]
    for (int j = log; j >= 0; --j) {
        if (L[a] - (1 << j) >= L[b])
            a = P[a][j];
    }

    if (a == b) return a;

    // pull both to LCA.
    for (int j = log; j >= 0; --j) {
        if (P[a][j] != -1 && P[a][j] != P[b][j]) {
            a = P[a][j];
            b = P[b][j];
        }
    }
    return T[a]; // 1st parent of a is LCA.
}

int main() {
    g[0].push_back(1);
    g[0].push_back(2);
    g[1].push_back(5);
    g[2].push_back(3);
    g[2].push_back(4);

    bfs(0);
    build_sparse_table(6);
    int ans = lca(3, 1);

    cout << ans << "\n";

    return 0;
}
