#include <bits/stdc++.h>
using namespace std;

int K, L;
unordered_map<string, int> M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> L;
    for (int i = 0; i < L; i++) {
        string tmp; cin >> tmp;
        M[tmp] = i;
    }

    vector<pair<int, string>> ans;
    for (auto p : M) ans.push_back({p.second, p.first});
    sort(ans.begin(), ans.end());
    
    // cout << "after vector\n";
    // for (auto p : ans) cout << p.first << ' ' << p.second << '\n';
    // cout << "answer\n";
    for (int i = 0; i < K; i++) {
        if (i >= ans.size()) break;
        cout << ans[i].second << '\n';
    }
}