#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long N; cin >> N;

    long long num = 1;

    for (long long i = 1; i <= N; i++) num *= i;

    cout << num;
}