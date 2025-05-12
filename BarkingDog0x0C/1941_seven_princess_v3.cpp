#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string brd[5];
bool isvis[5][5];
int cnt, scnt;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool close(int x, int y) {
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        if (isvis[nx][ny]) return 1;
    }
    return 0;
}

void solve(int k, int c) {
    if (c - scnt > 3) return;
    if (c == 7) { 
        for (int i = 0; i < 25; i++) {
            if(!isvis[i/5][i%5]) continue;
            if(!close(i/5, i%5)) return;
        }
        cnt++;
        return;
    }
    if (k >= 25) return;
    if (brd[k/5][k%5] == 'S') scnt++;
    isvis[k/5][k%5] = 1;
    solve(k+1, c+1);
    if (brd[k/5][k%5] == 'S') scnt--;
    isvis[k/5][k%5] = 0;
    solve(k+1, c);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++) cin >> brd[i];
    
    solve(0, 0);

    cout << cnt;
}