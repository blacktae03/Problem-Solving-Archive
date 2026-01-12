#include <bits/stdc++.h>
using namespace std;

int N, ans;
int S[109];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = N-1; i >= 0; i--) cin >> S[i]; // 반대로 배치해서 갈수록 작아져야함.

    for (int i = 1; i < N; i++) {
        if (S[i] < S[i-1]) continue;
        ans += S[i] - S[i-1] + 1;
        S[i] -= S[i] - S[i-1] + 1; 
    }

    cout << ans;
}