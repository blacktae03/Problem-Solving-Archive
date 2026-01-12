#include <bits/stdc++.h>
using namespace std;

int M, N, T, x, y, lmt, ans;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while(T--) {
        cin >> M >> N >> x >> y;
        lmt = M > N ? lcm(M, N) : lcm(N, M);
        y %= N;

        for (ans = x; ans <= lmt; ans += M) {
            if (ans % N != y) continue;
            break;
        }

        if (ans > lmt) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}