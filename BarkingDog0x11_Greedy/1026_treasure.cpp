#include <bits/stdc++.h>
using namespace std;

int N, ans;
int A[53], B[53];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    sort(A, A+N);
    sort(B, B+N, [](int a, int b) {
        return a > b;
    });

    for (int i = 0; i < N; i++) ans += A[i] * B[i];

    cout << ans;
}