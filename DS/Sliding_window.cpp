#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> getSolution(vector<int>& vec, int n, int k);

int main()
{   ios::sync_with_stdio(0); cin.tie(0);

    int n, k, num;
    vector<int> v;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        v.push_back(num);
    }

    vector<int> res = getSolution(v, n, k);
    for (int x : res)
        cout << x << " ";

    return 0;
}

vector<int> getSolution(vector<int>& vec, int n, int k) {
    int frnt;
    deque<int> dq;
    vector<int> ret;
    if(k == 1) return vec;
    if(n == k) {
        sort(vec.begin(), vec.end());
        ret.push_back(vec.back());
        return ret;
    }

    for (int i = 0; i < n; ++i) {
        while (!dq.empty() && vec[dq.back()] < vec[i]) {
            dq.pop_back();
        }
        dq.push_back(i);

        frnt = dq.front();
        if(i-frnt+1 == k) dq.pop_front();

        if (i+1 >= k) ret.push_back(vec[frnt]);
    }
    return ret;
}
