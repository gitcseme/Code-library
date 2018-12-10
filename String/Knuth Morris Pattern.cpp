#include <bits/stdc++.h>
using namespace std;

char text[1000], pattern[1000];
int suf[1005];

void lps () {
    int len = strlen(pattern), k = 0;
    for (int i = 1; i < len; ++i) {
        while (k > 0 && pattern[k] != pattern[i])
            k = suf[k - 1];
        if (pattern[k] == pattern[i])
            ++k;
        suf[i] = k;
    }
}

void KMP () {
    int len = strlen(text), k = 0, pat = strlen(pattern);
    for (int i = 0; i < len; ++i) {
        while (k > 0 && pattern[k] != text[i])
            k = suf[k - 1];
        if (pattern[k] == text[i])
            ++k;
        if (k == pat) {
            k = 0;
            cout << (i+1) - pat << " "; // locations.
        }
    }
}

int main () {
    // text = abcabcabcabc  pattern = cab
    cin >> text;
    cin >> pattern;

    lps();
    KMP();

    return 0;
}
