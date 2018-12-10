#include <bits/stdc++.h>
using namespace std;

int evaluate (vector <string>& exp) {
    stack <int> stk;
    int x, y, ans = 0, len = exp.size();

    char c;
    for (int i = 0; i < len; ++i) {
        c = exp[i][0];
        if (c == '/' || c == '*' || c == '+' || c == '-' || c == '^') {
            x = stk.top(); stk.pop();
            y = stk.top(); stk.pop();
            switch (c) {
                case '/': ans = y/x; break;
                case '*': ans = x*y; break;
                case '+': ans = x+y; break;
                case '-': ans = y-x; break;
            }
            stk.push(ans);
        }
        else {
            stringstream sso(exp[i]);
            sso >> x;
            stk.push(x);
        }
    }
    return stk.top();
}

/* input
    Postfix : ( 3 + 6 ) * ( 4 - 2 ) ==> 3 6 + 4 2 - *
    Prefix : * + 3 6 - 4 2 ==> 2 4 - 6 3 + *   (reversed) and
    in place y/x will be x/y and in y-x will be x-y.
*/
int main () {
    string exp, token;
    getline(cin, exp);
    vector <string> expression;
    stringstream sso(exp);
    while (sso >> token) {
        expression.push_back(token);
    }

    int result = evaluate(expression);
    cout << result;

    return 0;
}
