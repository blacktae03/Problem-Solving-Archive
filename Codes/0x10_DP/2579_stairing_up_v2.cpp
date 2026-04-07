#include <bits/stdc++.h>
using namespace std;

int N, sum;
int D[302], S[302];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {cin >> S[i]; sum += S[i];}

    D[1] = S[1], D[2] = S[2], D[3] = S[3];

    for (int i = 4; i <= N; i++) D[i] = min(D[i-3], D[i-2]) + S[i];

    int ans = min(D[N-1], D[N-2]);

    cout << sum - ans;
}
// D[i] = i번째 계단을 밟기 전에 밟지 않은 계단의 합의 최솟값 (i 번째 계단은 무조건 안밟는다고 가정)
// S[1:7] = {10, 20, 15, 25, 10, 20} 이라고 가정하고 생각해보자.
// D[1] = 10, D[2] = 20, D[3] = 15
// D[4] = (10(1), 20(2)) + 25 = 35, D[5] = (20(2) + 15(3)) + 10, D[6] = (25(1,3) or 15(3) or 35(1,4) or 45(2,4)) + 20 = 35