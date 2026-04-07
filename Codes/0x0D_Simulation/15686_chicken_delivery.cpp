#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, M, cnt, rtmp, ctmp, ans, chicken_dist;
int brd[52][52], dist[52][52];
bool chicken[15];
vector<pair<int, int>> loc1, loc2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    fill(chicken+M, chicken+15, 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> brd[i][j];
            if (!brd[i][j]) continue;
            else if (brd[i][j] == 1) {
                loc1.push_back({i, j});
            }
            else {
                loc2.push_back({i, j});
                cnt++;
            }
        }
        fill(dist[i], dist[i]+N, 200);
    }

    do {
        chicken_dist = 0;

        for (int i = 0; i < cnt; i++) {
            if (chicken[i]) continue;
            for (auto p : loc1) {
                rtmp = max(p.X - loc2[i].X, loc2[i].X - p.X); // abs(p.X - loc2[i].X) same
                ctmp = max(p.Y - loc2[i].Y, loc2[i].Y - p.Y); // abs(p.Y - loc2[i].Y) same
                dist[p.X][p.Y] = min(dist[p.X][p.Y], rtmp + ctmp);
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                chicken_dist += (dist[i][j] == 200) ? 0 : dist[i][j];
            }
        }
        
        if (!ans) ans = chicken_dist;
        else ans = min(ans, chicken_dist);
        
        for (int i = 0; i < N; i++) fill(dist[i], dist[i] + N, 200);
        
    } while (next_permutation(chicken, chicken+cnt));

    cout << ans;
}