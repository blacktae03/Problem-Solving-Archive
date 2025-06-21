#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string brd[5];
bool isvis[5][5];
int cnt, scnt;
vector<pair<int, int>> v;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void close(int x, int y) {
    // if (!k) return 1;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        if (isvis[nx][ny]) continue;

        v.push_back({nx, ny});
    }
}

void solve(int k) {
    if (k - scnt > 3) return;
    if (k == 7) {
        cnt++;
        return;
    }

    for (auto p : v) {
        if (isvis[p.X][p.Y]) continue;
        if (brd[p.X][p.Y] == 'S') scnt++;
        isvis[p.X][p.Y] = 1;
        close(p.X, p.Y);
        solve(k+1);
        if (brd[p.X][p.Y] == 'S') scnt--;
        isvis[p.X][p.Y] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++) cin >> brd[i];
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (brd[i][j] == 'Y') continue;
            v.push_back({i, j});
            solve(0);
        }
    }

    cout << cnt;
}