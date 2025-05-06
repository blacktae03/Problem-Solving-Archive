#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

// 1과 2의 순서를 바꾼 경우.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int dist[2][500001];
    fill(dist[0], dist[0]+500001, -1);
    fill(dist[1], dist[1]+500001, -1);

    queue<pair<int, int>> Q;
    
    

    int dx[2] = {-1, 1};
    int ans = -1;

    if (n == k) ans = 0;
    else {
        Q.push({0, n});
        dist[0][n] = 0;
    }

    bool found = false;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 3; dir++) {
            int nx, time;
            if (dir == 2) nx = cur.Y * dir;
            else nx = cur.Y + dx[dir];
            time = cur.X + 1;

            if (nx < 0 || nx > 500000) continue;
            if (dist[time % 2][nx] > -1) continue;
        
            dist[(cur.X+1) % 2][nx] = cur.X + 1;
            Q.push({time, nx});
        }

        if (found) break;
    }

    int cur = k;
    for (int i = 0; cur <= 500000; i++) {
        if (dist[i%2][cur] <= i) {
            ans = i;
            break;
        }
        cur += i+1;
    }

    cout << ans;

}