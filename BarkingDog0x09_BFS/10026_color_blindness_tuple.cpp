#include <bits/stdc++.h>
using namespace std;
#define X get<1>(cur)
#define Y get<2>(cur)
#define Z get<0>(cur)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    string color[N];
    bool CBvis[N][N];
    bool vis[N][N];
    int CBcnt = 0;
    int cnt = 0;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
//    queue<pair<char, int>> CBQ;
    queue<tuple<char, int, int>> Q; // tuple로 해도 정답 나옴.

    for (int i = 0; i < N; i++) {
        cin >> color[i];
        fill(CBvis[i], CBvis[i]+N, 0);
        fill(vis[i], vis[i]+N, 0);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (vis[i][j]) continue;
            
            Q.push({color[i][j], i, j});
            vis[i][j] = 1;
            cnt++;

            while (!Q.empty()) {
                tuple<char, int, int> cur = Q.front(); Q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = X + dx[k];
                    int ny = Y + dy[k];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (vis[nx][ny] || color[nx][ny] != Z) continue;

                    Q.push({color[nx][ny], nx, ny});
                    vis[nx][ny] = 1;
                    
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (CBvis[i][j]) continue;
            
            Q.push({color[i][j], i, j});
            CBvis[i][j] = 1;
            CBcnt++;

            while (!Q.empty()) {
                tuple<char, int, int> cur = Q.front(); Q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = X + dx[k];
                    int ny = Y + dy[k];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (CBvis[nx][ny]) continue;

                    if (Z == 'B') {
                        if (color[nx][ny] != Z) continue;

                        Q.push({color[nx][ny], nx, ny});
                        CBvis[nx][ny] = 1;
                    }

                    else {
                        if (color[nx][ny] == 'B') continue;

                        Q.push({color[nx][ny], nx, ny});
                        CBvis[nx][ny] = 1;
                    }
                }
            }
        }
    }

    cout << cnt << ' ' << CBcnt;
}