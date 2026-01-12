#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int tmp = N;
    // if (tmp == 2 || tmp == 3) cout << tmp << '\n';

    for (int i = 2; true; i++) {
        while (!(N % i)) {
            cout << i << '\n';
            N /= i;
        }
        
        if (N == 1) break;

        if (i * i > N) {
            cout << N << '\n';
            break;
        }
    }
}