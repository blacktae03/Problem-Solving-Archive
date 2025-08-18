#include <bits/stdc++.h>
using namespace std;

int N, ans;
vector<bool> sieve(4000001, true);

vector<int> SOE() {
    vector<int> tmp;
    sieve[1] = false;
    
    for (int i = 2; i*i <= 4000000; i++) {
        if (!sieve[i]) continue;
        for (int j = i*i; j <= 4000000; j += i) {
            sieve[j] = false;
        }
    }

    for (int i = 2; i <= 4000000; i++) if (sieve[i]) tmp.push_back(i);

    return tmp;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    vector<int> primes = SOE();

    int st = 0, en = 0;
    int sum = 0;

    while (en < primes.size() || sum >= N) {
        if (sum >= N) {
            if (sum == N) ans++;
            sum -= primes[st++];
        }
        else sum += primes[en++];
    }

    cout << ans;
}