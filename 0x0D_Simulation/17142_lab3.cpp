#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M, cnt, ans = -1;
int brd[51][51], dist[51][51];
vector<pair<int, int>> V;
queue<pair<int, int>> Q;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool comb[11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    fill(comb, comb+11, 1);
    fill(comb, comb+M, 0);

    for (int i = 0; i < N; i++) {
        fill(dist[i], dist[i]+51, -1);
        for (int j = 0; j < N; j++) {
            cin >> brd[i][j];
            if (brd[i][j] == 2) V.push_back({i, j});
            if (!brd[i][j]) cnt++;
        }
    }
    
    int tmp = cnt;
    int res = 0;

    do {

        if (!tmp) {
            if (ans == -1) ans = res;
            else ans = min(ans, res);
        } // 이거 다시 아래로 내려야할 수도
        
        tmp = cnt;
        res = 0;
        bool esc = 0;
        
        for (int idx = 0; idx < V.size(); idx++) {
            if (!comb[idx]) {
                Q.push(V[idx]);
                dist[V[idx].X][V[idx].Y] = 0;
            }
        }
        
        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (dist[nx][ny] > -1 || brd[nx][ny] == 1) continue;
                
                Q.push({nx, ny});
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                res = max(res, dist[nx][ny]);
                
                if (!brd[nx][ny]) tmp--;
                if (!tmp) esc = 1;
            }
            
            if (esc) break;
        }
        
        for (int i = 0; i < N; i++) fill(dist[i], dist[i]+51, -1);
        while(!Q.empty()) Q.pop();
        
    } while(next_permutation(comb, comb+V.size()));
    
    if (!tmp) {
        if (ans == -1) ans = res;
        else ans = min(ans, res);
    }
    
    cout << ans;
}