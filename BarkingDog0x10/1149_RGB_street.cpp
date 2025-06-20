#include <bits/stdc++.h>
using namespace std;

int N;
int cost[1002][3], D[1002][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cost[i][j];
            D[i][j] = 10000000;
        }
    }

    D[1][0] = cost[1][0];
    D[1][1] = cost[1][1];
    D[1][2] = cost[1][2];

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (k == j) continue;
                D[i][k] = min(D[i][k], D[i-1][j] + cost[i][k]);
            }
        }
    }

    // int ans = 10000000;
    // for (int i = 0; i < 3; i++) ans = min(ans, D[N][i]); 이건 너무 초짜 방법인데 ㅋㅋ;
    cout << *min_element(D[N], D[N]+3);
    // cout << min({D[N][0], D[N][1], D[N][2]});

    // cout << ans;
}
// D[i][0:3] : i(i>=2)번째 집을 칠 했을 때 최솟값, 0:3 : 마지막 집의 색