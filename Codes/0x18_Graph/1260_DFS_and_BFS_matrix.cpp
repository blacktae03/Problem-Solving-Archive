#include <bits/stdc++.h>
using namespace std;

int N, M, V;
// vector<int> adj[1010];
int adj[1010][1010];
queue<int> Q;
bool visBFS[1010], visDFS[1010];

void DFS(int cur) {
    for (int nx = 1; nx <= N; nx++) {
        if(visDFS[nx] || !adj[cur][nx]) continue;
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

        adj[u][v]++;
        adj[v][u]++;
    }

    // for (int i = 1; i <= N; i++) sort(adj[i].begin(), adj[i].end());

    visDFS[V] = 1;
    cout << V << ' ';
    DFS(V);
    cout << '\n';

    Q.push(V);
    visBFS[V] = 1;
    cout << V << ' ';

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();

        for (int nx = 1; nx <= N; nx++) {
            if (visBFS[nx] || !adj[cur][nx]) continue;
            visBFS[nx] = 1;
            Q.push(nx);
            cout << nx << ' ';
        }
    }
}
// matrix가 아닌 list로 표현할 경우 sort를 해야해서 시간이 오래 걸릴 것으로 예상했으나
// 이게 더 오래 걸림.