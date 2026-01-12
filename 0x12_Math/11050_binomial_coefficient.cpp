#include <bits/stdc++.h>
using namespace std;

int N, K, ans = 1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 0; i < K; i++) ans *= N-i;
    for (int i = 1; i <= K; i++) ans /= i;

    cout << ans;
}