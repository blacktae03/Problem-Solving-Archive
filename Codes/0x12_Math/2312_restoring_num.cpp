#include <bits/stdc++.h>
using namespace std;

int N, T;
vector<bool> sieve(100001, true);
int fac[100010];
const int L = 100000;

void SOE() {
    sieve[1] = false;

    for (int i = 2; i*i <= L; i++) {
        if (!sieve[i]) continue;
        for (int j = i*i; j <= L; j += i) {
            sieve[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    SOE();

    while(T--) {
        cin >> N;
        int tmp = N;

        for (int i = 2; i <= N; i++) {
            if (!sieve[i]) continue;
            while (!(N % i)) {
                fac[i]++;
                N /= i;
            }
        }

        for (int i = 2; i <= tmp; i++) {
            if (!fac[i]) continue;
            cout << i << ' ' << fac[i] << '\n';
        }
        
        fill(fac, fac+100010, 0);
    }
}