#include <bits/stdc++.h>
using namespace std;

int N, M, cnt;
vector<int> adj[104];
queue<int> Q;
bool vis[104];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    while(M--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Q.push(1);
    vis[1] = 1;
    // cnt++;

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        
        for (auto nx : adj[cur]) {
            if (vis[nx]) continue;
            Q.push(nx);
            vis[nx] = 1;
            cnt++;
        }
    }

    cout << cnt;
}