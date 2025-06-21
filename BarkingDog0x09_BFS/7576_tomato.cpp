#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> c >> r; // 행, 열 반대로 문제 쳐 만드네 화나게..

    int tmt[r][c];
    int day[r][c];
    queue<pair<int, int>> Q;
    pair<int, int> cur;
    int min = 0;

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> tmt[i][j];
            day[i][j] = 0;
            if (tmt[i][j] == 1)
                Q.push({i, j});
        }
    }

    while (!Q.empty()) {
        cur = Q.front(); Q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (tmt[nx][ny] < 0) continue;
            if (tmt[nx][ny] == 0 && day[nx][ny] == 0) {
                tmt[nx][ny] = 1;
                day[nx][ny] = day[cur.X][cur.Y] + 1;
                min = day[nx][ny];
                Q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (tmt[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }
    }
    

    cout << min;
}