#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    int mx = 200001;
    int dist[mx];
    fill(dist, dist+mx, -1);

    queue<int> Q;
    
    Q.push(N);
    dist[N] = 0;

    int dx[2] = {-1, 1};

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();

        int nx = cur*2;

        if(nx >= 0 && nx < mx) {
            if (dist[nx] < 0) {
                Q.push(nx);
                dist[nx] = dist[cur];
            }
        }

        for (int dir = 0; dir < 2; dir++) {
            int nx = cur + dx[dir];

            if (nx < 0 || nx >= mx) continue;
            if (dist[nx] > -1) continue;

            dist[nx] = dist[cur] + 1;

            Q.push(nx);

        }

        
    }
    
    cout << dist[K];

}