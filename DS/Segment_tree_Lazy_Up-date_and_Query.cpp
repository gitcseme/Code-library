#include <bits/stdc++.h>
using namespace std;

#define INF 200000000
int arr[100005], segTree[400005];
int lazy[400005];

void build(int node, int b, int e) { // build Minimum tree.
    if (b == e) {
        segTree[node] = arr[b];
        return;
    }
    int mid = (b + e) / 2;
    build(node * 2, b, mid);
    build(node * 2 + 1, mid + 1, e);
    segTree[node] = min ( segTree[node * 2], segTree[node * 2 + 1] );
}

int query(int node, int b, int e, int l, int r)
{
    if (l > e || r < b) {
        return INF; // Not relevant
    }
    if (b >= l && e <= r) return segTree[node]; // Relevant
    // Partially relevant goo deep.
    int mid = (b + e) / 2;
    int p1 = query(node * 2, b, mid, l, r);
    int p2 = query(node * 2 + 1, mid + 1, e, l, r);
    return min(p1, p2);
}

void LazyUpdateRange(int node, int low, int high, int l, int r, int val) {
    if (low > high) {
        return;
    }
    /* make sure all propagation is done. If not then update current node
       and give the propagation value to children [expanding pending update] */
    if (lazy[node] != 0) {
        segTree[node] += lazy[node];
        if (low != high) { // If internal node
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0; // propagation update done.
    }
    // No overlap
    if (l > high || r < low) {
        return;
    }
    // Total overlap
    if (l <= low && high <= r) {
        segTree[node] += val;
        if (low != high) {
            lazy[2 * node] += val;
            lazy[2 * node + 1] += val;
        }
        return;
    }
    // Otherwise partial update and go both side.
    int mid = (low + high) / 2;
    LazyUpdateRange(2 * node, low, mid, l, r, val);
    LazyUpdateRange(2 * node + 1, mid+1, high, l, r, val);
    segTree[node] = min( segTree[2 * node], segTree[2 * node + 1] );
}

int LazyQueryRange(int node, int low, int high, int l, int r) {
    if (low > high) {
        return INF;
    }
    /* make sure all propagation is done. If not then update current node
       and give the propagation value to children [expanding pending update] */
    if (lazy[node] != 0) {
        segTree[node] += lazy[node];
        if (low != high) { // If internal node
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0; // propagation update done.
    }
    // No overlap
    if (l > high || r < low) {
        return INF;
    }
    // Total overlap
    if (l <= low && high <= r) {
        return segTree[node];
    }
    // Partial overlap take both side.
    int mid = (low + high) / 2;
    return min ( LazyQueryRange(2 * node, low, mid, l, r), LazyQueryRange(2 * node + 1, mid+1, high, l, r));
}

int main() {
    freopen("zzz.txt", "r", stdin);
    int N, q, l, r;

    cin >> N >> q;
    for (int i = 1; i <= N; ++i) cin >> arr[i];
    build(1, 1, N);

    cin >> l >> r;
    LazyUpdateRange(1, 1, 4, 1, 4, 2);
    LazyUpdateRange(1, 1, 4, 3, 3, 4);
    printf("%d\n", query(1, 1, N, l, r));
    printf("%d\n", LazyQueryRange(1, 1, N, 2, 3));

    return 0;
}
