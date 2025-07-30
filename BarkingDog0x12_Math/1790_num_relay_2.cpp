#include <bits/stdc++.h>
using namespace std;

int N, K, idx = 9, L, cnt, ans;

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
    cout << "L == " << L << '\n';

    if (K > L) {
        cout << -1;
        return 0;
    }

    idx = 9;

    while(true) {
        cnt++;

        if (K < idx) {
            ans = idx/10 + (K+cnt-1) / cnt; // K == 10 일 때 10이 되어야 함.
            cout << "1st ans == " << ans << '\n';
            int tmp = K % cnt ? cnt - K % cnt : K % cnt;
            while (tmp--) ans /= 10;
            ans %= 10;
            break;
        }

        K -= idx;
        idx *= 10;
    }

    cout << ans;
}