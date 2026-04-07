#include <bits/stdc++.h>
using namespace std;

int N, R, q;
vector<int> adj[10010];
int dist[10010];
queue<int> Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> R >> q;

    while (N--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    fill(dist, dist+10010, -1);
    Q.push(R);
    dist[R] = 0;

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        vector<int> next_depth;
        int cnt = 0;

        for (auto v : adj[cur]) {
            if (dist[v] < 0) continue;
            next_depth.push_back(v);
            cnt++;
        }
    }

    while (q--) {

    }
}