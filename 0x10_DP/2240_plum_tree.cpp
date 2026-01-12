// 와 이걸 이렇게 빨리 푼다고 개소름이네 진짜 나 좀 친다 ㅋㅋ
#include <bits/stdc++.h>
using namespace std;

int T, W;
bool F[1004][4];
int D[40][1004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T >> W;

    for (int i = 1; i <= T; i++) {
        int tmp; cin >> tmp;
        F[i][tmp] = 1;
    }
    D[0][1] = F[1][1];
    D[1][1] = F[1][2];

    for (int i = 2; i <= T; i++) {
        for (int j = 0; j <= W; j++) {
            if (j > i) continue;
            if (j == 0) D[j][i] = D[j][i-1] + F[i][j%2+1];
            else D[j][i] = max(D[j][i-1], D[j-1][i-1]) + F[i][j%2+1];
        }
    }

    int ans = 0;
    for (int i = 0; i <= W; i++) {
        ans = max(ans, D[i][T]);
    }

    cout << ans;
}
// D[i][j] = i번 이동해서 j초 후에 얻은 자두의 개수의 최댓값