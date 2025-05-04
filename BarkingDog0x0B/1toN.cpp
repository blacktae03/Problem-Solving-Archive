#include <bits/stdc++.h>
using namespace std;

int sum = 0;

int func1 (int n) {
    if(n == 0) return 0;
    return n+func1(n-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << func1(5);
}