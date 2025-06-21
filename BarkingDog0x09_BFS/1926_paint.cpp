#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;

    queue<pair<int,int>> Q;
    pair<int, int> cur;
    int pnt[r][c];
    bool vis[r][c];
    int area = 0, cnt = 0, acnt = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> pnt[i][j];
            vis[i][j] = 0;
        }
    }

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            
            if (pnt[i][j] == 1 && vis[i][j] == 0) {
                cnt++;
                
                Q.push({i,j});
                vis[i][j] = 1;

                while (!Q.empty()) {
                    cur = Q.front();
                    for (int k = 0; k < 4; k++) {
                        int nx = cur.X + dx[k];
                        int ny = cur.Y + dy[k];
                        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                        
                        if (pnt[nx][ny] == 1 && vis[nx][ny] == 0) {
                            vis[nx][ny] = 1;
                            Q.push({nx, ny});
                        }
                    }   
                    Q.pop();
                    acnt++; // 넓이가 이상함.
                }
                area = max(area, acnt);
                acnt = 0;
            }
        }
    }

    cout << cnt << '\n' << area;
}