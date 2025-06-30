#include <bits/stdc++.h>
using namespace std;

int N, K;
int V[105], W[105];
int D[105][2], cur[105][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> W[i] >> V[i];
    }

    // D[1][0] = 0;
    // cur[1][0] = 0;
    // if (W[1] <= K) {
    //     D[1][1] = V[1];
    //     cur[1][1] = W[1];
    // }

    for (int i = 1; i <= N; i++) {
        if (D[i-1][0] > D[i-1][1]) {
            D[i][0] = D[i-1][0];
            cur[i][0] = cur[i-1][0];
        }
        else if (D[i-1][0] < D[i-1][1]) {
            D[i][0] = D[i-1][1];
            cur[i][0] = cur[i-1][1];
        }

        else {
            D[i][0] = D[i-1][0];
            if (cur[i-1][0] < cur[i-1][1]) cur[i][0] = cur[i-1][0];
            else cur[i][0] = cur[i-1][1];
        }

        D[i][1] = V[i];
        cur[i][1] = W[i];

        if (cur[i-1][0] + W[i] <= K) {
            if (D[i-1][0] + V[i] > D[i][1]) {
                D[i][1] = D[i-1][0] + V[i];
                cur[i][1] = cur[i-1][0] + W[i];
            }
        }

        if (cur[i-1][1] + W[i] <= K) {
            if (D[i-1][1] + V[i] > D[i][1]) {
                D[i][1] = D[i-1][1] + V[i];
                cur[i][1] = cur[i-1][1] + W[i];
            }
        }
    }

    cout << "D : ";
    for (int i = 1; i <= N; i++) {
        cout << D[i][0] << ' ' << D[i][1] << " | ";
    }
    cout << "\ncur : ";
    for (int i = 1; i <= N; i++) {
        cout << cur[i][0] << ' ' << cur[i][1] << " | ";
    }
    cout << '\n';

    cout << max(D[N][0], D[N][1]);
}
// D[i][0or1] = i번째 아이템까지만 봤을 때, i번째 아이템을 포함한(1) 또는 포함하지 않은(0) 가치 합의 최댓값
// cur[i][0or1] = 그때의 배낭 내 총 무게