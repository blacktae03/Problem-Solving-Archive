#include <bits/stdc++.h>
using namespace std;

int N, M;
multiset<pair<int, int>> ms;
map<int, int> mp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int P, L; cin >> P >> L;
        ms.insert({L, P});
        mp[P] = L;
    }

    cin >> M;
    
    while (M--) {
        string cmd;
        int P, L;

        cin >> cmd >> P;

        if (cmd == "add") {
            cin >> L;
            ms.insert({L, P});
            mp[P] = L;
        }

        else if (cmd == "solved") {\
            auto tmp = mp.find(P);
            ms.erase({tmp->second, tmp->first});
            mp.erase(P);
        }

        else {
            if (P == 1) cout << prev(ms.end())->second << '\n';
            else cout << ms.begin()->second << '\n';
        }
    }
}