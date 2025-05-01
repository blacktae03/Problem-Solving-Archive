#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, maxcnt = 0, cnt = 0;
    cin >> N;

    int brd[N][N];
    bool vis[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> brd[i][j];
            vis[i][j] = 0;
        }
    }

    

    for (int k = 0; k <= 100; k++) {
        cnt = 0;
        queue<pair<int, int>> Q;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                vis[i][j] = 0;
            }
        }

        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (brd[i][j] <= k || vis[i][j]) continue;
                
                cnt++;
                Q.push({i, j});
                vis[i][j] = 1;
                

                while (!Q.empty()) {
                    pair<int, int> cur = Q.front(); Q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if (brd[nx][ny] <= k || vis[nx][ny]) continue;

                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        maxcnt = max(maxcnt, cnt);
    }

    cout << maxcnt;
}