#include <bits/stdc++.h>
using namespace std;

int val = 1;

int func(int a, int b, int c) {
    if (b == 1) return a % c;
    int val = a * a % b;
    if (b % 2 == 0) return func(a, b/2, c);
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    cout << func(a, b, c);
}