#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, escape = 0;
    cin >> T;

    while (T--) {
        escape = 0;
        int r, c;
        cin >> c >> r;

        string brd[r];
        int Fdist[r][c];
        int Sdist[r][c];
        queue<pair<int, int>> FQ;
        queue<pair<int, int>> SQ;
        
        for (int i = 0; i < r; i++) {
            cin >> brd[i];

            fill(Fdist[i], Fdist[i]+c, -1);
            fill(Sdist[i], Sdist[i]+c, -1);

            for (int j = 0; j < c; j++) {
                if (brd[i][j] == '@') {
                    Sdist[i][j] = 0;
                    SQ.push({i, j});
                }

                else if (brd[i][j] == '*') {
                    Fdist[i][j] = 0;
                    FQ.push({i, j});
                }
            }
        }

        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        
        while (!FQ.empty()) {
            pair<int, int> cur = FQ.front(); FQ.pop();

            for (int k = 0; k < 4; k++) {
                int nx = cur.X + dx[k];
                int ny = cur.Y + dy[k];

                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if (brd[nx][ny] == '#' || Fdist[nx][ny] > -1) continue;

                FQ.push({nx, ny});
                Fdist[nx][ny] = Fdist[cur.X][cur.Y] + 1;
            }
        }

        while (!SQ.empty()) {
            pair<int, int> cur = SQ.front(); SQ.pop();

            for (int k = 0; k < 4; k++) {
                int nx = cur.X + dx[k];
                int ny = cur.Y + dy[k];

                if ( nx < 0 || nx >= r || ny < 0 || ny >= c) {
                    if (!escape)
                        escape = Sdist[cur.X][cur.Y] + 1;
                    continue;
                }
                if (Sdist[nx][ny] > -1 || brd[nx][ny] == '#') continue;
                if (Fdist[nx][ny] != -1 && Sdist[cur.X][cur.Y] + 1 >= Fdist[nx][ny]) continue;

                SQ.push({nx, ny});
                Sdist[nx][ny] = Sdist[cur.X][cur.Y] + 1;
            }
        }
        if (!escape) cout << "IMPOSSIBLE\n";
        else cout << escape << '\n';
    }
}