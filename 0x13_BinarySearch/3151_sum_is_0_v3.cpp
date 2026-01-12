#include <bits/stdc++.h>
using namespace std;

int N, ans;
int A[10010], B[10010];
vector<int> V;
vector<pair<int, int>> idx;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    
    sort(A, A+N);
    for (int i = 0; i < N; i++) cout << A[i] << ' ';
    cout << '\n';


    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            V.push_back({A[i]+A[j]});
            idx.push_back({i, j});
        }
    } // O(N^2)

    // sort(idx.begin(), )
    sort(V.begin(), V.end());
    cout << V.size() << '\n';
    for (auto n : V) cout << n << ' ';
    cout << '\n';
    

    for (int i = 0; i < N; i++) {
        // O(N)만큼의 무언가를 이용해서 이 문제를 해결할 수 있을 거 같음.
        // vector<int> tmp;
        int find = -1*A[i];
        for (int j = 0; j < N; j++) { // O(N)
            if (j == i) continue;
            // tmp.push_back(A[i] + A[j]);
            if (A[i] + A[j] == find) ans--;
        }

        auto st = lower_bound(V.begin(), V.end(), find) - V.begin();
        auto en = upper_bound(V.begin(), V.end(), find) - V.begin();
        ans += en - st;

        // cout << '(' << ", " << idx[i].second << ')' << ", ans += " << en - st << '\n';
    } // O(Nlg(N^2))

    cout << ans;
}
// O(N^2)까지는 통과 가능할 듯.
// 어떻게 해야 중복되는 걸 피할 수 있을까?
// 36번 줄 반복문에서 i값이 포함된 벡터에서는 찾으면 안됨.