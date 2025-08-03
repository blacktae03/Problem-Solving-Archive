#include <bits/stdc++.h>
using namespace std;

int N, F;
int rad[104];

int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b); // 4 12 -> 12 4 -> 4 0
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> F;

    for (int i = 1; i < N; i++) {
        int tmp; cin >> tmp;
        int tgcd = GCD(F, tmp);
        cout << F / tgcd << '/' << tmp / tgcd << '\n';
    }
}