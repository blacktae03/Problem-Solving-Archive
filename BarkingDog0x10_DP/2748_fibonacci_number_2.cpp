#include <bits/stdc++.h>
using namespace std;

long long D[100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    D[0] = 0;
    D[1] = 1;
    int n; cin >> n;

    for (int i = 2; i <= n; i++) D[i] = D[i-1] + D[i-2];

    cout << D[n];
}