#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

string brd[12];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool vis[12][6];
bool bomb;
int cnt, ans;
queue<pair<int, int>> Q;
queue<char> Q2;
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 12; i++) cin >> brd[i];
    
    while(true) {
        bomb = false;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (brd[i][j] == '.' || vis[i][j]) continue;
    
                Q.push({i, j});
                vis[i][j] = 1;
                v.push_back({i, j});
    
                while(!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
    
                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
    
                        if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
                        if (vis[nx][ny] || brd[i][j] != brd[nx][ny]) continue;
    
                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                        v.push_back({nx, ny});
                    }
                }
    
                if (v.size() >= 4) {
                    bomb = true;
                    for (auto p : v) brd[p.X][p.Y] = '.';
                }
    
                v.clear();
            }
        } // 4개 넘는 뿌요들 다 X로 바꾸기 작업.

        if (!bomb) break;

        ans++;
        
        for (int i = 0; i < 6; i++) {
            for (int j = 11; j >= 0; j--) {
                if (brd[j][i] == '.') continue;
                Q2.push(brd[j][i]);
                brd[j][i] = '.';
            }

            for (int j = 11; j >= 0; j--) {
                if (Q2.empty()) break;
                brd[j][i] = Q2.front(); Q2.pop();
            }
        } // X로 한 거 다 밑으로 내리기 작업. X를 2048에서 0이라고 생각하고 다 밀기만 하면 될 듯. 2048의 down이랑 비슷하지만 더 간단함.

        for (int i = 0; i < 12; i++) fill(vis[i], vis[i]+6, 0); // vis 0으로 초기화
    }

    cout << ans;
}