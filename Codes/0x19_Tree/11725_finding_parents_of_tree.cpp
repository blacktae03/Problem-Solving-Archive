#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> adj[100010];
int par[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> Q;
    Q.push(1);

    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();

        for (auto nxt : adj[cur]) {
            if (par[nxt]) continue;
            par[nxt] = cur;
            Q.push(nxt);
        }
    }

    for (int i = 2; i <= N; i++) cout << par[i] << '\n';
}