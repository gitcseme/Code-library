#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> divisors[105];
    for (int i = 1; i <= 100; ++i)
        for (int j = i; j <= 100; j += i)
            divisors[j].push_back(i);

    for (int i = 1; i <= 100; ++i) {
        cout << i << " : ";
        for(int d : divisors[i])
            cout << d << " ";
        cout << "\n";
    }

    return 0;
}
