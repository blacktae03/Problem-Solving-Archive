#include <bits/stdc++.h>
using namespace std;

int n, m;
long long C[1004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> C[i];

    for (int i = 0; i < m; i++) {
        sort(C, C+n);
        C[0] = C[1] = C[0] + C[1];
    }

    cout << accumulate(C, C+n, 0ll);
}
// 역시 자료형을 잘 생각해야 돼.