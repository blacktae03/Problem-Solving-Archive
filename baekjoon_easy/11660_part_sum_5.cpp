#include <bits/stdc++.h>
using namespace std;

int N, M;
int brd[1030][1030], D[1030][1030];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int tmp = 0;
        for (int j = 1; j <= N; j++) {
            cin >> brd[i][j];
            tmp += brd[i][j];
            D[i][j] = D[i-1][j] + tmp;
        }
    }

    for (int i = 0; i < M; i++) {
        int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;

        cout << D[ex][ey] + D[sx-1][sy-1] - D[ex][sy-1] - D[sx-1][ey] << '\n';
    }
}
// 4 3
// 1 2 3 4
// 2 3 4 5
// 3 4 5 6
// 4 5 6 7
// 2 2 3 4
// 3 4 3 4
// 1 1 4 4