#include <bits/stdc++.h>
using namespace std;
// 직접 깨닫고 구현해봄 ㅋ

int N, M, ans = INT_MAX;
int A[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N);

    int st = 0, en = 0;
    while(en < N) {
        if (A[en] - A[st] < M) en++;
        else {
            ans = min(ans, A[en]-A[st]);
            st++;
        }
    }

    cout << ans;
}