#include <bits/stdc++.h>
using namespace std;

int N, Q;
multiset<pair<bool, int>> M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    
    for (int i = 0; i < N; i++) {
        bool good;
        cin >> good;
        M.insert({good, i});
    }

    int loc = 0;

    while (Q--) {
        int cmd; cin >> cmd;

        if (cmd == 1) {
            int i; cin >> i;
            i--;
            auto it = M.find({0, i});
            if (it != M.end()) {
                M.insert({1, i});
                M.erase(it);
            }
            else {
                M.insert({0, i});
                M.erase({1, i});
            }
        }

        else if (cmd == 2) {
            int x; cin >> x;
            loc += x;
            loc %= N;
        }

        else {
            auto it = M.lower_bound({1, loc});
            if (it != M.end()) { // loc보다 높거나 같은 위치에서 찾았을 때
                int ans = it->second - loc;
                // if (ans < 0) ans += N;
                cout << ans << '\n';
            }
            else {
                it = M.lower_bound({1, 0});
                if (it != M.end()) { // loc보다 낮은 위치에서 찾았을 때
                    int ans = it->second - loc + N;
                    // if (ans < 0) ans += N;
                    cout << ans << '\n';
                }
                else cout << -1 << '\n';
            }
        }
    }
}