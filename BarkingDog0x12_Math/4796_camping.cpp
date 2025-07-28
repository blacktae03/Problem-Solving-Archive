#include <bits/stdc++.h>
using namespace std;

int L, P, V, ans, i;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        cin >> L >> P >> V;
        if (!L) break;

        ans += V/P * L;
        ans += V%P > L ? L : V%P;

        cout << "Case " << ++i << ": " << ans << '\n';
        ans = 0;
    }
}