#include <bits/stdc++.h>
using namespace std;

int n, s, cnt;
int num[20];
bool isused[20];

void fsum(int sum, int k) {
    if (!k && sum == s) {
        cnt++;
        return;
    }

    for (int m = 0; m < n; m++) {
        if (isused[m]) continue;
        isused[m] = 1;
        fsum(sum + num[m], k+1);
        isused[m] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    fsum(0, 0);
    cout << cnt;
}