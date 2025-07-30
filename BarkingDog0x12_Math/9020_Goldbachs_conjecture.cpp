#include <bits/stdc++.h>
using namespace std;

int T, N;
vector<bool> sieve(1000001, true);
const int L = 1000000;

void SOE() {
    sieve[1] = false;

    for (int i = 2; i*i <= L; i++) {
        if (!sieve[i]) continue;
        for (int j = i*i; j <= L; j+=i) {
            sieve[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    SOE();

    cin >> T;

    while(T--) {
        cin >> N;
        int i1, i2;

        for (int i = 2; i <= N/2; i++) {
            if (!sieve[i] || !sieve[N-i]) continue;
            i1 = i;
            i2 = N-i;
        }

        cout << i1 << ' ' << i2 << '\n';
    }
}