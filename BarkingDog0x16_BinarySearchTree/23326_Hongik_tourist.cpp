#include <bits/stdc++.h>
using namespace std;

int N, Q;
map<int, bool> M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    
    for (int i = 0; i < N; i++) {
        bool good;
        cin >> good;
        M[i] = good;
    }

    int loc = 0;

    while (Q--) {
        int cmd; cin >> cmd;

        if (cmd == 1) {
            int i; cin >> i;
            M[i] = !M[i];
        }

        else if (cmd == 2) {
            int x; cin >> x;
            loc += x;
            loc %= N;
        }

        else {
            M.lower_bound()
        }
    }
}