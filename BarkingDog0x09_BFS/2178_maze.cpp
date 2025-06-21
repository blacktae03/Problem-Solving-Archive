#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;
    string brd[r];
    int vis[r][c];
    queue<pair<int, int>> Q;
    pair<int, int> cur;

    for (int i = 0; i < r; i++) {
        cin >> brd[i];
        fill(vis[i], vis[i]+c, 0);
    }

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    Q.push({0, 0});
    vis[0][0] = 1;
    
    while (!Q.empty()) {
        cur = Q.front(); Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(brd[nx][ny] == '1' && vis[nx][ny] == 0) {
                Q.push({nx, ny});
                vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            }
        }
    }

    cout << vis[r-1][c-1];
}