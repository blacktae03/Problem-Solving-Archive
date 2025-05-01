#include <bits/stdc++.h>
using namespace std;
#define X get<0>(cur)
#define Y get<1>(cur)
#define Z get<2>(cur)

int main() {
    int l, r, c;

    while(true) {
        cin >> l >> r >> c;

        if (!l && !r && !c) break;

        queue<tuple<int, int, int>> Q;

        string brd[l][r];
        int dist[l][r][c];
        
        int dx[6] = {1,0,0,-1,0,0};
        int dy[6] = {0,1,0,0,-1,0};
        int dz[6] = {0,0,1,0,0,-1};

        int escape = 0;

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                cin >> brd[i][j];
                for (int k = 0; k < c; k++) {
                    dist[i][j][k] = -1;
                    if (brd[i][j][k] == 'S') {
                        dist[i][j][k] = 0;
                        Q.push({i, j, k});
                    }
                }
            }
        }
    
    
        while (!Q.empty()) {
            tuple<int, int, int> cur = Q.front(); Q.pop();

            for (int dir = 0; dir < 6; dir++) {
                int nx = X + dx[dir];
                int ny = Y + dy[dir];
                int nz = Z + dz[dir];

                if (nx < 0 || nx >= l || ny < 0 || ny >= r || nz < 0 || nz >= c) continue;
                if (brd[nx][ny][nz] == '#' || dist[nx][ny][nz] >= 0) continue;

                if (brd[nx][ny][nz] == 'E') escape = dist[X][Y][Z] + 1;

                dist[nx][ny][nz] = dist[X][Y][Z] + 1;
                Q.push({nx, ny, nz});
            }
        }

        if (escape > 0) cout << "Escaped in " << escape << " minute(s).\n";
        else cout << "Trapped!\n";
    }
    
}