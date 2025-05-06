#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

bool vis[2][500001];

// 이 코드의 문제점 : 수빈이가 어떤 칸에 n번 때도 갈 수 있고, n+1번 때도 갈 수 있으면, 동생이 어느 때도 갈 수 있다는 것을 처리하기 위해서
// 홀수, 짝수마다 dist의 인덱스를 따로 만들고, n번 때와 n+1번 때의 거리를 둘 다 기록할 수 있게 처리함.
// 그러나, 코드 2에서 코드 1의 값을 발견할 시, 항상 최단거리라고 보장할 수 없음.
// 그 이유는, 수빈이가 빠른 시간에 간다고 해서, 동생이 빠른 시간에 간다는 것은 아니기 때문.
// 수빈이는 2번 만에 가는 곳이어도, 동생은 8번만에 와서 만날 수도 있는 거고,
// 수빈이가 5번 만에 가는 곳이어도, 동생이 5번만에 와서 만날 수도 있는 것임.
// 수빈이가 11에서 시작, 동생이 8에서 시작할 때, 14에서 3번만에 만나고, 수빈이가 2번만 움직이면 44에 갈 수 있는데, 44에서 동생은 8번만에 도착하므로,
// 이 코드대로 하면 8이 나올 것임.
// 따라서 1과 2의 순서를 바꾸거나, break를 하지말고, 최솟값을 처리해야함.

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
        dist[0][n] = 0;
        vis[0][n] = 1;
    }

    bool found = false;
    while(!Q.empty()) { // 2
        auto cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 3; dir++) {
            int nx, time;
            if (dir == 2) nx = cur.Y * dir;
            else nx = cur.Y + dx[dir];
            time = cur.X + 1;

            if (nx < 0 || nx > 500000) continue;
            if (vis[time % 2][nx]) continue;
            if (dist[time % 2][nx] > -1 && dist[time % 2][nx] >= time) {
                ans = dist[time % 2][nx];
                found = true;
                break;
            }
            vis[time % 2][nx] = 1;
            // dist[(cur.X+1) % 2][nx] = cur.X + 1;
            Q.push({time, nx});

            // if (dist[1][nx] > -1 && dist[1][nx] >= dist[0][nx] && (dist[1][nx] - dist[0][nx]) % 2 == 0) {
            //     ans = dist[1][nx];
            //     found = true;
            //     break;
            // }
        }

        if (found) break;
    }

    cout << ans;

}