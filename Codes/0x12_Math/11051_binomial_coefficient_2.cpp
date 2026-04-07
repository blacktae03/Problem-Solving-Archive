#include <bits/stdc++.h>
using namespace std;

int N, K, ans = 1;
int D[1004][1004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    // D[N][K] = D[N-1][K-1] + D[N-1][K] 활용하기
    D[1][0] = 1;
    D[1][1] = 1;

    for (int i = 2; i <= N; i++) {
        D[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            D[i][j] = (D[i-1][j] + D[i-1][j-1]) % 10007;
        }
    }

    cout << D[N][K];
}