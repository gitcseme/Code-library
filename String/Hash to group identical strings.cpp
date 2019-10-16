#include <bits/stdc++.h>
using namespace std;

long long compute_hash(string const& s) {
    const int p = 31;
    const int mod = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % mod;
        p_pow = (p_pow * p) % mod;
    }
    return hash_value;
}

vector<vector<int>> Group_Identical_strings(vector<string> const& s) {
    int n = s.size();
    vector<pair<long long, int>> hashes(n);
    for (int i = 0; i < n; ++i) {
        hashes[i] = {compute_hash(s[i]), i};
    }
    sort(hashes.begin(), hashes.end());

    vector<vector<int>> groups;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || hashes[i].first != hashes[i-1].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}

int main() {
    vector<string> s;
    s.push_back("shuvo");
    s.push_back("arif");
    s.push_back("shuvo");
    s.push_back("mahin");
    s.push_back("shuvo");
    s.push_back("fahim");
    s.push_back("arif");
    s.push_back("mitu");
    s.push_back("mahin");
    s.push_back("mitu");
    s.push_back("shuvo");

    vector<vector<int>> g = Group_Identical_strings(s);
    for (int i = 0; i < g.size(); ++i) {
        cout << "group" << i+1 << ": ";
        for (int x : g[i]) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
