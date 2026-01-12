#include <bits/stdc++.h>
using namespace std;

long long A, B, ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;
    
    for (long long i = A; i*i <= B; i++) {
        long long j;
        for (j = 2; j*j <= A; j++) {
            if (A % j == 0) break;
        }
        if (j*j > A) continue; // j

        for (j = i*i; j <= B; j *= i) ans++;
    }

    cout << ans;
}