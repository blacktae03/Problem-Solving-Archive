#include <bits/stdc++.h>
using namespace std;
#define X get<0>(cur)
#define Y get<1>(cur)
#define Z get<2>(cur)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int horse, r, c;
    cin >> horse >> c >> r;
    
    int brd[r][c];
    int dist[r][c][horse+1];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> brd[i][j];
            fill(dist[i][j], dist[i][j]+horse+1, -1);
        }
    }

    queue<tuple<int, int, int>> Q;

    dist[0][0][0] = 0;
    Q.push({0, 0, 0});
    

    int hdx[8] = {2,2,1,1,-1,-1,-2,-2};
    int hdy[8] = {1,-1,2,-2,2,-2,1,-1}; 

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    int ans = -1;
    if (r == 1 && c == 1)ans = 0; // 이런 예외처리를 할바엔 sol 처럼 그냥 다 하고 최솟값 구하는게 나을지도...
    
    bool escape = false;
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 8; dir++) {
            int nx = X + hdx[dir];
            int ny = Y + hdy[dir];
            int nz = Z + 1;

            if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz > horse) continue;
            if (brd[nx][ny] || dist[nx][ny][nz] > -1) continue;

            Q.push({nx, ny, nz});
            dist[nx][ny][nz] = dist[X][Y][Z] + 1;

            if (nx == r-1 && ny == c-1) {
                ans = dist[nx][ny][nz];
                escape = true;
                break;
            }
        }
        

        if (escape) break;

        for (int dir = 0; dir < 4; dir++) {
            int nx = X + dx[dir];
            int ny = Y + dy[dir];
            int nz = Z;
            
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (brd[nx][ny] || dist[nx][ny][nz] > -1) continue;
            
            Q.push({nx, ny, nz});
            dist[nx][ny][nz] = dist[X][Y][Z] + 1;

            if (nx == r-1 && ny == c-1) {
                ans = dist[nx][ny][nz];
                escape = true;
                break;
            }
        }

        if (escape) break;       
    }

    cout << ans;

}