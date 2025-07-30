#include <bits/stdc++.h>
using namespace std;

int N, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while(N) {
        if (!(N % 5)) {
            N -= 5;
            ans++;
        }

        else {
            N -= 3;
            ans++;
        }

        if (N < 0) {
            cout << -1;
            return 0;
        }
    }

    cout << ans;
}