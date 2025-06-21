#include <bits/stdc++.h>
using namespace std;

int N;
int D[1002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    D[0] = 1;
    D[1] = 1;

    for (int i = 2; i <= N; i++) {
        D[i] = (D[i-1] + D[i-2] * 2) % 10007;
    }

    cout << D[N];
}
// D[i] = 2*i 직사각형을 채우는 경우의 수