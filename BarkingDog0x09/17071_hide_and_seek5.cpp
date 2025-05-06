#include <bits/stdc++.h>
using namespace std;

// 이 코드의 문제점 : 어떤 곳에 n번만에 갔으면 n+2번 때도 갈 수 있다는 것을 인지했으나,
// 그 곳에 n번에도 갈 수 있고, n+1번에도 갈 수 있으면, 동생이 그 곳에 어떤 시간대에 가더라도 발견할 수 있음.
// 하지만 n번에도 갈 수 있고, n+1번에도 갈 수 있을 때, n번만 기록됨. n+3번 때 동생이 그 곳에 가면 만날 수 있으나, 만날 수 없다고 처리됨.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int dist[2][500002];
    fill(dist[0], dist[0]+500002, -1);
    fill(dist[1], dist[1]+500002, -1);

    queue<int> Q;
    
    int cur = k;
    for (int i = 0; cur <= 500001; i++) {
        dist[1][cur] = i;
        cur += i+1;
    }



    int dx[2] = {-1, 1};
    int ans = -1;

    if (n == k) ans = 0;
    else {
        Q.push(n);
        dist[0][n] = 0;
    }

    
    bool found = false;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 3; dir++) {
            int nx;
            if (dir == 2) nx = cur * dir;
            else nx = cur + dx[dir];

            if (nx < 0 || nx >= 500002) continue;
            if (dist[0][nx] > -1) continue;

            dist[0][nx] = dist[0][cur] + 1;
            Q.push(nx);

            // if (nx == 3 && dist[1][nx] > -1 && dist[1][nx] - dist[0][nx] >= 0 && ((dist[1][nx] - dist[0][nx]) % 2 == 0 || (dist[1][nx] - dist[0][nx]) % 3 == 0)) {
            //     ans = dist[1][nx];
            //     while(!Q.empty()) Q.pop();
            //     break;
            // }

            if (dist[1][nx] > -1 && dist[1][nx] >= dist[0][nx] && (dist[1][nx] - dist[0][nx]) % 2 == 0) {
                ans = dist[1][nx];
                found = true;
                break;
            }
        }

        if (found) break;
    }

    cout << ans;

}