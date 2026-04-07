#include <bits/stdc++.h>
using namespace std;

int T, N, ans;
bool P[104];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while (T--) {
        cin >> N;

        for (int i = 1; i <= N; i++) {
            for (int j = i; j <= N; j += i) {
                P[j] = !P[j];
            }
        }

        for (int i = 1; i <= N; i++) ans += P[i];
        cout << ans << '\n';
        ans = 0;
        fill(P, P+104, 0);
    }
}