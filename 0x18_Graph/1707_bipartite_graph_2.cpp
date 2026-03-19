#include <bits/stdc++.h>
using namespace std;

int K, V, E;
vector<int> adj[5][20020];
int group[5][20020];

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
            if (!group[K][i]) group[K][i] = 1;
            int cur = group[K][i];

            for (auto v : adj[K][i]) {
                if (group[K][v] == cur) flag = false;
                else group[K][v] = -cur;
            }

            if (!flag) break;
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
}

// 반례 : 1 - 4 - 3 - 2
// 1
// 4 3
// 1 4
// 4 3
// 3 2
// Answer : YES
// Output : NO