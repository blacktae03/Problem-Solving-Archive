#include <bits/stdc++.h>
using namespace std;

int N, M, mx;
vector<int> adj[10010];
bool vis[10010];
int cnt[10010];
queue<int> Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    while (M--) {
        int u, v;
        cin >> v >> u;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= N; i++) {
        fill(vis, vis+10010, 0);
        Q.push(i);
        vis[i] = 1;
        cnt[i]++;

        while (!Q.empty()) {
            int cur = Q.front(); Q.pop();

            for (int pc : adj[cur]) {
                if (vis[pc]) continue;
                Q.push(pc);
                vis[pc] = 1;
                cnt[i]++;
            }
        }

        mx = max(mx, cnt[i]);
    }

    for (int i = 1; i <= N; i++) if (mx == cnt[i]) cout << i << ' ';
}