#include <bits/stdc++.h>
using namespace std;

int A, B, C;
int ans = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B >> C;

    for (int i = 0; i < B; i++) {
        ans *= A % C;
        ans %= C;
    }

    cout << ans;
}