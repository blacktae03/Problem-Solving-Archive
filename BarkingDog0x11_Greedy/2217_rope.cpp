#include <bits/stdc++.h>
using namespace std;

int N, ans;
int R[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) cin >> R[i];
    
    sort(R, R+N);

    for (int i = 0; i < N; i++) ans = max(ans, R[i] * (N-i));

    cout << ans;
}