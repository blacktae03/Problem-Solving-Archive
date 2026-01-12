#include <bits/stdc++.h>
using namespace std;

int N, M, ans, idx, cnt;
vector<int> adj[20020];
int dist[20020];
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

    fill (dist, dist+20020, -1);
    Q.push(1);
    dist[1] = 0;

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();

        for (int num : adj[cur]) {
            if (dist[num] > -1) continue;
            Q.push(num);
            dist[num] = dist[cur] + 1;
        }
    }
    
    for (int i = 1; i <= N; i++) {
        if (dist[i] < ans) continue;
        else if (dist[i] == ans) cnt++;
        else {
            idx = i;
            ans = dist[i];
            cnt = 1;
        }
    }

    cout << idx << ' ' << ans << ' ' << cnt;
}