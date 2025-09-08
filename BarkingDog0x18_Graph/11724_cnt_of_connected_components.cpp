#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
vector<int> adj[1010];
bool vis[1010];
queue<int> Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    while (M--) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;

        Q.push(i);
        vis[i] = 1;

        while(!Q.empty()) {
            int cur = Q.front();
            Q.pop();

            for (int n : adj[cur]) {
                if (vis[n]) continue;
                Q.push(n);
                vis[n] = 1;
            }
        }
        
        ans++;
    }

    cout << ans;
}