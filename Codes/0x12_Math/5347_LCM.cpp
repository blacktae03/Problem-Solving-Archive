#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T, A, B;

ll GCD(ll a, ll b) {
    if (a == 0) return b;
    return GCD(b % a, a);
}

ll LCM(ll a, ll b) {
    return a / GCD(a, b) * b;
    // a * b = GCD(a, b) * LCM(a, b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--) {
        cin >> A >> B;
        cout << LCM(A, B) << '\n';
    }
}
// long long 쓰는 이유 : GCD에서 100만, 100만 끼리 비교하면 int 범위 넘음.