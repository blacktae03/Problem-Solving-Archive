#include <bits/stdc++.h>
using namespace std;
// 혹시나 해서 거꾸로 해보니까 되긴 됐는데 왜 됐는지 모르겠음.
// 왜 정방향으로 하면 안됨?

int A, B;
vector<pair<int, int>> V;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;

    V.push_back({B, 0});

    int idx = 0;
    while(true) {
        if (idx >= V.size()) break;
        auto cur = V[idx++];
        int nx;

        if (cur.first % 10 == 1 && cur.first > 10) {
            nx = cur.first / 10;
            if (nx == A) {
                cout << cur.second+2 << '\n';
                return 0;
            }    
            if (nx < A) continue;
            V.push_back({nx, cur.second+1});
        }
        
        if (cur.first % 2 == 0) {
            nx = cur.first / 2;
            if (nx == A) {
                cout << cur.second+2 << '\n';
                return 0;
            }    
            if (nx < A) continue;
            V.push_back({nx, cur.second+1});
        }

        // for (int dir = 0; dir < 2; dir++) {
        //     // bool in = 0;
        //     int nx;
        //     if (dir) nx = cur.first * 10 + 1;
        //     else nx = cur.first * 2;
            
        //     if (nx == A) {
        //         cout << cur.second+2 << '\n';
        //         V.push_back({nx, cur.second+1});
        //         for (auto t : V) cout << t.first << ' ' << t.second << '\n';
        //         return 0;
        //     }
        //     if (nx < A) continue;
        //     // for (auto p : V) {
        //     //     if (p.first == nx) in = 1;
        //     // }
        //     // if (in) continue;

        //     V.push_back({nx, cur.second+1});
        // }
    }

    cout << -1;
}