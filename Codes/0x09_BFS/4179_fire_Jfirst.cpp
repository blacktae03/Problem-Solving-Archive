#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    string maze[r];
    int dist[r][c];
    queue<pair<int, int>> Q; 
    pair<int, int> cur;
    int cnt = 0;

    for (int i = 0; i < r; i++) {
        cin >> maze[i];
        fill(dist[i], dist[i]+c, 0);

        for (int j = 0; j < c; j++) {
            if (maze[i][j] == 'J') { // J는 마지막에 움직여야함.
                Q.push({i, j});
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (maze[i][j] == 'F') {
                Q.push({i, j});
                dist[i][j] = -1;
            }

            else if (maze[i][j] == '#' || maze[i][j] == '.') {
                dist[i][j] = -1;
            }
        }
    }

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    while (!Q.empty()) {
        cur = Q.front(); Q.pop();

        // if (maze[cur.X][cur.Y] == '#' || maze[cur.X][cur.Y] == '.') continue;

        for (int k = 0; k < 4; k++) {
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];

            // if (dist[cur.X][cur.Y] >= 0 && maze[cur.X][cur.Y] != 'F' && (nx < 0 || nx >= r || ny < 0 || ny >= c)) {
            //     cout << dist[cur.X][cur.Y] + 1;
            //     return 0;
            // }

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (maze[nx][ny] == '#' || maze[nx][ny] == 'F') continue;

            if (dist[cur.X][cur.Y] == 'J') {
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
            if (maze[cur.X][cur.Y] == 'F') {
                maze[nx][ny] = 'F';
                Q.push({nx, ny});
            }

            
        }
    }

}