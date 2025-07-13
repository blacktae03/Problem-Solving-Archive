#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int N, T;
int G[100004][5], D[100004][5];
int dx[4] = {0,1,1,1};
int dy[4] = {1,-1,0,1};
queue<pair<int, int>> Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        cin >> N;
        if (N == 0) return 0;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= 3; j++) {
                cin >> G[i][j];
                D[i][j] = 1'000'000'001; // 음수인 경우도 있어서 0으로 초기화 하면 안됨.
            }
        }

        D[1][2] = G[1][2];
        Q.push({1, 2});

        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 1 || nx > N || ny < 1 || ny > 3) continue;

                if (D[nx][ny] > D[cur.X][cur.Y] + G[nx][ny]) { // 음수인 경우도 있어서 
                    D[nx][ny] = D[cur.X][cur.Y] + G[nx][ny];
                    Q.push({nx, ny});
                }
            }
        }

        cout << ++T << ". " << D[N][2] << '\n';
    }
}