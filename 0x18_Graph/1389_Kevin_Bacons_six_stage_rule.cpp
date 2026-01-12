#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adj[105];
queue<int> Q;
int dist[105][105];
int KVnum[105];

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
        fill(dist[i], dist[i]+105, -1);

        Q.push(i);
        dist[i][i] = 0;

        while(!Q.empty()) {
            int cur = Q.front(); Q.pop();

            for (int frnd : adj[cur]) {
                if (dist[i][frnd] > -1) continue;

                Q.push(frnd);
                dist[i][frnd] = dist[i][cur] + 1;
                KVnum[i] += dist[i][frnd];
            }
        }
    }

    int ans = INT_MAX;
    int idx = 0;
    for (int i = 1; i <= N; i++) {
        if (KVnum[i] >= ans) continue;
        ans = KVnum[i];
        idx = i;
    }
    cout << idx;
    // cout << min_element(KVnum+1, KVnum+N) - KVnum;
}