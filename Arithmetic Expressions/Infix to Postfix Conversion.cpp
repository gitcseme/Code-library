#include <bits/stdc++.h>
using namespace std;

int precedence(char opt) {
    if (opt == '+' || opt == '-') return 1;
    if (opt == '/' || opt == '*') return 2;
    if (opt == '^') return 3;
    return -1;
}

string convert (vector <string> &exp) {
    string ret = ""; stack <char> stk; char c; int len = exp.size();

    for (int i = 0; i < len; ++i) {
        c = exp[i][0];

        if (isdigit(c))
            ret.append(exp[i]), ret.append(" ");
        else if (c == '(')
            stk.push(c);
        else if (c == ')') {
            while (stk.top() != '(')
                c = stk.top(), stk.pop(), ret = ret + c, ret.append(" ");
            stk.pop();
        }
        else { // Operator encountered.
            while (precedence(c) <= precedence(stk.top()))
                ret = ret + stk.top(), ret.append(" "), stk.pop();
            stk.push(c);
        }
    }
    return ret;
}

int main() {
    string exp, token;
    getline(cin, exp);
    vector <string> expression;
    expression.push_back("( ");
    stringstream sso(exp);
    while (sso >> token) {
        expression.push_back(token);
    }
    expression.push_back(")");

    string out = convert (expression);
    cout << "Postfix : " << out;

    return 0;
}
