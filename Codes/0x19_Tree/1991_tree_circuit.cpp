#include <bits/stdc++.h>
using namespace std;

int N;
unordered_map<char, char> L, R;

void preorder_traversal(char node) {
    cout << node;
    if (L[node] != '.') preorder_traversal(L[node]);
    if (R[node] != '.') preorder_traversal(R[node]);
}

void inorder_traversal(char node) {
    if (L[node] != '.') inorder_traversal(L[node]);
    cout << node;
    if (R[node] != '.') inorder_traversal(R[node]);
}

void postorder_traversal(char node) {
    if (L[node] != '.') postorder_traversal(L[node]);
    if (R[node] != '.') postorder_traversal(R[node]);
    cout << node;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while (N--) {
        char par, lc, rc;
        cin >> par >> lc >> rc;

        L[par] = lc;
        R[par] = rc;
    }

    preorder_traversal('A');
    cout << '\n';
    inorder_traversal('A');
    cout << '\n';
    postorder_traversal('A');
    cout << '\n';
}

// preorder traversal
// : self -> left -> right
// inorder traversal
// : left -> self -> right
// postorder traversal
// : left -> right -> self