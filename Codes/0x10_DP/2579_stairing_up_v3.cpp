#include <bits/stdc++.h>
using namespace std;

int S[302], D[302];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;

    for (int i = 1; i <= N; i++) cin >> S[i];
    
    D[1] = S[1];
    if (N == 1) {cout << D[1]; return 0;}
    D[2] = S[1] + S[2];
    if (N == 2) {cout << D[2]; return 0;}
    D[3] = max(S[1], S[2]) + S[3];

    for (int i = 4; i <= N; i++) {
        D[i] = max(D[i-3] + S[i-1], D[i-2]) + S[i];
    }

    cout << D[N];
    
}
// D[n] = n번째 계단까지 올라섰을 때 점수의 합의 최댓값 n번째 계단은 무조건 밟는다고 가정.