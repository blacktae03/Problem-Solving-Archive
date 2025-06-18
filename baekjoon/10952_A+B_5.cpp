#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;

    cin >> a >> b;

    while(a || b) {
        cout << a+b << '\n';
        cin >> a >> b;
    }
}