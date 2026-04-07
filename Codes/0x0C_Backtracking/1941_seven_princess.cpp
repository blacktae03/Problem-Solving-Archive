#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string brd[5];
bool isvis[5][5];
int cnt, scnt;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<pair<int, int>> v;

void solve(int k, int x, int y) {
    if (k - scnt > 3) return;
    if (k == 7) { cnt++; return; }

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        if (isvis[nx][ny]) continue;
        v.push_back({nx, ny});
    }

    for (auto p : v) {
        if (isvis[p.X][p.Y]) continue;
        if (brd[p.X][p.Y] == 'S') scnt++; 
        isvis[p.X][p.Y] = 1;
        solve(k+1, p.X, p.Y);
        isvis[p.X][p.Y] = 0;
        if (brd[p.X][p.Y] == 'S') scnt--;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++) cin >> brd[i];
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            isvis[i][j] = 1;
            solve(1, i, j);
            isvis[i][j] = 0;
        }
    }

    cout << cnt;
}