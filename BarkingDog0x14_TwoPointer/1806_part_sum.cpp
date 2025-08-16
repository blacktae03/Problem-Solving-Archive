#include <bits/stdc++.h>
using namespace std;

int N, S, ans = INT_MAX;
int A[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> A[i];
    // sort(A, A+N);

    int st = 0, en = 0;
    int sum = 0;

    while (en < N || sum >= S) {
        if (sum >= S) {
            ans = min(ans, en-st);
            sum -= A[st++];
        }
        else sum += A[en++];
    }
    // if (sum >= S) ans = min(ans, en-st);
    if (ans == INT_MAX) cout << 0;
    else cout << ans;
}