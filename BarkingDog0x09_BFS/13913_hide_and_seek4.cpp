#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    queue<int> Q;
    stack<int> S;

    int brd[200001];
    fill(brd, brd+200001, -1);

    Q.push(N);
    brd[N] = 0;
    
    int dx[2] = {1, -1};

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 3; dir++) {
            int nx;
            if (dir == 2) nx = cur * dir;
            else nx = cur + dx[dir];

            if (nx < 0 || nx >= 200001) continue;
            if (brd[nx] > -1) continue;

            Q.push(nx);
            brd[nx] = brd[cur] + 1;

            // if (nx == K) {
            //     S.push(nx);
            //     while(!Q.empty()) Q.pop();
            //     break;
            // }
        }
    }

    S.push(K);

    int dist = brd[S.top()];

    cout << dist << '\n';
    

    while(dist != 0) {
        int cur = S.top();

        for (int dir = 0; dir < 3; dir++) {
            int nx;

            if (dir == 2 && cur % 2 == 0) nx = cur / dir;
            else nx = cur + dx[dir];

            if (nx < 0 || nx >= 200001) continue;
            if (brd[nx] == brd[cur]-1) {
                dist = brd[nx];
                S.push(nx);
                break;
            }
        }
    }

    while (!S.empty()) {
        cout << S.top() << ' ';
        S.pop();
    }
}