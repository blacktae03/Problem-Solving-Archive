#include <bits/stdc++.h>
using namespace std;
#define X second.first
#define Y second.second
#define Z first

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    string maze[r];
    //int dist[r][c];
    queue<pair<char, pair<int, int>>> Q; 
    pair<char, pair<int, int>> cur;
    int cnt = 0;

    for (int i = 0; i < r; i++) {
        cin >> maze[i];
        //fill(dist[i], dist[i]+c, 0);

        for (int j = 0; j < c; j++) {
            if (maze[i][j] == 'F') {
                Q.push({'F', {i, j}});
            }

            else if (maze[i][j] == '#' || maze[i][j] == '.') {
                // dist[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (maze[i][j] == 'J') { // J는 마지막에 움직여야함.
                Q.push({'J', {i, j}});
            }
        }
    }

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    while (!Q.empty()) {
        cur = Q.front(); Q.pop();

        //if (maze[cur.X][cur.Y] == '#' || maze[cur.X][cur.Y] == '.') continue;

        for (int k = 0; k < 4; k++) {
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
                if (cur.Z == 'J') {
                    cout << cnt + 1;
                    return 0;
                }
                continue;
            }
            if (maze[nx][ny] == '#' || maze[nx][ny] == 'F') continue;

            if (cur.Z == 'F') {
                maze[nx][ny] = 'F';
                //dist[nx][ny] = -1;
                Q.push({'F', {nx, ny}});
            }
            if (cur.Z == 'J') {
                cnt++;
                Q.push({'J', {nx, ny}});
                // if( k == 3 && maze[cur.X][cur.Y] == 'F') dist[cur.X][cur.Y] = -1;
            }

            
        }
    }

    cout << "IMPOSSIBLE";

}