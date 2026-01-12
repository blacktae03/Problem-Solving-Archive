#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
vector<int> adj[1010];
bool vis[1010];
stack<int> S;

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

        S.push(i);
        vis[i] = 1;

        while(!S.empty()) {
            int cur = S.top();
            S.pop();

            for (int n : adj[cur]) {
                if (vis[n]) continue;
                S.push(n);
                vis[n] = 1;
            }
        }
        
        ans++;
    }

    cout << ans;
}