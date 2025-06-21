#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

bool brd[101][101];
bool vis[101][101];
// bool on[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N, M;

bool OOB(int nx, int ny) { return nx < 1 || nx > N || ny < 1 || ny > N; }

bool is_conn(pair<int, int> nxt) { // (1,1)에서 nxt가 도달 가능한 칸인가?
    for (int dir = 0; dir < 4; dir++) {
      int nx = nxt.X + dx[dir];
      int ny = nxt.Y + dy[dir];
      if (OOB(nx, ny)) continue;
      if (vis[nx][ny]) return 1;
    }
    return 0;
  }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    queue<pair<int, int>> LQ[N+1][N+1];
    int x, y, a, b;
    queue<pair<int, int>> Q;

    while (M--) {
        cin >> x >> y >> a >> b;
        LQ[x][y].push({a, b});
    }

    Q.push({1, 1});
    vis[1][1] = 1;
    brd[1][1] = 1;
    
    int ans = 0;

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        while(!LQ[cur.X][cur.Y].empty()) {
            auto curL = LQ[cur.X][cur.Y].front(); LQ[cur.X][cur.Y].pop();
            
            if (is_conn(curL)) {
                vis[curL.X][curL.Y] = 1;
                Q.push({curL.X, curL.Y});
            }
            brd[curL.X][curL.Y] = 1;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (vis[nx][ny] || !brd[nx][ny]) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ans += brd[i][j];
        }
    }
    cout << ans;
}
