#include <bits/stdc++.h>
using namespace std;

struct Node {
    bool endmark;
    Node* next[26 + 1];
    Node() {
        endmark = false;
        for (int i = 0; i < 26; ++i)
            next[i] = NULL;
    }
};
Node *root;

void Insert (char str[], int len) {
    Node *cur = root;
    for (int i = 0; i < len; ++i) {
        int id = str[i] - 'a';
        if (cur->next[id] == NULL) {
            cur->next[id] = new Node();
        }
        cur = cur->next[id];
    }
    cur->endmark = true;
}

bool Search (char str[], int len) {
    Node *cur = root;
    for (int i = 0; i < len; ++i) {
        int id = str[i] - 'a';
        if (cur->next[id] == NULL) {
            return false;
        }
        cur = cur->next[id];
    }
    return cur->endmark;
}

void del (Node *cur) {
    for (int i = 0; i < 26; ++i) {
        if (cur->next[i])
            del(cur->next[i]);
    }
    delete(cur);
}

int main () {
    root = new Node();
    int num_words, query;
    cin >> num_words;
    while (num_words--) {
        char str[50];
        cin >> str;
        Insert(str, strlen(str));
    }

    cin >> query;
    while (query--) {
        char str[50];
        cin >> str;
        if (Search(str, strlen(str)))
            cout << "Found\n";
        else
            cout << "Nor Found\n";
    }

    del(root);
    return 0;
}
