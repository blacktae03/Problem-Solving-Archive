#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;
    int N;
    string cmd;
    int psh;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> cmd;

        if (cmd == "push") {
            cin >> psh;
            S.push(psh);
        }

        else if (cmd == "top") {
            if (S.empty()) cout << -1 << '\n';
            else cout << S.top() << '\n';
        }

        else if (cmd == "pop") {
            if (S.empty()) cout << -1 << '\n';
            else {
                cout << S.top() << '\n';
                S.pop();
            }
        }

        else if (cmd == "size") {
            cout << S.size() << '\n';
        }

        else if (cmd == "empty") {
            cout << S.empty() << '\n';
        }
    }
}