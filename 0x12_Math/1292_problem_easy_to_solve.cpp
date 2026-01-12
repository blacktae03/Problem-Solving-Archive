#include <bits/stdc++.h>
using namespace std;

int A, B, ans, idx;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;

    for (int i = 1; i <= 1000; i++) {
        for (int j = 0; j < i; j++) {
            idx++;
            if (idx < A) continue;
            if (idx > B) break;
            ans += i;
        }
        if (idx > B) break;
    }

    cout << ans;
}