#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main () {
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

    queue<pair<int, int>> Q;

    int num = 0;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!brd[i][j] || vis[i][j] != -1) continue;
            
            Q.push({i, j});
            vis[i][j] = 1;
            brd[i][j] = num;

            while (!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (vis[nx][ny] != -1) continue;
                    vis[nx][ny] = num;
                    if (!brd[nx][ny]) continue;
                    
                    Q.push({nx, ny});
                }
            }
            num++;
        }
    } // 섬 주변 바다 한 칸까지 방문표시 하기.

    int length = 10000;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!brd[i][j] && vis[i][j] != -1) {
                Q.push({i, j});
                dist[i][j] = 1;
                
                while(!Q.empty()) {
                    pair<int, int> cur = Q.front(); Q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        
                        if (brd[nx][ny] == 1) {
                            if (vis[nx][ny] != vis[cur.X][cur.Y]) length = min(length, dist[cur.X][cur.Y]);
                            continue;
                        }
                        // if (vis[nx][ny] == vis[cur.X][cur.Y]) continue;
                        if (vis[nx][ny] == vis[cur.X][cur.Y] && dist[nx][ny] > -1 && dist[cur.X][cur.Y]+1 > dist[nx][ny]) continue;
                        // if (vis[nx][ny] == vis[cur.X][cur.Y] && brd[nx][ny] == 1) continue;
                        Q.push({nx, ny});
                        
                        dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                        
                    }
                }
            }
            
        }
    }

    cout << length;
}