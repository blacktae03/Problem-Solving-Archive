#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;

    while (true) {
        cin >> a >> b;
        if (!a && !b) break;

        if (a > b) cout << "Yes\n";
        else cout << "No\n";
    }
}