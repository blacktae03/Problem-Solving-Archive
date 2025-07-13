#include <bits/stdc++.h>
using namespace std;

int D[1000010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    D[0] = 0;
    D[1] = 1;
    

    int n; cin >> n;
    int sign;

    if (n == 0) sign = 0;
    else if (n < 0 && abs(n) % 2 == 0) sign = -1;
    else sign = 1;
    
    n = abs(n);

    for (int i = 2; i <= n; i++) {
        D[i] = D[i-1] % 1'000'000'000 + D[i-2] % 1'000'000'000;
    }

    cout << sign << '\n';
    cout << D[n] % 1'000'000'000;
}
// D[1] = D[0] + D[-1]
// D[-1] = D[1] - D[0]; = 1
// D[0] = D[-1] + D[-2];
// D[-2] = D[0] - D[-1] = -1
// D[-1] = D[-2] + D[-3]
// D[-3] = D[-1] - D[-2] = 2