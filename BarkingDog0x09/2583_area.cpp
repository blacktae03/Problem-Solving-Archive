#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c, rec;
    int x1, y1, x2, y2;

    cin >> r >> c >> rec;

    int brd[r][c];
    bool vis[r][c];
    vector<int> area;
    queue<pair<int, int>> Q;
    int cnt = 0, tarea = 0;
    
    for (int i = 0; i < r; i++) {
        fill(brd[i], brd[i]+c, 0);
        fill(vis[i], vis[i]+c, 0);
    }

    for (int i = 0; i < rec; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        for (int j = y1; j < y2; j++) {
            for (int k = x1; k < x2; k++) {
                brd[j][k] = -1;
            }
        }
    }

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (brd[i][j] < 0 || vis[i][j]) continue;
            tarea = 1;
            cnt++;
            Q.push({i, j});
            vis[i][j] = 1;

            while (!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = cur.X + dx[k];
                    int ny = cur.Y + dy[k];

                    if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                    if (vis[nx][ny] || brd[nx][ny] < 0) continue;

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
        cout << a << ' ';
}