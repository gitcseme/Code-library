#include <bits/stdc++.h>
#define FI freopen ("inp.txt", "r", stdin)
#define FO freopen ("out.txt", "w", stdout)
using namespace std;

/* input

Breakfast Office
Dress_up Office
Office Dinner
Office Sports
Office Email
Email Sports
Email Dinner
Dinner Sports
*/

struct Node {
    string data;
    int indegree;
    vector <string> adj;
    Node(){}                // map <primitive, struct>   needs this constructor. or use make_pair().
    Node (string d) {
        data = d;
        indegree = 0;
    }
};

map <string, Node> g;
vector <string> output;

void topsort () {
    queue <string> q;
    for(auto it = g.begin(); it != g.end(); ++it) {
        if (it->second.indegree == 0)
            q.push(it->first);
    }

    while (!q.empty()) {
        string u = q.front(); q.pop();
        output.push_back(u);

        for (string v : g[u].adj) {
            g[v].indegree--;
            if (g[v].indegree == 0)
                q.push(v);
        }
    }
}

int main() {
    FI;

    string s1, s2;
    for (int i = 0; i < 8; ++i) {
        cin >> s1 >> s2;
        if (g.count(s1) == 0) g[s1] = Node(s1);
        if (g.count(s2) == 0) g[s2] = Node(s2);
        g[s1].adj.push_back(s2);
        g[s2].indegree++;
    }

    topsort();

    for (int i = 0; i < output.size(); ++i){
        if (i != output.size()-1) cout << output[i] << " -> ";
        else cout << output[i] << "\n";
    }

    return 0;
}
