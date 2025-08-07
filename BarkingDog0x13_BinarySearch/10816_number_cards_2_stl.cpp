#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[500010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N);

    cin >> M;

    while(M--) {
        int tmp; cin >> tmp;
        // cout << upper_bound(A, A+N, tmp) - lower_bound(A, A+N, tmp) << ' ';
        auto ans = equal_range(A, A+N, tmp);
        cout << ans.second - ans.first << ' ';
    }
}