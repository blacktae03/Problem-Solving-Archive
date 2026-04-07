#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

bool brd[105][105];
bool vis1[105][105];
bool vis2[105][105];
bool on[105][105];
bool cnt[105][105];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, x, y, a, b;
    

    cin >> N >> M;

    queue<pair<int, int>> Q;
    queue<pair<int, int>> LQ[N+1][N+1];
    queue<pair<int, int>> LQ2[N+1][N+1];
    

    for (int i = 0; i < M; i++) {
        cin >> x >> y >> a >> b;
        LQ[x][y].push({a, b});
        LQ2[x][y].push({a, b});
        brd[a][b] = 1;
    } // 1. 일단 불 다 키는 과정

    Q.push({1, 1});
    brd[1][1] = 1;
    on[1][1] = 1;

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        while(!LQ[cur.X][cur.Y].empty()) {
            auto curL = LQ[cur.X][cur.Y].front(); LQ[cur.X][cur.Y].pop();
            on[curL.X][curL.Y] = 1;
        }
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (!brd[nx][ny] || vis1[nx][ny]) continue;

            vis1[nx][ny] = 1;
            Q.push({nx, ny});
        }
    } // 3. 방문 가능한 곳(== 1,1과 인접한 곳)에서 불 킬 수 있는 곳 다 킴.

    Q.push({1, 1});
    cnt[1][1] = 1;
    int ans = 0;

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        // if (!vis[cur.X][cur.Y] || !on[cur.X][cur.Y]) continue;

        while(!LQ2[cur.X][cur.Y].empty()) {
            auto curL = LQ2[cur.X][cur.Y].front(); LQ2[cur.X][cur.Y].pop();
            cnt[curL.X][curL.Y] = 1;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (vis2[nx][ny] || !brd[nx][ny] || !on[nx][ny]) continue;
            
            vis2[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ans += cnt[i][j];
        }
    }
    
    cout << ans;
}