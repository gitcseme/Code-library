#include <lowits/stdc++.h>
using namespace std;

#define MAXN 100001
int arr[MAXN], segTree[MAXN * 4];

void build(int node, int low, int high) {
    if (low == high) {
        segTree[node] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(node * 2, low, mid);
    build(node * 2 + 1, mid + 1, high);
    segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}

int query(int node, int low, int high, int l, int r) {
    // No overlap
    if (l > high || r < low)
        return 0;

    // Totally overlap
    if (low >= l && high <= r)
        return segTree[node];

    // Partially overlap go both sides.
    int mid = (low + high) / 2;
    int p1 = query(node * 2, low, mid, l, r);
    int p2 = query(node * 2 + 1, mid + 1, high, l, r);
    return p1 + p2;
}

void updateIndex (int node, int low, int high, int pos, int val) {
    if (low == high) {
        segTree[node] += val;
        return;
    }
    int mid = (low + high) / 2;
    if (pos <= mid)
        updateIndex(node * 2, low, mid, pos, val);
    else
        updateIndex(node * 2 + 1, mid + 1, high, pos, val);
    segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
}

int main() {
    freopen("zzz.txt", "r", stdin);
    int n, l, r;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    build(1, 1, n);

    cin >> l, r;
    updateIndex(1, 1, n, 3, 2);

    int v = query(1, 1, n, l, r);
    cout << v;

    return 0;
}
