#include <bits/stdc++.h>
using namespace std;

int T, V, E;
vector<int> adj[5][20020];
bool vis[5][20020];
queue<int> Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--) {
        int cnt = 0;

        cin >> V >> E;

        while (E--) {
            int u, v;
            cin >> u >> v;
            adj[T][u].push_back(v);
            adj[T][v].push_back(u);
        }

        for (int i = 1; i <= V; i++) {
            if (vis[T][i]) continue;

            Q.push(i);
            vis[T][i] = 1;
            cnt++;

            while(!Q.empty()) {
                int cur = Q.front(); Q.pop();

                for (int nx : adj[T][cur]) {
                    if (vis[T][nx]) continue;
                    Q.push(nx);
                    vis[T][nx] = 1;
                }
            }
        }

        if (cnt == 2) cout << "YES\n";
        else cout << "NO\n";
    }
}