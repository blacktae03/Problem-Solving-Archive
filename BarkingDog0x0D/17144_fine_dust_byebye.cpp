// 오늘은 뭔가 자신감도 떨어지고 잘 안되는 날이네.. 겨우 이거라도 풀었는데 너무 더럽게 풀었다 내일 답 확인해보자

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int R, C, T;
int brd[52][52], tmp[52][52];
bool vis[52][52];
queue<pair<int, int>> Q;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int ac1, ac2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> T;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> brd[i][j];
            if (brd[i][j] > 0) Q.push({i, j});
            if (brd[i][j] < 0) ac2 = i;
        }
    }
    ac1 = ac2-1;

    for (int i = 0; i < R; i++) {
        if(!i || i == R-1 || i == ac1 || i == ac2) {
            for (int j = 0; j < C; j++) vis[i][j] = 1;
        }

        else {
            vis[i][0] = 1;
            vis[i][C-1] = 1;
        }
    }
    vis[ac1][0] = 0;
    vis[ac2][0] = 0;

    int sum = 0;

    while(T--) {
        sum = 0;
        int Qsize = Q.size();

        while (Qsize--) {
            auto cur = Q.front(); Q.pop();
            int dif = brd[cur.X][cur.Y] / 5;

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (brd[nx][ny] == -1) continue;

                tmp[nx][ny] += dif;
                brd[cur.X][cur.Y] -= dif;
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                brd[i][j] += tmp[i][j];
                tmp[i][j] = 0;
            }
        }

        for (int i = 0; i <= ac1; i++) {
            if (!i) {
                for (int j = C-1; j > 0; j--) {
                    tmp[i][j-1] = brd[i][j]; // j == 0일 때는 안됨.
                }
                tmp[i][C-1] = brd[i+1][C-1];
            }
            else if (i == ac1) {
                for (int j = 1; j < C-1; j++) {
                    tmp[i][j+1] = brd[i][j]; // j == C-1일 때는 안됨.
                }
                // 굳이 할필요 없음 공기청정기 자리라서
            }
            else {
                tmp[i][0] = brd[i-1][0];
                tmp[i][C-1] = brd[i+1][C-1];
            }
        }
        for (int i = ac2; i < R; i++) {
            if (i == R-1) {
                for (int j = C-1; j > 0; j--) {
                    tmp[i][j-1] = brd[i][j]; // j == 0일 때는 안됨.
                }
                tmp[i][C-1] = brd[i-1][C-1];
            }
            else if (i == ac2) {
                for (int j = 1; j < C-1; j++) {
                    tmp[i][j+1] = brd[i][j]; // j == C-1일 때는 안됨.
                }
            }
            else {
                tmp[i][0] = brd[i+1][0];
                tmp[i][C-1] = brd[i-1][C-1];
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (vis[i][j]) {
                    brd[i][j] = tmp[i][j];
                }
                tmp[i][j] = 0;
            }
        }
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (brd[i][j] <= 0) continue;
                Q.push({i, j});
                sum += brd[i][j];
            }
        }
    }

    cout << sum;
}