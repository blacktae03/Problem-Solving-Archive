#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int M, N, ans = -1;
int brd[51][51], dist[51][51];
vector<pair<int, int>> V;
bool comb[11];
queue<pair<int, int>> Q;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    fill(comb, comb+11, 1);
    fill(comb, comb+M, 0);
    
    for (int i = 0; i < N; i++) fill(dist[i], dist[i]+51, -1);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> brd[i][j];
            if (brd[i][j] == 2) V.push_back({i, j});
        }
    }
    
    do {
        int rec = 0;
        bool notall = 0;
        
        for (int i = 0; i < V.size(); i++) {
            if (comb[i]) continue;
            Q.push(V[i]);
            dist[V[i].X][V[i].Y] = 0;
        }
        
        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (brd[nx][ny] == 1) continue;
                if (dist[nx][ny] > -1) continue;
                
                Q.push({nx, ny});
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                
                rec = max(rec, dist[nx][ny]);
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (brd[i][j] != 1 && dist[i][j] == -1) notall = 1;
            }
        }

        if (!notall) {
            if (ans == -1) ans = rec;
            else ans = min(ans, rec);
        }
        
        for (int i = 0; i < N; i++) fill(dist[i], dist[i]+51, -1);

    } while(next_permutation(comb, comb+V.size()));

    cout << ans;
}