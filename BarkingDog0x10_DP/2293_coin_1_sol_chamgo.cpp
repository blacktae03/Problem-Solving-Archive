#include <bits/stdc++.h>
using namespace std;

int n, k;
int C[105], D[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> C[i];

    D[0] = 1;

    for (auto coin : C) {
        if (!coin) break;
        for (int i = coin; i <= k; i++) {
            D[i] += D[i-coin];
        }
    }

    cout << D[k];
}
// 3 10
// 1
// 2
// 5
// 일 때
// C = {1, 2, 5, 0,}
// i = 0일 때
// d[1] += d[0];
// d[2] += d[1];
// d[3] += d[2];
// ...
// d[10] += d[9];

// i = 1일 때
// d[2] += d[0];
// d[3] += d[1];
// d[4] += d[2];
// ...
// d[10] += d[8];

// d[i] = i원을 만드는 경우의 수
// 1원 짜리 동전은 1원부터 k원까지 만들 수 있음
// 2원 짜리 동전은 2원부터 (k원까지) 만들 수 있음
// 5원 짜리 동전은 5원부터 만들 수 있음.
// i원짜리 동전을 j원짜리 동전 묶음에 추가하면 i+j원을 만들 수 있음
// (j >= 0)이고 아무것도 없는 동전 묶음도 0원짜리 묶음이므로 d[0] = 1;