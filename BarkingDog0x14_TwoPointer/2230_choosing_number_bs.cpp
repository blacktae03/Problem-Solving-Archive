#include <bits/stdc++.h>
using namespace std;

int N, M, ans = INT_MAX;
int A[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N);

    for (int i = 0; i < N; i++) ans = min(ans, *lower_bound(A, A+N, A[i] + M) - A[i] < 0 ? INT_MAX : *lower_bound(A, A+N, A[i] + M) - A[i]);

    cout << ans;
}