#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, tarea = 0;
    cin >> N;
    string apt[N];
    bool vis[N][N];
    int cnt = 0;
    vector<int> area;

    for (int i = 0; i < N; i++) {
        cin >> apt[i];
        fill (vis[i], vis[i]+N, 0);
    }

    queue<pair<int, int>> Q;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (vis[i][j] || apt[i][j] == '0') continue;
            cnt++;
            tarea = 1;
            Q.push({i, j});
            vis[i][j] = 1;

            while (!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = cur.X + dx[k];
                    int ny = cur.Y + dy[k];
                    
                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (vis[nx][ny] || apt[nx][ny] == '0') continue;

                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                    tarea++;
                }        
            }

            area.push_back(tarea);
        }
    }

    cout << cnt << '\n';
    
    sort(area.begin(), area.end());

    for (auto a : area)
        cout << a << '\n';
}