#include <bits/stdc++.h>
using namespace std;

int N, A, B, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> A >> B;

    while(abs(A-B) > 1 || (A+1)/2 != (B+1)/2) {
        A = (A+1) / 2;
        B = (B+1) / 2;
        ans++;
    }

    cout << ans+1;
}