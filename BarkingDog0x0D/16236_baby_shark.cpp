#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

struct fish
{
    int size;
    int distOrEaten;
    pair<int, int> loc;
};

int N, bssize = 2, ans;
int brd[21][21], dist[21][21];
fish bs, treat;
queue<pair<int, int>> Q;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        fill(dist[i], dist[i]+21, -1);
        for (int j = 0; j < N; j++) {
            cin >> brd[i][j];

            if (brd[i][j] == 9) {
                bs.size = 2;
                bs.distOrEaten = 0;
                bs.loc = {i, j};
            }
        }
    }

    treat = {0, 500, {20, 20}};

    bool mom = 0;

    while(true) {
        mom = 1;
        Q.push(bs.loc);
        dist[bs.loc.X][bs.loc.Y] = 0;

        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (dist[nx][ny] > -1 || brd[nx][ny] > bs.size) continue;
                
                Q.push({nx, ny});
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;

                if (brd[nx][ny] > 0 && brd[nx][ny] < bs.size && (dist[nx][ny] < treat.distOrEaten || (dist[nx][ny] == treat.distOrEaten && (nx < treat.loc.X || (nx == treat.loc.X && ny < treat.loc.Y))))) {
                    mom = 0;
                    treat.size = brd[nx][ny];
                    treat.distOrEaten = dist[nx][ny];
                    treat.loc = {nx, ny};
                }
            }
        } // 먹이 찾기

        if (mom) break;

        ans += treat.distOrEaten;
        brd[bs.loc.X][bs.loc.Y] = 0;
        brd[treat.loc.X][treat.loc.Y] = 9;
        bs.distOrEaten++;
        bs.loc = treat.loc;

        if(bs.distOrEaten == bs.size) {
            bs.size++;
            bs.distOrEaten = 0;
        }
        
        for (int i = 0; i < N; i++) fill(dist[i], dist[i]+21, -1);

        treat = {0, 500, {20, 20}};
    }

    cout << ans;
}