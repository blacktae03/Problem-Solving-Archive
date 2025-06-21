#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

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
    queue<pair<char, int>> Q;

    for (int i = 0; i < N; i++) {
        cin >> color[i];
        fill(CBvis[i], CBvis[i]+N, 0);
        fill(vis[i], vis[i]+N, 0);
    }

    for (int i = 0; i < N*N; i++) {
        if (vis[i/N][i%N]) continue;
        
        Q.push({color[i/N][i%N], i});
        vis[i/N][i%N] = 1;
        cnt++;

        while (!Q.empty()) {
            pair<char, int> cur = Q.front(); Q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = cur.Y / N + dx[k];
                int ny = cur.Y % N + dy[k];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (vis[nx][ny] || color[nx][ny] != cur.X) continue;

                Q.push({color[nx][ny], nx*N+ny});
                vis[nx][ny] = 1;
                
            }
        }
    }

    for (int i = 0; i < N*N; i++) {
        if (CBvis[i/N][i%N]) continue;
        
        Q.push({color[i/N][i%N], i});
        CBvis[i/N][i%N] = 1;
        CBcnt++;

        while (!Q.empty()) {
            pair<char, int> cur = Q.front(); Q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = cur.Y / N + dx[k];
                int ny = cur.Y % N + dy[k];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (CBvis[nx][ny]) continue;

                if (cur.X == 'B') {
                    if (color[nx][ny] != cur.X) continue;

                    Q.push({color[nx][ny], nx*N+ny});
                    CBvis[nx][ny] = 1;
                }

                else {
                    if (color[nx][ny] == 'B') continue;

                    Q.push({color[nx][ny], nx*N+ny});
                    CBvis[nx][ny] = 1;
                }
            }
        }
    }

    cout << cnt << ' ' << CBcnt;
}