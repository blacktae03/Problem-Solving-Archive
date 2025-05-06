#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

bool vis[2][500001];

// 최솟값을 처리하는 코드.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int dist[2][500001];
    fill(dist[0], dist[0]+500001, -1);
    fill(dist[1], dist[1]+500001, -1);

    queue<pair<int, int>> Q;
    
    int cur = k;
    for (int i = 0; cur <= 500000; i++) {
        dist[i % 2][cur] = i;
        cur += i+1;
    } // 1

    int dx[2] = {-1, 1};
    int ans = -1;

    if (n == k) ans = 0;
    else {
        Q.push({0, n});
        vis[0][n] = 1;
        if (dist[0][n] >= 0) { // 수빈이가 처음 위치한 곳에서도 짝수 번째에서 만날 수 있으니 이 처리를 해야한다는 단점이 있음.
            ans = dist[0][n];
        }
    }

    while(!Q.empty()) { // 2
        auto cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 3; dir++) {
            int nx, time;
            if (dir == 2) nx = cur.Y * dir;
            else nx = cur.Y + dx[dir];
            time = cur.X + 1;

            if (nx < 0 || nx > 500000) continue;
            if (vis[time % 2][nx]) continue;
            if (dist[time % 2][nx] >= time) { // 그대신 조건문 간소화됨.
                if (ans == -1) ans = dist[time % 2][nx];
                else ans = min(ans, dist[time % 2][nx]);
            }
            
            vis[time % 2][nx] = 1;
            Q.push({time, nx});
        }
    }

    cout << ans;

}