#include <bits/stdc++.h>
using namespace std;

int T, N;
long long D[1000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    D[1] = 1;
    D[2] = D[1] + 1;
    D[3] = D[2] + D[1] + 1;

    for (int i = 4; i <= 1000000; i++) {
        D[i] = (D[i-1] % 1'000'000'009 + D[i-2] % 1'000'000'009 + D[i-3] % 1'000'000'009) % 1'000'000'009;
    }

    cin >> T;

    while(T--) {
        cin >> N;
        cout << D[N] << '\n';
    }
}
// 풀었지만 sol 참고할 것