#include <bits/stdc++.h>
using namespace std;

int A, B;
vector<pair<int, int>> V;
queue<pair<int, int>> Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;

    V.push_back({A, 0});
    Q.push({A, 0});

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 2; dir++) {
            bool in = 0;
            int nx;
            if (dir) nx = cur.first * 10 + 1;
            else nx = cur.first * 2;
            
            if (nx == B) {
                cout << cur.second+2 << '\n';
                V.push_back({nx, cur.second+1});
                for (auto t : V) cout << t.first << ' ' << t.second << '\n';
                return 0;
            }
            if (nx > B) continue;
            // for (auto p : V) {
            //     if (p.first == nx) in = 1;
            // }
            // if (in) continue;

            V.push_back({nx, cur.second+1});
            Q.push({nx, cur.second+1});
        }
    }


    cout << -1;
}