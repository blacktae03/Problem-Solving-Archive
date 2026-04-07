#include <bits/stdc++.h>
using namespace std;

void func1 (int n) {
    if (n == 0) return;
    cout << n << " ";
    func1(n-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    func1(5);
}