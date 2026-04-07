#include <bits/stdc++.h>
using namespace std;

int N, D, K, C, ans, kind = 1;
int T[30003], cnt[3003];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> D >> K >> C;
    cnt[C] = 1;
    for (int i = 0; i < N; i++) cin >> T[i];

    int st = 0, en = 0;
    while(en < K) {
        if (!cnt[T[en]]) kind++;
        cnt[T[en++]]++;
    }
    
    ans = max(ans, kind);
    
    while(st < N) {
        if (cnt[T[st]] == 1) kind--;
        cnt[T[st++]]--;
        if (!cnt[T[en%N]]) kind++;
        cnt[T[en++%N]]++;
        ans = max(ans, kind);
    }

    cout << ans;
}