#include <bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    Node *left, *right;
};

Node* newNode (string d) {
    Node* temp = new Node;
    temp->left = temp->right = NULL;
    temp->data = d;
    return temp;
}

Node* build_tree (vector<string> &exp) {
    int len = exp.size();
    stack <Node*> stk;
    Node *cur, *x, *y;
    char c;

    for (int i = 0; i < len; ++i) {
        c = exp[i][0];
        if (isdigit(c)) {
            stk.push(newNode(exp[i]));
        }
        else {
            cur = newNode(exp[i]);
            x = stk.top(); stk.pop();
            y = stk.top(); stk.pop();
            cur->left = y;
            cur->right = x;
            stk.push(cur);
        }
    }
    return stk.top();
}

void InOrder (Node *root) {
    if(root == NULL) {
        return;
    }
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

int main() {
    string exp, token;
    getline(cin, exp);
    vector <string> expression;
    stringstream sso(exp);
    while (sso >> token) {
        expression.push_back(token);
    }

    Node *root = build_tree(expression);

    InOrder (root);
    return 0;
}
