#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

// int grd[50][50];
// bool vis[50][50];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, cnt = 0;
    queue<pair<int, int>> Q;
    pair<int, int> cur;
    cin >> T;

    while (T--) {
        int r, c, num;

        cin >> c >> r >> num;

        int grd[r][c];
        bool vis[r][c]; 
        // 아니 왜 전역변수로 하면 안되냐 다 0으로 초기화 되는거 아니었 나

        for (int i = 0; i < r; i++) {
            fill(grd[i], grd[i]+c, 0);
            fill(vis[i], vis[i]+c, 0);
        }

        while (num--) {
            int x, y;
            cin >> y >> x;

            grd[x][y] = 1;
        }

        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grd[i][j] == 0 || vis[i][j]) continue;

                vis[i][j] = 1;
                Q.push({i, j});
                
                cnt++;

                while (!Q.empty()) {
                    cur = Q.front(); Q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = cur.X + dx[k];
                        int ny = cur.Y + dy[k];

                        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                        if (grd[nx][ny] == 0 || vis[nx][ny]) continue;

                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }

        cout << cnt << '\n';
        cnt = 0;
    }

}