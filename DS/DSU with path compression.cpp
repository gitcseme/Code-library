#include <bits/stdc++.h>
using namespace std;

int parent[1000];

void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]); // with path compression
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

int main () {
    freopen("zzz.txt", "r", stdin);
    int n, q, a, b;
    cin >> n;
    for (int i = 1; i <= n; ++i) make_set(i);

    cin >> q;
    while (q--) {
        cin >> a >> b;
        union_sets(a, b);
    }

    for (int i = 1; i <= n; ++i)
        cout << i << " ==> " << parent[i] << "\n";

    return 0;
}
