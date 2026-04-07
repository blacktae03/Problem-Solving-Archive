#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector<bool> sieve(300000, true);

void SOE() {
    sieve[1] = false;
    for (int i = 2; i * i <= 300000; i++) {
        if (!sieve[i]) continue;
        for (int j = i * i; j <= 300000; j+=i) sieve[j] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    SOE();

    while(true) {
        cin >> n;
        if (!n) break;
        
        for (int i = n+1; i <= 2*n; i++) if (sieve[i]) ans++;
        cout << ans << '\n';
        ans = 0;
    }
}