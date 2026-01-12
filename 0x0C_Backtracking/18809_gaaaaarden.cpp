#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int brd[50][50], grow[10];
pair<int, int> where[10];
pair<int, char> dist[50][50];
int r, c, green, red, grcnt, fcnt;
queue<tuple<int, int, char>> Q;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> green >> red;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> brd[i][j];
            if (brd[i][j] == 2) {
                where[grcnt] = {i, j};
                grcnt++;
            }
        }
    }

    fill(grow, grow+green, 1);
    fill(grow+green, grow+green+red, 2);
    sort(grow, grow+grcnt);

    do {
        int cnt = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                dist[i][j] = {-1, 'N'};
            }
        }

        for (int i = 0; i < grcnt; i++) {
            if(grow[i] == 1) { dist[where[i].X][where[i].Y] = {0, 'G'}; Q.push({where[i].X, where[i].Y, 'G'}); }
            else if(grow[i] == 2) { dist[where[i].X][where[i].Y] = {0, 'R'}; Q.push({where[i].X, where[i].Y, 'R'}); }
        }

        while (!Q.empty()) {
            int x, y;
            char k;
            tie(x, y, k) = Q.front(); Q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if (!brd[nx][ny]) continue;
                
                if ((k == 'G' && dist[nx][ny].Y == 'R' && dist[nx][ny].X == dist[x][y].X + 1) || (k == 'R' && dist[nx][ny].Y == 'G' && dist[nx][ny].X == dist[x][y].X + 1)) {
                    dist[nx][ny] = {dist[x][y].X + 1, 'F'};
                    cnt++;
                }
                if (dist[nx][ny].Y == 'N') {
                    dist[nx][ny] = {dist[x][y].X + 1, k};
                    Q.push({nx, ny, k});
                }
                // N이면 BFS
                // 내가 G이고 새로운게 R이면 또는 반대면 F  로 바꾸고 카운트 증가 (푸쉬안함)
            }
        }

        fcnt = max(fcnt, cnt);

    } while (next_permutation(grow, grow+grcnt));

    cout << fcnt;
}