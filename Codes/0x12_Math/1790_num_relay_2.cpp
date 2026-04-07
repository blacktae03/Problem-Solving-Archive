#include <bits/stdc++.h>
using namespace std;

int N, K, idx = 9, L, cnt, ans = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    while(true) {
        if (N < 0) break;
        L += N;
        N -= idx;
        idx *= 10;
    }
    // cout << "L == " << L << '\n';

    if (K > L) {
        cout << -1;
        return 0;
    }

    idx = 9;

    while(true) {
        cnt++;

        if (K <= idx * cnt) {
            for (int i = 1; i < cnt; i++) ans *= 10;
            ans--;
            // cout << "beforehand ans == " << ans << '\n';
            ans += (K+cnt-1) / cnt; // K == 10 일 때 10이 되어야 함.
            // cout << "1st ans == " << ans << '\n';
            int tmp = K % cnt ? cnt - K % cnt : K % cnt;
            while (tmp--) ans /= 10;
            ans %= 10;
            break;
        }

        K -= idx * cnt;
        idx *= 10;
    }

    cout << ans;
}