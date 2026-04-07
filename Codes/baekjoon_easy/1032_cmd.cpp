#include <bits/stdc++.h>
using namespace std;

int N;
string str, comp;
bool qm[55];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        if (!i) {
            cin >> str;
        }

        else {
            cin >> comp;
            int tmp = -1;

            for (char c : str) {
                tmp++;
                if (comp[tmp] == c) continue;
                qm[tmp] = 1;
            }
        }
    }

    for (int i = 0; i < str.length(); i++) {
        if (qm[i]) cout << '?';
        else cout << str[i];
    }
}