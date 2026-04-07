#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int r, c;
    cin >> r >> c;

    int ibg[r][c];
    bool vis[r][c];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> ibg[i][j];
            vis[i][j] = 0;
        }
    }

    queue<pair<int, int>> Q;
    
    int year = 0;
    int cnt = 0;
    
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    while (cnt < 2) {
        cnt = 0;

        // 빙산 녹이기

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                vis[i][j] = 0;
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!ibg[i][j]) continue;
                vis[i][j] = 1;

                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];

                    if(!ibg[nx][ny] && ibg[i][j] > 0 && !vis[nx][ny]) ibg[i][j]--;
                }
            }
        }
        year++;

        // 붙은 거 개수 세기.

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                vis[i][j] = 0;
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (!ibg[i][j] || vis[i][j]) continue;
                Q.push({i, j});
                vis[i][j] = 1;
                cnt++;

                while(!Q.empty()) {
                    pair<int, int> cur = Q.front(); Q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                        if (!ibg[nx][ny] || vis[nx][ny]) continue;

                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }

        if (!cnt) {cout << cnt; return 0;}

    }

    cout << year;
}