#include <bits/stdc++.h>
using namespace std;
#define X get<0>(cur)
#define Y get<1>(cur)
#define K get<2>(cur)

int dist[1000][1000][11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c, k;
    cin >> r >> c >> k;

    string brd[r];
    
    for (int i = 0; i < r; i++) {
        cin >> brd[i];
    }

    queue<tuple<int, int, int>> Q;

    Q.push({0, 0, 0});
    dist[0][0][0] = 1;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = X + dx[dir];
            int ny = Y + dy[dir];
            int nk = K;

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (brd[nx][ny] == '0' && !dist[nx][ny][nk]) {
                dist[nx][ny][nk] = dist[X][Y][K] + 1;
                Q.push({nx, ny, nk});    
            }
            if (brd[nx][ny] == '1' && nk < k && !dist[nx][ny][nk+1]) {
                dist[nx][ny][nk+1] = dist[X][Y][K] + 1;
                Q.push({nx, ny, nk+1});
            }
        }
    }

    int ans = 1000000;
    for (int i = 0; i < k+1; i++) {
        if (!dist[r-1][c-1][i]) continue;
        ans = min(ans, dist[r-1][c-1][i]);
    }

    if (ans == 1000000) cout << -1;
    else cout << ans;
}