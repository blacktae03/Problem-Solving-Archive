#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
vector<int> adj[1010];
bool vis[1010];
stack<int> S;

void dfs(int d) {
    for (int t : adj[d]) {
        if (vis[t]) continue;
        vis[t] = 1;
        dfs(t);
    }
}

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
        vis[i] = 1;
        dfs(i);
        
        ans++;
    }

    cout << ans;
}