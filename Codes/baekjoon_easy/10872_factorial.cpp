#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    long long ans = 1;
    for (int i = N; i >= 1; i--) ans *= i;

    cout << ans;
}