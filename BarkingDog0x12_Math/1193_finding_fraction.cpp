#include <bits/stdc++.h>
using namespace std;

int X, i, j;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> X;

    for (i = 2; true; i++) {
        if (i % 2) {
            for (j = 1; j < i; j++) {
                if (!--X) break;
            }
        }
        else {
            for (j = i-1; j >= 1; j--) {
                if (!--X) break;
            }
        }
        if (!X) break;
    };

    cout << j << '/' << i-j << '\n';
}