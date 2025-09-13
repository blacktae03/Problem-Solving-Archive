#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> adj[55];
int dist[55][55];
int score[55];
queue<int> Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) fill(dist[i], dist[i]+55, -1);
    
    while(true) {
        int u, v;
        cin >> u >> v;
        if (u < 0) break;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) {
        dist[i][i] = 0;
        Q.push(i);

        while(!Q.empty()) {
            int cur = Q.front(); Q.pop();

            for (int t : adj[cur]) {
                if (dist[i][t] > -1) continue;

                dist[i][t] = dist[i][cur] + 1;
                score[i] = max(score[i], dist[i][t]);
                Q.push(t);
            }
        }
    }

    int ansScore = *min_element(score+1, score+N);
    int cnt = 0;
    vector<int> can;

    for (int i = 1; i <= N; i++) {
        if (score[i] == ansScore) {
            cnt++;
            can.push_back(i);
        }
    }

    cout << ansScore << ' ' << cnt << '\n';
    for (int num : can) cout << num << ' ';
}