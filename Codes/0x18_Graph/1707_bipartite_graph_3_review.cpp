#include <bits/stdc++.h>
using namespace std;

string solve() {
    int V, E;
    vector<int> adj[20020];
    int group[20020] = {0,};

    cin >> V >> E;

    while (E--) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    for (int i = 1; i <= V; i++) {
        if (group[i]) continue;
        queue<int> Q;
        Q.push(i);
        group[i] = 1;

        while(!Q.empty()) {
            int cur = Q.front(); Q.pop();
            int my = group[cur];

            for (auto v : adj[cur]) {
                if (group[v] == -my) continue;
                if (group[v] == my) return "NO\n";
                
                Q.push(v);
                group[v] = -my;
            }
        }
    }

    return "YES\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K; cin >> K;
    while (K--) cout << solve();
}