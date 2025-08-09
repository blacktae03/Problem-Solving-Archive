#include <bits/stdc++.h>
using namespace std;

int nA, nB;
int A[500050], B[500050];
vector<int> ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> nA >> nB;

    for (int i = 0; i < nA; i++) cin >> A[i];
    for (int i = 0; i < nB; i++) cin >> B[i];

    sort(A, A+nA); // 원래 A는 굳이 sort 할 필요 없지만, 문제에서 오름차순으로 출력하라고 했으므로 정렬함.
    sort(B, B+nB);

    for (int i = 0; i < nA; i++) {
        if (binary_search(B, B+nB, A[i])) continue;
        ans.push_back(A[i]);
    }

    cout << ans.size() << '\n';

    for (auto i : ans) cout << i << ' ';
}