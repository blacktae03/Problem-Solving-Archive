#include <bits/stdc++.h>
using namespace std;

int N, K, ans;
int A[200020], cnt[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> A[i];

    int st = 0, en = 0;
    int danger;
    while(en < N) {
        if(cnt[A[en]] < K) {
            cnt[A[en]]++;
            ans = max(ans, ++en-st);
        }
        else {
            danger = A[en];
            while(A[st] != danger) cnt[A[st++]]--;
            cnt[A[st++]]--;
        }
    }

    cout << ans;
}