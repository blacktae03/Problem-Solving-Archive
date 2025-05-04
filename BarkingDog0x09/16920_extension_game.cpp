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
    int pc[p];
    string brd[r];
    
    for (int i = 0; i < p; i++) {
        cin >> pc[i];
    }

    for (int i = 0; i < r; i++) {
        cin >> brd[i];
    }

    queue<tuple<int, int, int>> Q;

    for (char k = '1'; k <= '0'+p; k++) {
        for (int i = 0; i < r; i++) {   
            for (int j = 0; j < c; j++) {
                if (k == brd[i][j]) {
                    Q.push({i, j, 0});
                }
            }
        }

        
    }

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int cnt = 1;

    

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = X + dx[dir];
            int ny = Y + dy[dir];
            int nn = N + 1;

            if (nx < 0 || nx >= r || ny < 0 || ny >= c || nn > pc[(brd[X][Y]-'1')] * cnt) continue;
            if (brd[nx][ny] != '.') continue;

            brd[nx][ny] = brd[X][Y];
            Q.push({nx, ny, nn});
        }

        cnt++;
    }

    int ans[p] = {0,};

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ans[brd[i][j]-'1']++;
        }
    }

    for (auto num : ans) cout << num << ' ';
}