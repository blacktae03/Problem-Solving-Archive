#include <bits/stdc++.h>
using namespace std;

long long val = 1;
long long a, b, c;

long long func(long long a, long long b, long long c) {
    if (b == 0) return 1;
    
    long long val = func(a, b/2, c);
    val = val * val % c;
    if (b % 2 == 1) val = val * a % c;
    return val % c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;

    cout << func(a, b, c);
}
// ex) b = 25(10) == 11001(2)이라고 할 때
// a 곱하고(1) 나 자신 곱하고(2) a 곱하고(3) 나 자신 곱하고(6) 나 자신 곱하고(12) 나 자신 곱하고(24) a 곱하면(25) 되잖아
// 14 == 10110(2)