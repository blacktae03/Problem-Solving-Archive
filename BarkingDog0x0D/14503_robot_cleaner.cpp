#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int r, c, x, y, d, ans;
bool brd[51][51], vis[51][51];
queue<pair<int, int>> Q;
bool notclean, esc = 1, go;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> x >> y >> d;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> brd[i][j];
        }
    }

    while(esc) {
        notclean = 0;
        go = 0;
        vis[x][y] = 1; // 1

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (vis[nx][ny] || brd[nx][ny]) continue;

            notclean = 1;
        }

        if (!notclean) {
            switch(d) {
                case 0 :
                    if (brd[++x][y]) esc = 0;
                    break;
                
                case 1 :
                    if (brd[x][--y]) esc = 0;
                    break;

                case 2 :
                    if (brd[--x][y]) esc = 0;
                    break;
                
                case 3 :
                    if (brd[x][++y]) esc = 0;
                    break;
            }
        } // 2

        else {
            d += 3;
            for (int i = 0; i < 4; i++) {
                switch(d % 4) {
                    case 0 :
                        if (!vis[x-1][y] && !brd[x-1][y]) {go = 1; x--; d %= 4; }
                        break;
                    
                    case 1 :
                        if (!vis[x][y+1] && !brd[x][y+1]) {go = 1; y++; d %= 4; }
                        break;
                    
                    case 2 :
                        if (!vis[x+1][y] && !brd[x+1][y]) {go = 1; x++; d %= 4; }
                        break;
                    
                    case 3 :
                        if (!vis[x][y-1] && !brd[x][y-1]) {go = 1; y--; d %= 4; }
                        break;
                }

                if (go) break;
                d--;
            }
        } // 3
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ans += vis[i][j];
        }
    }

    cout << ans;
}