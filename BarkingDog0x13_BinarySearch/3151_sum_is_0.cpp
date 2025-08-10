#include <bits/stdc++.h>
using namespace std;

int N, ans;
int A[10010], B[10010];
vector<pair<int, pair<int, int>>> V;

// bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
//     return a.first < b.first;
// }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A, A+N);

    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            V.push_back({A[i]+A[j], {i, j}});
        }
    } // O(N^2)

    sort(V.begin(), V.end());

    for (int i = 0; i < N; i++) {
        auto st = lower_bound(V.begin(), V.end(), -1*A[i]) - V.begin();
        auto en = upper_bound(V.begin(), V.end(), -1*A[i]) - V.begin();
        ans += en - st;
        
        
        // cout << '(' << ", " << idx[i].second << ')' << ", ans += " << en - st << '\n';
    } // O(Nlg(N^2))

    cout << ans;
}
// O(N^2)까지는 통과 가능할 듯.
