#include <bits/stdc++.h>
using namespace std;

int N, K;
int W[104], V[104];
int D[104][4], T[104][4];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) cin >> W[i] >> V[i];

    if (W[1] <= K) {
        D[1][1] = V[1];
        T[1][1] = W[1];
    }

    for (int i = 2; i <= N; i++) {
        if (D[i-1][0] > D[i-1][1]) {
            D[i][0] = D[i-1][0];
            T[i][0] = T[i-1][0];
        }
        else if (D[i-1][0] == D[i-1][1]) {
            D[i][0] = D[i-1][0];
            T[i][0] = min(T[i-1][0], T[i-1][1]);
        }
        else {
            D[i][0] = D[i-1][1];
            T[i][0] = T[i-1][1];
        }

        if (W[i] > K) continue;

        D[i][1] = V[i];
        T[i][1] = W[i];

        if (T[i-1][0] + W[i] <= K) {
            if (D[i-1][0] + V[i] >= D[i][1]) {
                if (D[i][1] == D[i-1][0] + V[i]) T[i][1] = min(T[i][1], T[i-1][0]+W[i]); 
                else T[i][1] = T[i-1][0] + W[i];
                D[i][1] = D[i-1][0] + V[i];
            }
        }

        if (T[i-1][1] + W[i] <= K) {
            if (D[i-1][1] + V[i] >= D[i][1]) {
                if (D[i][1] == D[i-1][1] + V[i]) T[i][1] = min(T[i][1], T[i-1][1]+W[i]);
                else T[i][1] = T[i-1][1] + W[i];
                D[i][1] = D[i-1][1] + V[i];
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << T[i][0] << ' ' << D[i][0] << " | " << T[i][1] << ' ' << D[i][1] << '\n';
    }

    cout << max(D[N][0], D[N][1]);
}
// 그냥 1차원적으로 생각해보자.
// D[i][0or1] = i번째 물건을 포함한(1) 또는 포함하지 않은(0) 가치합의 최댓값일 때의 배낭의 {무게, 가치합}