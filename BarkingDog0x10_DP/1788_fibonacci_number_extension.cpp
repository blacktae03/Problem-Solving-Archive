#include <bits/stdc++.h>
using namespace std;

int D[2000020];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    D[1000000] = 0;
    D[1000001] = 1;
    

    int n; cin >> n;
    int sign = 0;

    if (n > 0) {
        for (int i = 2; i <= n; i++) {
            D[1000000+i] = D[1000000+i-1] % 1'000'000'000 + D[1000000+i-2] % 1'000'000'000;
            sign = 1;
        }
    }
    
    else if (n < 0) {
        for (int i = -1; i >= n; i--) {
            D[1000000+i] = D[1000000+i+1] % 1'000'000'000 + D[1000000+i+2] % 1'000'000'000;
            if (abs(i) % 2) sign = 1;
            else sign = -1;
        }
    }

    cout << sign << '\n';
    cout << D[1000000+n] % 1'000'000'000;
}
// D[1] = D[0] + D[-1]
// D[-1] = D[1] - D[0]; = 1
// D[0] = D[-1] + D[-2];
// D[-2] = D[0] - D[-1] = -1
// D[-1] = D[-2] + D[-3]
// D[-3] = D[-1] - D[-2] = 2