#include <bits/stdc++.h>
using namespace std;

int N, ans = 1;
map<int, int> M;
multiset<int> MS;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int h, k;
        cin >> h >> k;
        M[h] = k;
    }

    auto it = M.end();
    // int i = 0;
    MS.insert(0);

    while (it != M.begin()) {
        it = prev(it);
        
        auto where = MS.lower_bound(it->second-1);
        if (where == MS.begin() && *where >= it->second) MS.insert(1);
        else {
            if (*where >= it->second) where = prev(where);
            MS.insert(*where+1);
            MS.erase(where);
        }
    }

    cout << MS.size();
}