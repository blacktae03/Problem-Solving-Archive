#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> V;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int s, e; cin >> s >> e;
        V.push_back({s, 1});
        V.push_back({e, -1});
    }

    sort(V.begin(), V.end());

    int cnt = 0;
    int ans = 0;

    for (auto l : V) {
        if (l.second == 1) {
            if (cnt++ == 0) ans -= l.first;
        }
        else {
            if (--cnt == 0) ans += l.first;
        }
    }
    
    cout << ans;
}
// 4
// 1 3
// 2 5
// 3 5
// 6 7
// 1 1, 2 1, 3 -1, 3 1, 5 -1, 5 -1, 6 1, 7 -1
