#include <bits/stdc++.h>
using namespace std;

int n, s, cnt;
int num[20];

void fsum(int sum, int k, int l) {
    if (k != 0 && sum == s) cnt++;
    if (k == n+1) return;

    for (int m = l; m < n; m++) fsum(sum + num[m], k+1, m+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    fsum(0, 0, 0);
    cout << cnt;
}