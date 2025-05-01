#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int dist[2][500001];
    fill(dist[0], dist[0]+500001, -1);
    fill(dist[1], dist[1]+500001, -1);

    queue<int> Q;
    
    int cur = k;
    for (int i = 0; cur <= 500000; i++) {
        dist[1][cur] = i;
        cur += i+1;
    }

    int dx[3] = {-1, 1};
    int ans = -1;

    if (n == k) ans = 0;
    else {
        Q.push(n);
        dist[0][n] = 0;
    }

    

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 3; dir++) {
            int nx;
            if (dir == 2) nx = cur * dir;
            else nx = cur + dx[dir];

            if (nx < 0 || nx >= 500001) continue;
            if (dist[0][nx] > -1) continue;

            dist[0][nx] = dist[0][cur] + 1;
            Q.push(nx);

            if (dist[1][nx] > -1 && dist[1][nx] - dist[0][nx] >= 0 && (dist[1][nx] - dist[0][nx]) % 2 == 0) {
                ans = dist[1][nx];
                while(!Q.empty()) Q.pop();
                break;
            }
        }
    }

    cout << ans;

}