#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string brd[5];
bool isvis[5][5];
bool vis[5][5];
int cnt, scnt, con;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int, int>> Q;

bool close() {
    for (int i = 0; i < 25; i++) {
        if (!isvis[i/5][i%5]) continue;
        vis[i/5][i%5] = 1;
        Q.push({i/5, i%5});
        break;
    }

    con = 1;

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (vis[nx][ny] || !isvis[nx][ny]) continue;

            Q.push({nx, ny});
            vis[nx][ny] = 1;
            con++;
        }
    }

    for (int i = 0; i < 5; i++) fill(vis[i], vis[i]+5, 0);

    if (con == 7) return 1;
    return 0;
}

void solve(int k, int l) {
    if (k - scnt > 3) return;
    if (k == 7) {
        if (!close()) return;
        cnt++;
        return;
    }

    for (int i = l; i < 25; i++) {
        if(isvis[i/5][i%5]) continue;
        isvis[i/5][i%5] = 1;
        if(brd[i/5][i%5] == 'S') scnt++;
        solve(k+1, i+1);
        isvis[i/5][i%5] = 0;
        if(brd[i/5][i%5] == 'S') scnt--;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++) cin >> brd[i];
    
    solve(0, 0);

    cout << cnt;
}