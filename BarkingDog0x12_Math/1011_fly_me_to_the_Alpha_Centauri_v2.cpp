#include <bits/stdc++.h>
using namespace std;

int N, A, B;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while(N--) {
        cin >> A >> B;

        int dif = B - A;
        int ans = 0;
        int i = 1;

        while (dif > i*2) {
            dif -= i*2;
            ans += 2;
            i++;
        }

        if (!dif) {}
        else if (dif <= i) ans++;
        else ans += 2;

        cout << ans << '\n';
    }


}