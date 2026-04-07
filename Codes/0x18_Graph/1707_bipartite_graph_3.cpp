#include <bits/stdc++.h>
using namespace std;

int K, V, E;
vector<int> adj[5][20020];
int group[5][20020];
queue<int> Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K;

    while (K--) {
        cin >> V >> E;

        while (E--) {
            int v1, v2;
            cin >> v1 >> v2;
            adj[K][v1].push_back(v2);
            adj[K][v2].push_back(v1);
        }

        bool flag = true;

        for (int i = 1; i <= V; i++) {
            if (group[K][i]) continue;
            Q.push(i);
            group[K][i] = 1;
    
            while(!Q.empty()) {
                int cur = Q.front(); Q.pop();
                int my = group[K][cur];
    
                for (auto v : adj[K][cur]) {
                    if (group[K][v] == -my) continue;
                    if (group[K][v] == my) {
                        flag = false;
                        continue;
                    }
                    
                    Q.push(v);
                    group[K][v] = -my;
                }
    
                // if (!flag) break;
            }
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
}