#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int brd[n][n];
    bool vis[n][n];
    int dist[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> brd[i][j];
            vis[i][j] = 0;
            dist[i][j] = -1;
        }
    }

    int num = 1;
    queue<pair<int, int>> Q;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] || !brd[i][j]) continue;

            Q.push({i, j});
            vis[i][j] = 1;
            brd[i][j] = num;

            while (!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (vis[nx][ny] || !brd[nx][ny]) continue;

                    brd[nx][ny] = num;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }

            num++;
        }
    }
    
    int ans = 10000;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(!brd[i][j]) continue;

            Q.push({i, j});
            dist[i][j] = 0;

            while(!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (dist[nx][ny] > -1 || brd[nx][ny] == brd[i][j]) continue;
                    if (brd[nx][ny] != 0 && brd[nx][ny] != brd[i][j]) {
                        ans = min(ans, dist[cur.X][cur.Y]);
                        // escape = true;
                        // break;
                        continue;
                    }

                    dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                    Q.push({nx, ny});
                }
                // if(escape) break;
            }

            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    // if (!brd[k][l]) continue;
                    dist[k][l] = -1;
                }
            }
        }
    }

    cout << ans;
}