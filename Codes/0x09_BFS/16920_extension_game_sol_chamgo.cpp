#include <bits/stdc++.h>
using namespace std;
#define X get<0>(cur)
#define Y get<1>(cur)
#define N get<2>(cur)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c, p;
    cin >> r >> c >> p;
    int pc[p+1];
    string brd[r];
    bool vis[r][c];
    
    for (int i = 1; i < p+1; i++) {
        cin >> pc[i];
    }

    for (int i = 0; i < r; i++) {
        cin >> brd[i];
        fill(vis[i], vis[i]+c, 0);
    }

    queue<tuple<int, int, int>> Q[10];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(brd[i][j] == '#' || brd[i][j] == '.') continue;
            Q[brd[i][j]-'0'].push({i,j,0});
            vis[i][j] = 1;
        }
    }

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int turn = 1;
    bool escape = true;

    while(true) {
        escape = true;
        for (int k = 1; k <= p; k++) {
            while (!Q[k].empty()) {
                auto cur = Q[k].front();
                if (N >= pc[k] * turn) break;
                Q[k].pop();
        
                for (int dir = 0; dir < 4; dir++) {
                    int nx = X + dx[dir];
                    int ny = Y + dy[dir];
                    int nn = N + 1;
        
                    if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                    if (brd[nx][ny] != '.') continue;
        
                    brd[nx][ny] = brd[X][Y];
                    vis[nx][ny] = 1;
                    Q[k].push({nx, ny, nn});
                    escape = false;
                }
            }
        }
        turn++;

        if(escape) break;
    }

    

    

    int ans[p] = {0,};

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ans[brd[i][j]-'1']++;
        }
    }

    for (auto num : ans) cout << num << ' ';
}