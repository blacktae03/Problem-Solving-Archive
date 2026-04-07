#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second.first
#define Z second.second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c, h;
    cin >> c >> r >> h; // 행, 열 반대로 문제 쳐 만드네 화나게..

    int tmt[h][r][c];
    int day[h][r][c];
    queue<pair<int, pair<int, int>>> Q;
    pair<int, pair<int, int>> cur;
    int min = 0;

    int dx[6] = {1,0,0,-1,0,0};
    int dy[6] = {0,1,0,0,-1,0};
    int dz[6] = {0,0,1,0,0,-1};
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                cin >> tmt[i][j][k];
                day[i][j][k] = 0;
                if (tmt[i][j][k] == 1)
                    Q.push({i, {j, k}});
            }
        }
    }

    while (!Q.empty()) {
        cur = Q.front(); Q.pop();
        for (int k = 0; k < 6; k++) {
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];
            int nz = cur.Z + dz[k];

            if (nx < 0 || nx >= h || ny < 0 || ny >= r || nz < 0 || nz >= c) continue;
            if (tmt[nx][ny][nz] < 0) continue;
            if (tmt[nx][ny][nz] == 0 && day[nx][ny][nz] == 0) {
                tmt[nx][ny][nz] = 1;
                day[nx][ny][nz] = day[cur.X][cur.Y][cur.Z] + 1;
                min = day[nx][ny][nz];
                Q.push({nx, {ny, nz}});
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < r; j++) {
            for (int k = 0; k < c; k++) {
                if (tmt[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    

    cout << min;
}