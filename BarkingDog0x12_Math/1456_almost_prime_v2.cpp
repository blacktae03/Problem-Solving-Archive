#include <bits/stdc++.h>
using namespace std;

long long A, B, ans;
vector<int> sieve(10000010, true); // 10Mb
const int L = 10000000;

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

    cin >> A >> B;
    
    for (long long i = 2; i*i <= B; i++) {
        if (!sieve[i]) continue;
        for (long long j = i*i; j <= B; j *= i) {
            if (j < A) continue;
            ans++;
        }
    }

    cout << ans;
    // cout << "sieve[10000000] = " << sieve[10000000] << '\n';
}