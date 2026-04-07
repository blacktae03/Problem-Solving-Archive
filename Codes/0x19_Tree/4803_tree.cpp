#include <bits/stdc++.h>
using namespace std;

int testcase;

bool solve() {
    testcase++;
    int N, M; cin >> N >> M;
    if (!N && !M) return false;

    bool adj[505][505] = {0,};
    bool vis[505] = {0,};
    int tree = 0;

    while (M--) {
        int v1, v2; cin >> v1 >> v2;
        adj[v1][v2] = adj[v2][v1] = true;
    }

    for (int i = 1; i <= N; i++) {
        if (vis[i]) continue;

        queue<int> Q;
        bool isTree = true;
        Q.push(i);
        vis[i] = true;

        while (!Q.empty()) {
            int cur = Q.front(); Q.pop();

            for (int j = 1; j <= N; j++) {
                if (!adj[cur][j]) continue;
                // cout << cur << "->" << j << '\n';
                if (vis[j]) {
                    isTree = false;
                    break;
                }
                Q.push(j);
                vis[j] = true;
                adj[j][cur] = adj[cur][j] = false;
            }
            
            if (!isTree) break;
        }

        // if (isTree) cout << '*' << i << '*' << '\n';
        tree += isTree;
    }

    if (!tree) cout << "Case " << testcase << ": No trees.\n";
    else {
        if (tree == 1) cout << "Case " << testcase << ": There is one tree.\n";
        else cout << "Case " << testcase << ": A forest of " << tree << " trees.\n";
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (solve()) {}
}