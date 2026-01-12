#include <bits/stdc++.h>
using namespace std;

int N, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int t = 0; t < N; t++) {
        int tmp; cin >> tmp;
        if (tmp == 1) ans++;

        for (int i = 2; i * i <= tmp; i++) {
            if (tmp % i) continue;
            ans++;
            break;
        }
    }

    cout << N-ans;
}
// 합성수를 더해버려 그냥