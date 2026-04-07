#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p, q, n;
unordered_map<ll, ll> um;

ll solve(ll n) {
    // if (n == 0) return 1;
    if (um.find(n) != um.end()) return um[n];
    um[n] = solve(n/p) + solve(n/q);
    return um[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    um[0] = 1;
    cin >> n >> p >> q;
    cout << solve(n);
}
// 해설 참고 헀는데 unordered_map 사용함.