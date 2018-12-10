#include <bits/stdc++.h>
using namespace std;

long long B = 347, M = 1000000000 + 7;

long long Hash (const string &s, int m) {
    long long h = 0, power = 1;
    for (int i = m-1; i >= 0; --i) {
        h = (h + (s[i] * power) % M) % M;
        power = (power * B) % M;
    }
    return h;
}

long long mpow(long long a, long long b) {
    if (b == 1)
        return a;
    long long res = mpow(a, b>>1);
    res = res * res;
    if (b&1)
        res = res * a;
    return res;
}

int match (const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();
    if ((n < m) || (m==0 || n==0)) return -1;

    long long power = mpow(B, m-1); //calculate B^(m-1)
    long long hash_text = Hash(text, m);
    long long hash_pattern = Hash(pattern, m);

    if (hash_text == hash_pattern) return 0; // match at the beginning.

    for (int i = 1; i <= (n-m); ++i)
    {
        // Rolling the hash value. H_i = (H_i-1 - S_i-1 * B^(m-1) ) * B + S_i+m-1
        hash_text = (hash_text - (text[i-1] * power) % M ) % M;
        hash_text = (hash_text + M) % M; // -ve value check.
        hash_text = (hash_text * B) % M;
        hash_text = (hash_text + text[i+m-1]) % M;

        if (hash_text == hash_pattern) return i;
    }
    return -1;
}

int main() {
    cout<< match("HelloWorld", "oWor") << endl;

    return 0;
}
