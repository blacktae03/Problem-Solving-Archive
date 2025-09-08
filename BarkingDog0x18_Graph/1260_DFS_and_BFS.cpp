#include <bits/stdc++.h>
using namespace std;

int N, M, V;
vector<int> adj[1010];
queue<int> Q;
bool visBFS[1010], visDFS[1010];

void DFS(int cur) {
    for (auto nx : adj[cur]) {
        if(visDFS[nx]) continue;
        cout << nx << ' ';
        visDFS[nx] = 1;
        DFS(nx);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> V;
    
    while(M--) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++) sort(adj[i].begin(), adj[i].end());

    visDFS[V] = 1;
    cout << V << ' ';
    DFS(V);
    cout << '\n';

    Q.push(V);
    visBFS[V] = 1;
    cout << V << ' ';

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();

        for (auto nx : adj[cur]) {
            if (visBFS[nx]) continue;
            visBFS[nx] = 1;
            Q.push(nx);
            cout << nx << ' ';
        }
    }
}