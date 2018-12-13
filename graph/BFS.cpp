#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

vector <int> g[MAXN];
bool vis[MAXN];
int level[MAXN];

void BFS (int source) {
    queue <int> q;
    q.push(source);
    vis[source] = true;
    level[source] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        printf("%d ", u); // traverse order level by level.

        for (int v : g[u]) {
            if (!vis[v]) {
                level[v] = level[u] + 1;
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

int main () {

    //create graph;
    g[1].push_back(2);
    g[1].push_back(4);
    g[1].push_back(3);
    g[2].push_back(1);
    g[2].push_back(6);
    g[4].push_back(1);
    g[4].push_back(7);
    g[3].push_back(7);
    g[3].push_back(8);
    g[6].push_back(2);
    g[6].push_back(10);
    g[7].push_back(4);
    g[7].push_back(3);
    g[7].push_back(8);
    g[7].push_back(9);
    g[8].push_back(3);
    g[8].push_back(7);
    g[8].push_back(5);
    g[10].push_back(6);
    g[10].push_back(9);
    g[10].push_back(5);
    g[9].push_back(10);
    g[9].push_back(7);
    g[5].push_back(10);
    g[5].push_back(8);

    BFS(1);

    puts("\n");
    for (int i = 1; i <= 10; ++i)
        printf("level of %d = %d\n", i, level[i]);

    return 0;
}
