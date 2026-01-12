#include <bits/stdc++.h>
using namespace std;
#define X get<1>(cur)
#define Y get<2>(cur)
#define Z get<0>(cur)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;
    
    string brd[r];
    int dist[2][r][c];

    for (int i = 0; i < r; i++) {
        cin >> brd[i];
        fill(dist[0][i], dist[0][i]+c, -1);
        fill(dist[1][i], dist[1][i]+c, -1);
    }

    queue<tuple<int, int, int>> Q;
    Q.push({0,0,0});
    dist[0][0][0] = 1;

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    while(!Q.empty()) {
        tuple<int, int, int> cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int brk = Z;
            int nx = X + dx[dir];
            int ny = Y + dy[dir];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;

            if (brd[nx][ny] == '0' && dist[brk][nx][ny] < 0) {
                Q.push({brk, nx, ny});
                dist[brk][nx][ny] = dist[Z][X][Y] + 1;
            }

            if (brd[nx][ny] == '1' && brk == 0 && dist[1][nx][ny] < 0) {
                Q.push({1, nx, ny});
                dist[1][nx][ny] = dist[Z][X][Y] + 1;
            }
        }
    }

    int ans;

    // cout << dist[0][r-1][c-1] << ' ' << dist[1][r-1][c-1] << '\n';

    if (dist[0][r-1][c-1] == -1 || dist[1][r-1][c-1] == -1) ans = max(dist[0][r-1][c-1], dist[1][r-1][c-1]);
    else ans = min(dist[0][r-1][c-1], dist[1][r-1][c-1]);

    cout << ans;
}