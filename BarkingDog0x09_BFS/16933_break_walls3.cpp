#include <bits/stdc++.h>
using namespace std;
#define X get<0>(cur)
#define Y get<1>(cur)
#define K get<2>(cur)
#define T get<3>(cur)

int dist[1000][1000][11][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c, k;
    cin >> r >> c >> k;

    string brd[r];

    for (int i = 0; i < r; i++) {
        cin >> brd[i]; 
    }

    queue<tuple<int, int, int, bool>> Q;

    Q.push({0,0,0,false});
    dist[0][0][0][0] = 1;

    int dx[5] = {0,1,0,-1,0};
    int dy[5] = {0,0,1,0,-1};

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 5; dir++) {
            int nx = X + dx[dir];
            int ny = Y + dy[dir];
            int nk = K;
            int nt = !T;

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (!dir && !dist[nx][ny][nk][nt]) {
                dist[nx][ny][nk][nt] = dist[X][Y][K][T] + 1;
                Q.push({nx, ny, nk, nt});
            } 
            else if (dir > 0 && brd[nx][ny] == '0' && !dist[nx][ny][nk][nt]) {
                dist[nx][ny][nk][nt] = dist[X][Y][K][T] + 1;
                Q.push({nx, ny, nk, nt});
            }
            else if (dir > 0 && brd[nx][ny] == '1' && !dist[nx][ny][nk+1][nt] && nk < k && nt) {
                dist[nx][ny][nk+1][nt] = dist[X][Y][K][T] + 1;
                Q.push({nx, ny, nk+1, nt}); 
            }
        }
    }

    int ans = 1000000000;

    for (int i = 0; i < k+1; i++) {
        for (int j = 0; j < 2; j++) {
            if (!dist[r-1][c-1][i][j]) continue;
            ans = min(ans, dist[r-1][c-1][i][j]);
        }
    }

    if (ans == 1000000000) cout << -1;
    else cout << ans;
}