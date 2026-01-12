#include <bits/stdc++.h>
using namespace std;

int N;
bool adj[103][103], vis[103][103];
queue<int> Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool route; cin >> route;
            adj[i][j] = route;
        }
    }

    for (int i = 0; i < N; i++) {
        Q.push(i);

        while(!Q.empty()) {
            int cur = Q.front(); Q.pop();

            for (int j = 0; j < N; j++) {
                if (vis[i][j] || !adj[cur][j]) continue;
                Q.push(j);
                vis[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << vis[i][j] << ' ';
        }
        cout << '\n';
    }
}