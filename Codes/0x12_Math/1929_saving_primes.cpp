// Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;

int M, N;
vector<int> primes;

void SOE(int N) {
    vector<bool> sieve(N+1, true); // 11번 생략 가능
    sieve[1] = false;
    // for (int i = 2; i <= N; i++) sieve[i] = true;
    for (int i = 2; i*i <= N; i++) {
        if (!sieve[i]) continue;
        for (int j = i*i; j <= N; j += i) sieve[j] = false;
    }

    // for (int i = 2; i <= N; i++) if(sieve[i]) primes.push_back(i);
    for (int i = M; i <= N; i++) if(sieve[i]) primes.push_back(i); // 막말로 여기서 출력해도 되지만 그래도 구현의 느낌이 나게 출력은 main에서 함.
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;

    SOE(N);

    for (auto i : primes) cout << i << '\n';
}