#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;

    cin >> T;

    while (T--) {
        int len, x1, y1, x2, y2;

        
        queue<pair<int, int>> Q;

        cin >> len;
        cin >> x1 >> y1;
        cin >> x2 >> y2;

        int brd[len][len];

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                brd[i][j] = -1;
            }
        }

        Q.push({x1, y1});
        brd[x1][y1] = 0;

        int dx[8] = {1,2,-1,-2,1,2,-1,-2};
        int dy[8] = {2,1,2,1,-2,-1,-2,-1};

        while (!Q.empty()) {
            pair<int, int> cur = Q.front(); Q.pop();

            for (int k = 0; k < 8; k++) {
                int nx = cur.X + dx[k];
                int ny = cur.Y + dy[k];

                if (nx < 0 || nx >= len || ny < 0 || ny >= len) continue;
                if (brd[nx][ny] != -1) continue;

                Q.push({nx, ny});
                brd[nx][ny] = brd[cur.X][cur.Y] + 1;
            }
        }

        cout << brd[x2][y2] << '\n';
    }
}