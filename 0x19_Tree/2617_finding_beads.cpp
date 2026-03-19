#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
vector<int> light_edge[101], heavy_edge[101];
int lighters[101], heaviers[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    int half = N/2;

    while (M--) {
        int heavier, lighter;
        cin >> heavier >> lighter;

        light_edge[lighter].push_back(heavier);
        heavy_edge[heavier].push_back(lighter);
    }

    for (int i = 1; i <= N; i++) {
        queue<int> Q;
        bool vis[101] = {0,};
        Q.push(i);
        vis[i] = true;

        while (!Q.empty()) {
            int cur = Q.front(); Q.pop();

            for (auto v : light_edge[cur]) {
                if (vis[v]) continue;

                lighters[v]++;
                Q.push(v);
                vis[v] = true;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        queue<int> Q;
        bool vis[101] = {0,};
        Q.push(i);
        vis[i] = true;

        while (!Q.empty()) {
            int cur = Q.front(); Q.pop();

            for (auto v : heavy_edge[cur]) {
                if (vis[v]) continue;

                heaviers[v]++;
                Q.push(v);
                vis[v] = true;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        // cout << "* " << i << " : " << lighters[i] << ' ' << heaviers[i] << " *\n";
        if (heaviers[i] > half || lighters[i] > half) {
            // cout << i << " DETECTED\n";
            ans++;
        }
    }

    cout << ans << '\n';
}
// Hello World