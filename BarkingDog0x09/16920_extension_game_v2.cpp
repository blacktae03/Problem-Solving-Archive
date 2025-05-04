#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c, p;
    cin >> r >> c >> p;
    int pc[p];
    string brd[r];
    int dist[r][c];
    
    for (int i = 0; i < p; i++) {
        cin >> pc[i];
    }

    for (int i = 0; i < r; i++) {
        cin >> brd[i];
        fill(dist[i], dist[i]+c, 0);
    }

    queue<pair<int, int>> Q;

    

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int turn = 0;
    int rcnt = 0;
    bool escape = false;

    while(true) {
        escape = true;
        for (char k = '1'; k <= '0'+p; k++) {
            // escape 과정을 바꾸니까 통과됨. 원래 escape 과정 : 문자열에서 길 개수(. 개수) 센 다음 0개면 탈출가능하게했음.
            // 그냥 무조건 실행하는 문장이라 시간복잡도가 N^2 이상으로 올라간 듯.
            
            for (int i = 0; i < r; i++) {   
                for (int j = 0; j < c; j++) {
                    if (k == brd[i][j] && dist[i][j] == turn * pc[k - '1']) {
                        Q.push({i, j});
                    }
                    // if (brd[i][j] == '.') rcnt++; 이 방법 없애니까 됨.
                }
            }

            while (!Q.empty()) {
                auto cur = Q.front(); Q.pop();
        
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
        
                    if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                    if (brd[nx][ny] != '.') continue;
        
                    brd[nx][ny] = brd[cur.X][cur.Y];
                    dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                    escape = false;
                    if (dist[nx][ny] < pc[k-'1'] * (turn+1)) Q.push({nx, ny});
                }
            }
        }
        turn++;

        if(escape) break;
    }

    

    

    int ans[p] = {0,};

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ans[brd[i][j]-'1']++;
        }
    }

    for (auto num : ans) cout << num << ' ';
}