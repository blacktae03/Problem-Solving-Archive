#include <bits/stdc++.h>
using namespace std;

int N, K, ocnt, ans = 0;
int S[1000010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> S[i];

    int st = 0, en = 0;

    while (en < N || ocnt > K) {
        if (ocnt > K) {
            if (S[st++] % 2) ocnt--;
        }

        else {
            if (S[en++] % 2) ocnt++;
            ans = max(ans, en-st-ocnt);
        }
    }

    cout << ans;
}