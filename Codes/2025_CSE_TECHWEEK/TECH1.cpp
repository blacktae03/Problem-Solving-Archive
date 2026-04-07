#include <bits/stdc++.h>
using namespace std;

int T, R, B;
vector<pair<int, bool>> V;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--) {
        cin >> R >> B;
        int mid = (R+B-1)/2;
        int tmp;

        for (int i = 0; i < R; i++) {
            cin >> tmp;
            V.push_back({tmp, 0});
        }
        
        for (int i = 0; i < B; i++) {
            cin >> tmp;
            V.push_back({tmp, 1});
        }

        sort(V.begin(), V.end());
        pair<int, bool> sim = {V[mid].first, !V[mid].second};
        // cout << sim.second << "+\n";
        
        if (binary_search(V.begin(), V.end(), sim)) cout << "RB\n";

        else {
            char ans = V[mid].second ? 'B' : 'R';
            cout << ans << '\n';
        }

        V.clear();
    }
}