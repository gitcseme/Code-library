#include <bits/stdc++.h>
using namespace std;

int parent[1000], renk[1000];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]); // with path compression
}

void make_set(int v) {
    parent[v] = v;
    renk[v] = 0;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (renk[a] < renk[b])
            swap(a, b);
        parent[b] = a;
        if (renk[a] == renk[b])
            renk[a]++;
    }
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
