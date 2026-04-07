#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
vector<int> adj[505];
queue<int> Q;
int dist[505];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    fill(dist, dist+505, -1);

    while(M--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Q.push(1);
    dist[1] = 0;

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if (dist[cur] == 2) continue;

        for (int nx : adj[cur]) {
            if (dist[nx] > -1) continue;
            Q.push(nx);
            dist[nx] = dist[cur] + 1;
            ans++;
        }
    }

    cout << ans;
}