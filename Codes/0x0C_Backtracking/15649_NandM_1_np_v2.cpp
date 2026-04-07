#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int brd[n];
    int temp[n];

    for (int i = 0; i < n; i++) {
        brd[i] = i+1;
        temp[i] = i+1;
    }
    
    for (int i = m; i < n; i++)
        brd[i] = 10;

    do { // 나머지 n-m개가 같은 걸로 처리 되어야 하는데...
        for (int i = 0; i < n; i++) {
            if (brd[i] == 10) continue;
            cout << temp[i] << ' ';
        }

        cout << '\n';
    } while (next_permutation(brd, brd+n));
}