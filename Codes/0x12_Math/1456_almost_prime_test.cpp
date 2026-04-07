#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a = 10000000;
    long long b = a;
    b *= a;
    cout << b << '\n';
    b *= a;
    cout << b << '\n';

    vector<int> V(11, 1);
    cout << V[11] << '\n';
    cout << V[10];
}